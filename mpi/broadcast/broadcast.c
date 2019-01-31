#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
 
int main(int argc, char *argv[]){
    int i,myid,numprocs,root,count;
    int buffer[4];
 
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    root=0; count=4;
    if(myid == root){
      for(i=0;i<count;i++)
        buffer[i]=i;
    }
    MPI_Bcast(buffer,count,MPI_INT,root,MPI_COMM_WORLD);
    for(i=0;i<count;i++){printf("%d ",buffer[i]);}
    printf("\n");
    MPI_Finalize();
}

