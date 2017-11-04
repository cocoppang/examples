#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    //Initialize the MPI environment
    MPI_Init(NULL, NULL);

    //Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    //Get the rank of the processes
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int token;

    if(world_rank == 0)
    {	
	//set by rank 0
	token = 222;
	MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);
	MPI_Recv(&token, 1, MPI_INT, (world_size - 1), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	printf("Process %d received token %d from process %d\n", world_rank, token, world_size-1);
    }
    else
    {
	MPI_Recv(&token, 1, MPI_INT, (world_rank - 1), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);
	printf("Process %d received token %d from process %d\n", world_rank, token, world_rank-1);
    }

    MPI_Finalize();

}
