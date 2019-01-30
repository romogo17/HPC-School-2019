#include <stdio.h>
#include <mpi.h>

int main (int argc, char *argv[]) {
  int pid, size;
  MPI_Init (&argc, &argv);	/* iniciar MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &pid); /* obtener id del proceso */
  MPI_Comm_size (MPI_COMM_WORLD, &size); /* obtener número de procesos */

  if(pid == 0){
    /* este proceso recibe e imprime el mensaje de todos los procesos */
    int i, buff;
    MPI_Status *state;
    
    /* imprime el mensaje del proceso maestro */
    printf("Hello world from MASTER process %d of %d\n", pid, size);

    /* imprime los mensajes recibiendolos en orden de los otros procesos*/
    for(i = 1; i < size; i++){
      MPI_Recv(&buff, 1, MPI_INT, i, 123, MPI_COMM_WORLD, state);
      printf("Hello world from process %d of %d\n", buff, size );
    }
  } else {
    /* este proceso envia el pid al proceso maestro */
    MPI_Send(&pid, 1, MPI_INT, 0, 123, MPI_COMM_WORLD);
  }

  MPI_Finalize();
  return 0;
}
