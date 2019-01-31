#include "mpi.h"
#include <stdio.h>
#define NPROCS 8
#define MASTER 0
#define MSGSIZE 7

int main(int argc, char *argv[]) {
   int rank, new_rank;
   int ranks1[4] = {0,1,2,3};
   int ranks2[4] = {4,5,6,7};
   char *msg;
   MPI_Group orig_group, new_group;
   MPI_Comm new_comm;
   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   /* Extraer la referencia del grupo original */
   MPI_Comm_group(MPI_COMM_WORLD, &orig_group);  
/* Dividir las tareas en dos grupos. Crear un nuevo grupo y un nuevo comunicador. Luego, hallar el nuevo rango en el nuevo comunicador y prepar el proceso maestro para la comunicación colectiva */
   if (rank < NPROCS/2) {
      MPI_Group_incl(orig_group, NPROCS/2, ranks1, &new_group);
      MPI_Comm_create(MPI_COMM_WORLD, new_group, &new_comm);
      MPI_Group_rank (new_group, &new_rank);
      if (new_rank == MASTER) msg="Group 1";
   } else {
      MPI_Group_incl(orig_group, NPROCS/2, ranks2, &new_group);
      MPI_Comm_create(MPI_COMM_WORLD, new_group, &new_comm);
      MPI_Group_rank (new_group, &new_rank);
      if (new_rank == MASTER) msg="Group 2";
   }
   MPI_Bcast(&msg,MSGSIZE,MPI_CHAR,MASTER,new_comm);
   printf("rank= %d newrank= %d msg= %s\n",rank,new_rank,msg);
   MPI_Finalize();
}

