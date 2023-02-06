#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i, n1=7, n2= 6;
	float arr[n1];
	float q;
	float vec[n2];
	float var;
	
	printf("Prueba del inciso a)\n");
	for(i=0; i< n1; i++){
		arr[i] = (float)rand()/(float)(RAND_MAX);
	}
	
	// Imprime vector original
	for(i=0; i<n1;i++) printf("%f  ", arr[i]);
	
	// Función
	fun(arr,n1);
	
	printf("\n\n");
	
	// Imprime vector modificado
	for(i=0; i<n1;i++) printf("%f  ", arr[i]);
	
	printf("\n\nPrueba del inciso d)\n");
	
	q = promedio();
	printf("El promedio es %f\n\n", q);
	
	var = varianza();
	printf("\nLa varianza es %f", var);
	
	return 0;
}
