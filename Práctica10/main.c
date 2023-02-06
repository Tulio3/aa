#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
	
	// Primer problema
	solve();
	
	// Segundo problema
	srand(time(NULL));
	
	Complex** matrix = create();
	
	if(!matrix){
		printf("No se pudo crear la matriz");
		return 0;
	}
	
	// Necesitamos las dimensiones para poder usar la función save
	int n,m;
	
	FILE* dimension = fopen("dimensiones.txt", "r");
	
	if(!dimension){
		printf("No se pudo abrir dimensiones.txt");
		return 0;
	}
	
	fscanf(dimension,"%d", &n);
	fscanf(dimension,"%d", &m);
	
	fclose(dimension);
	
	save(matrix,n,m);
	
	freeMatrix(matrix,n);
	
	return 0;
}


