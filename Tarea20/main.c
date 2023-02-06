#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float f;
	unsigned int* pt;
	
	printf("Dame un float: "); scanf("%f", &f);
	
	pt = (unsigned int*) &f;
	
	// Se manda como parámetro el contenido del apuntador como unsigned int,
	// que van a ser los bits del float original
	printf("Su trama de bits es: "); representar(*pt);
	
	return 0;
}
