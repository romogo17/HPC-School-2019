#include <mpi.h>
#include <stdio.h>
#include <math.h>

#define true 1
#define false 0
#define root 0

int is_prime(const int* n){
	if (*n < 2) return false;
	if (*n==2 || *n==3) return true;

	if (*n % 2 == 0 || *n % 3 == 0) return false;

	int top = sqrt(*n) + 1;
	/* in C++, If one thread writes to an atomic object while another thread reads from it, 
	 * the behavior is well-defined. This would be useful if using OpenMP on the foor loop 
	 *
	 * std::atomic<bool> is prime = true
	 * #pragma omp parallel for */
	int is_prime = true, i;
	for (i = 3;  i < top;  i += 6) {
		if (!is_prime) continue;
		if ((*n) % (i+2) == 0) is_prime = false;
		if ((*n) % (i+4) == 0) is_prime = false;
	}
	return is_prime;
}

int main (int argc, char **argv) { 
	int pid, size, global_sum = 0, local_sum, n;

	/* read the upper limit n as a parameter */
	if(argc == 1) { printf("Wrong arguments. Usage: prime <prime_number>\n\n"); return 1; }
	n = atoi(argv[1]); 

	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &pid); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
    double start = MPI_Wtime();

	/*
	 * Ya que la complejidad de determinar si un numero n es primo es de a lo sumo sqrt(n) + 1
	 * se traslada el problema a una escala exponencial, para que al aplicar la raiz cuadrada
	 * para determinar los intervalos, estos estén escalados de 0 a n, con mas elementos por
	 * intervalo entre menor sean los numeros, como se muestra en el siguiente ejemplo
	 *     
	 *     n = 1000, size = 5
	 *     h = 1000^2 / 5 = 200000

	 *     pid 0 =>  sqrt(0*200000)   = 0       => [  0, 447[  => 447 elementos
	 *     pid 1 =>  sqrt(1*200000)   = 447.21  => [447, 632[  => 185 elementos
	 *     pid 2 =>  sqrt(2*200000)   = 623.45  => [632, 774[  => 142 elementos
	 *     pid 3 =>  sqrt(3*200000)   = 774.59  => [774, 894[  => 120 elementos
	 *     pid 4 =>  sqrt(4*200000)   = 894.42  => [894,1000[  => 106 elementos
	 *     pid 5 =>  sqrt(5*200000)   = 1000                   ----------------
	 *                                                           1000 elementos
	 */

    int i; local_sum = 0;
    int h = n * n / size;
    for(i = (int) sqrt(pid * h); i < (int) sqrt((pid + 1) * h); i++)
        if(is_prime(&i) == true){
            // printf("%d\n", i);
            local_sum++;
        }
    printf("pid %d, [%d, %d[, local_sum = %d\n", pid, (int) sqrt(pid * h), (int) sqrt((pid + 1) * h), local_sum);

    /* reduce the local prime counts */
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, root, MPI_COMM_WORLD);

    double end = MPI_Wtime();
    if (pid == root) {
      printf("Total prime count from %d processes: %d\n", size, global_sum);
      printf("The process took %0.5f secconds to run.\n\n", end - start);
    }
    
	MPI_Finalize(); 
	return 0; 
}
