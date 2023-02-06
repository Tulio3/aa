#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i;
	
	int* vec = (int*) malloc(4*sizeof(int));
	int** v = &vec; 
	
	int r = reasignaVector(v, 12);
	
	printf("La funcion regreso %d", r);
	
	free(vec);
	
	// Adicional
	
	int n=6, m=4;
	
	// Crea matriz
	int **matr = (int**) malloc(n*sizeof(int*));
	for(i=0; i<n; i++) matr[i] = (int*) malloc(m*sizeof(int));
		
	int*** mat = &matr;
	
	r = reasignaMatriz(mat, n, 33, 20);
	
	printf("\n\nLa otra funcion regreso %d", r);
	
	free(matr);
	
	return 0;
}
