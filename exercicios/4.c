#include "mpi.h" 
#include <stdio.h>
int main(int argc, char **argv){      
	int x, y, z, my_rank, subtotal=0, total=0; 
	MPI_Status status; 
	x=10; 
	MPI_Init(&argc,&argv);  
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
	
	switch (my_rank){ 
		case 0: subtotal = x + 10;  
		break; 
		case 1: subtotal = x*x;     break; 
		case 2: subtotal = x*x*x;  break; 
		case 3: subtotal = x;  
		break; 
		default: subtotal = 0;  
		break; 
	} 
	
	MPI_Reduce(&subtotal, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);    
	if (my_rank==0) printf("Total=%d\n", total); 
	MPI_Finalize(); 
	
	return 0; 
} 
