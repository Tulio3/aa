#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	unsigned int num;
	
	printf("Dame un numero: "); scanf("%d", &num);
	printf("El numero tiene %d unos.", ejercicio1(num));
	
	printf("\n\nDame otro numero: "); scanf("%d", &num);
	printf("El numero con unos invertidos es %u.", ejercicio2(num)); 
	
	printf("\n\nDame otro numero: "); scanf("%d", &num);
	printf("La posicion del primer 1 es %d", posicion(num)); 
	
	printf("\n\nDame otro numero: "); scanf("%d", &num);
	printf("El numero que conserva solo el primer 1 es %d", cadena(num));
	
	return 0;
}
