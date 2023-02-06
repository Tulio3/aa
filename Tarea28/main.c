#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int aux = 0; 
	int* numero = &aux; // *numero guardará la dimensión del vector de impares
	int* vec; // El vector de impares
	int nf = 7, nc = 7; // Dimensiones de la matriz "identidad"
	
	vec = leeImpares2Enteros("file_numbers_0_100.txt",numero);
	
	copia("Nuevo_archivo.bin",*numero,vec);

	float** Iden;
	
	identidad(&Iden,nf,nc);
	
	printMatScreen(Iden,nf,nc);

	freeMat(Iden,nf);
	free(vec);
	
	return 0;
}
