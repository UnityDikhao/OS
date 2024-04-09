#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc, char *argv[]) 
{
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int elements_per_process = 1000 / size;
    srand(rank);

    int local_numbers[elements_per_process];
    for (int i = 0; i < elements_per_process; i++) 
    {
        local_numbers[i] = rand();
    }

    int local_sum = 0;
    for (int i = 0; i < elements_per_process; i++) 
    {
        local_sum += local_numbers[i];
    }
    int all_sums[size];
    MPI_Gather(&local_sum, 1, MPI_INT, all_sums, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int total_sum = 0;
    if (rank == 0) 
    {
        for (int i = 0; i < size; i++) 
        {
            total_sum += all_sums[i];
        }
    }
    double global_average;
    if (rank == 0) 
    {
        global_average = (double)total_sum / 1000;
    }
    if (rank == 0) 
    {
        printf("Total Sum: %d\n", total_sum);
        printf("Global Average: %.2f\n", global_average);
    }
    MPI_Finalize();
    return 0;
}