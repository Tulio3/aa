#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	unsigned int n;
	
	// Prueba inciso b
	printf("Dame un numero: "); scanf("%u", &n);
	printf("La expresion binaria es: "); representar(n);
	
	float Tmin[12] = {-8.3, -5.7, -0.3, 6.1, 11.2, 16.5, 18.9, 17.6, 12.7, 6.4, 0.4, -5.6};
	float Tmax[12] = {2.3, 5.5, 11.6, 18.7, 23.9, 28.8, 31.6, 30.7, 26.4, 20.2, 12, 4.6};
	int al = intAleatorio(0,11);
	
	// Prueba inciso d
	printf("\n\nEl resultado de la prueba del inciso d es: %f", floatAleatorio(Tmin[al], Tmax[al]));
	
	return 0;
}
