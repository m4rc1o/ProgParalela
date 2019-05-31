#include "mpi.h" 
#include <stdio.h>
int main(int argc, char **argv){      
	int my_rank, size, tag1=0, tag2=1;  
	MPI_Status status;    
	float x=10, y=2, c=1; 
	
	MPI_Init(&argc,&argv); 
	MPI_Comm_size(MPI_COMM_WORLD,&size); 
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank); 
	
	printf("My rank: %d\n",my_rank); 
	
	if (my_rank == 0){ 
		MPI_Send(&y, 1, MPI_FLOAT, 1, tag2, MPI_COMM_WORLD); 
		MPI_Recv(&x, 1, MPI_FLOAT, 1, tag1, MPI_COMM_WORLD, &status); 
		c += x+y; 
	}else{ 
		if (my_rank==1){ 
			MPI_Recv(&x, 1, MPI_FLOAT, 0, tag2, MPI_COMM_WORLD, &status); 
			MPI_Send(&x, 1, MPI_FLOAT, 0, tag1, MPI_COMM_WORLD); 
			c += x+y; 
		} 
	}    
	printf("Rank=%d; c=%.2f \n", my_rank, c);    
	MPI_Finalize(); 
	return 0; 
} 
