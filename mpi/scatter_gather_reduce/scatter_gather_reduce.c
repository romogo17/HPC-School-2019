#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int numnodes,myid,mpi_err; /* variables globales */
#define root 0

int main(int argc,char *argv[]){
   int *myray,*send_ray,*back_ray; 
   int count,size,mysize,i,k,j,total,gtotal;
	
   MPI_Init(&argc,&argv);
   MPI_Comm_size( MPI_COMM_WORLD, &numnodes );
   MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	count=4; /* cada proceso recibe count elementos del root */

	myray=(int*)malloc(count*sizeof(int));
	if(myid == root){ 
      /* crear los datos a ser enviados por el root */
      size=count*numnodes;
      send_ray=(int*)malloc(size*sizeof(int));
      back_ray=(int*)malloc(numnodes*sizeof(int));
	   for(i=0;i<size;i++)
		send_ray[i]=i;
	}
/* enviar los datos a cada proceso */
	mpi_err=MPI_Scatter(send_ray,count,MPI_INT,myray,count,MPI_INT,root,MPI_COMM_WORLD);
	                
/* cada proceso realiza una suma local */
	total=0;
	for(i=0;i<count;i++)
	    total=total+myray[i];
	printf("myid= %d total= %d\n ",myid,total);

	/* enviar las sumas locales al proceso root y reducir */ 
	mpi_err = MPI_Reduce(&total,&gtotal,1,MPI_INT,MPI_SUM,root,MPI_COMM_WORLD); 
	/* el root imprime la suma global */
	if(myid == root){ 
	   printf("results from all processors= %d \n ",gtotal); 
	}

	MPI_Finalize();
}

