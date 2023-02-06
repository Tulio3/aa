#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int reasignaVector(int** vector, int N){
	
	int i;
	int* aux;
	
	aux = (int*) malloc(N*sizeof(int));
	
	if(aux){
		
		free(*vector);
		*vector = aux;	
		return 1;
		
	} 
	else return -1;
}

int reasignaMatriz(int*** matriz, int num, int N, int M){
	
	// El indicador será 0 si algún vector de memoria no se puede crear
	int i, ind = 1;
	
	int** aux = (int**) malloc(N*sizeof(int*));
	
	if(aux == NULL) ind = 0; 
	else{
		
		for(i=0; i<N; i++) aux[i] = (int*) malloc(M*sizeof(int));
		if(aux[i] == NULL) ind = 0;	
		
	}
	
	if(ind){
		
		free(*matriz);
		*matriz = aux;
		return 1;
		
	}
	else return -1;
}
