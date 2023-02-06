#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int arr[2], i;
	unsigned char* pt;
	
	printf("Dame el primer entero: "); scanf("%u", &arr[0]);
	printf("Dame el segundo entero: "); scanf("%u", &arr[1]);
	
	// Imprimimos los bits de menos significativo a más significativo,
	// que es el orden en el que se almacena en esta computadora
	representar(arr[0]); representar(arr[1]);
	
	// Estos puntos nos muestran los principios de los bytes
	printf("\n.       .       .       .       .       .       .       .\n");
	
	pt = (unsigned char*) arr;
	
	for(i=0; i<8; i++, pt++) printf("\nEstamos es la posicion %p. En la posicion hay un %u.", pt, *pt);
	
	return 0;
}
