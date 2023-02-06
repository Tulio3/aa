#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int i, n1, n2, n3, n4, n5, n6;
	
	// Pedimos los tamaños de los vectores y los creamos,
	// luego los llenamos con valores aleatorios
	
	printf("Ingresa el tamanio del vector char: "); scanf("%d", &n1);
	char* orC = (char*) malloc(n1*sizeof(char));
	for(i=0; i<n1; i++) orC[i] = (char) intAleatorio(0,255);
	
	printf("Ingresa el tamanio del vector int: "); scanf("%d", &n2);
	int* orI = (int*) malloc(n2*sizeof(int));
	for(i=0; i<n2; i++) orI[i] = intAleatorio(0, RAND_MAX);
	
	printf("Ingresa el tamanio del vector unsigned int: "); scanf("%d", &n3);
	unsigned int* orUI = (unsigned int*) malloc(n3*4);
	for(i=0; i<n3; i++) orUI[i] = (unsigned int) intAleatorio(0,RAND_MAX);
	
	printf("Ingresa el tamanio del vector float: "); scanf("%d", &n4);
	float* orF = (float*) malloc(n4*sizeof(float));
	for(i=0; i<n4; i++) orF[i] = floatAleatorio(0, 1);
	
	printf("Ingresa el tamanio del vector double: "); scanf("%d", &n5);
	double* orD = (double*) malloc(n5*sizeof(double));
	for(i=0; i<n5; i++) orD[i] = floatAleatorio(0, 1);
	
	printf("Ingresa el tamanio del vector long double: "); scanf("%d", &n6);
	long double* orLD = (long double*) malloc(n6*sizeof(long double));
	for(i=0; i<n6; i++) orLD[i] = (long double) floatAleatorio(0, 1);
	
	// Creamos los apuntadores auxiliares
	
	char* aC = orC;
	int* aI = orI;
	unsigned int* aUI = orUI;
	float* aF = orF;
	double* aD = orD;
	long double* aLD = orLD;
	
	// Imprimimos los vectores
	
	printf("\nVector char: ");
	for(i=0; i<n1; i++) printf("%c ", orC[i]); printf("\n");
	printf("Vector int: ");
	for(i=0; i<n2; i++) printf("%d ", orI[i]); printf("\n");
	printf("Vector unsigned int: ");
	for(i=0; i<n3; i++) printf("%u ", orUI[i]); printf("\n");
	printf("Vector float: ");
	for(i=0; i<n4; i++) printf("%f ", orF[i]); printf("\n");
	printf("Vector double: ");
	for(i=0; i<n5; i++) printf("%lf ", orD[i]); printf("\n");
	printf("Vector long double: ");
	for(i=0; i<n6; i++) printf("%lf ", (double) orLD[i]); printf("\n");
	
	// Aquí llamamos a las funciones en donde modificamos los apuntadores auxiliares
	// y modificamos un valor de cada vector
	
	printf("\nVector char. Direccion de apuntador: %x\n\n", aC);
	aC = fun1(aC, orC, n1);
	printf("Cual es el nuevo valor? "); scanf("%c", aC);
	
	printf("\nVector int. Direccion de apuntador: %x\n\n", aI);
	aI = fun2(aI, orI, n2);
	printf("Cual es el nuevo valor? "); scanf("%d", aI);
	
	printf("\nVector unsigned int. Direccion de apuntador: %x\n\n", aUI);
	aUI = fun3(aUI, orUI, n3);
	printf("Cual es el nuevo valor? "); scanf("%u", aUI);
	
	printf("\nVector float. Direccion de apuntador: %x\n\n", aF);
	aF = fun4(aF, orF, n4);
	printf("Cual es el nuevo valor? "); scanf("%f", aF);
	
	printf("\nVector double. Direccion de apuntador: %x\n\n", aD);
	aD = fun5(aD, orD, n5);
	printf("Cual es el nuevo valor? "); scanf("%lf", aD); 
	
	printf("\nVector long double. Direccion de apuntador: %x\n\n", aLD);
	aLD = fun6(aLD, orLD, n6);
	printf("Cual es el nuevo valor? "); scanf("%Lf", aLD);
	
	// Imprimimos los vectores ya modificados
	
	printf("\nVector char: ");
	for(i=0; i<n1; i++) printf("%c ", orC[i]); printf("\n");
	printf("Vector int: ");
	for(i=0; i<n2; i++) printf("%d ", orI[i]); printf("\n");
	printf("Vector unsigned int: ");
	for(i=0; i<n3; i++) printf("%u ", orUI[i]); printf("\n");
	printf("Vector float: ");
	for(i=0; i<n4; i++) printf("%f ", orF[i]); printf("\n");
	printf("Vector double: ");
	for(i=0; i<n5; i++) printf("%lf ", orD[i]); printf("\n");
	printf("Vector long double: ");
	for(i=0; i<n6; i++) printf("%lf ", (double) orLD[i]); printf("\n");
	
	// Liberamos memoria
	
	free(orC);
	free(orI);
	free(orUI);
	free(orF);
	free(orD);
	free(orLD);
	
	getch();
	
	return 0;
}
