/* Programa que muestra la declaración de un apuntador a entero,
   el uso del operador de direccion (&) y de desreferencia (*).
   @autor Ricardo Ruiz Rodríguez
*/
#include <stdio.h>

int main(){
	
	// Declaramos b que usaremos mas tarde
	int a, b = 9;
	int *aPtr, *bPtr;
	
	a = 40178;
	aPtr = &a; /* aPtr apunta a la variable a */
	bPtr = &a; /* bPtr apunta a la variable a */
	
	printf("Direccion de a: %p\n", &a);
	printf("Valor de aPtr: %p\n", aPtr);
	
	printf("\nValor de a: %d\n", a);
	printf("Valor de *aPtr (desreferenciada): %d\n", *aPtr);
	
	*bPtr = 2018;
	printf("Valor de a: %d\n", a);
	
	printf("\nValor de bPtr: %p\n", bPtr);
	
	*aPtr = 5050;
	bPtr = &b;
	*bPtr = 10;
	
	aPtr = 11;
	
	/* Funciona asignar un valor explícito al apuntador,
	   sin embargo, este se pasa a hexadecimal, y desconocemos lo que hay ahí */
	
	printf("\n %p", aPtr);
	
	return 0;
}
