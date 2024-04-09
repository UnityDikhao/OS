#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc,char *argv[])
{
  MPI_Init(&argc,&argv);
  int rank,size;
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  
  int *randomNumbers=(int*)malloc(1000*sizeof(int));
  for(int i=0; i<100; i++)
  {
    randomNumbers[i]=rand()%1000;
  }
  int localMax=randomNumbers[0];
  
  for(int i=1; i<100; i++)
  {
    if(randomNumbers[i] > localMax)
    {
      localMax=randomNumbers[i];
    }
  }
  int globalMax;
  MPI_Reduce(&localMax,&globalMax,1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);
  if(rank==0)
  {
    printf("Maximum number:%d\n",globalMax);
  }  
  free(randomNumbers);
  MPI_Finalize();
  return 0;
}        