#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	printf("Prueba: ejercicio 1\n");
	
	int N;
	printf("Dame N: "); scanf("%d", &N);
	printf("El numero es %d\n\n", ejercicio1(N));
	
	printf("Prueba: ejercicio 2\n");
	
	printf("El numero es %f\n\n", ejercicio2());
	
	printf("Prueba: ejercicio 3\n");
	
	int a,b;
	printf("Dame a: "); scanf("%d", &a);
	printf("Dame b: "); scanf("%d", &b);
	printf("El numero es %d\n\n", ejercicio3(a,b));
	
	
	printf("Prueba: ejercicio 4\n");
	
	int a2,b2;
	printf("Dame a: "); scanf("%d", &a2);
	printf("Dame b: "); scanf("%d", &b2);
	printf("El numero es %f\n\n", ejercicio4(a2,b2));
	
	printf("Prueba: ejercicio 5\n");
	
	int a3,b3,c,d;
	printf("Dame a: "); scanf("%d", &a3);
	printf("Dame b: "); scanf("%d", &b3);
	printf("Dame c: "); scanf("%d", &c);
	printf("Dame d: "); scanf("%d", &d);
	printf("El numero es %f\n\n", ejercicio5(a3,b3,c,d));
	
	system("pause");
	
	return 0;
}
