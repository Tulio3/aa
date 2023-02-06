/* Programa que muestra la diferencia entre un par�metro
   por valor y uno por referencia (apuntador).
   @autor Ricardo Ruiz Rodr�guez
*/
#include <stdio.h>

void llamadaValor(int);
void llamadaReferencia(*int);

int main(){
	int argumento = 10;
	
	// Esto es para ver como est� el valor antes de entrar a las funciones
	printf("Valor de argumento (main()): %d\n", argumento);
	
	// Pasamos el argumento y se evidenc�a el cambio de nombre para entrar en la funci�n
	llamadaValor(argumento); /* parametro = argumento */
	printf("\nValor de argumento (main()): %d\n", argumento);
	
	// Ahora lo pasamos a otra funci�n que tiene el par�metro como apuntador, por eso el &
	llamadaReferencia(&argumento); /* parametro = &argumento */
	printf("\nValor de argumento (main()): %d\n", argumento);

	return 0;
}

void llamadaValor(int parametro){
	
	// Aqu� le imprimimos al usuario lo que coloc� en la llamada de la funci�n
	printf("\nValor de argumento (llamadaValor()): %d\n", parametro);
	parametro *= 2;
	
	// Lo modificamos e imprimimos lo modificado
	printf("Valor de argumento (llamadaValor()): %d\n", parametro);
}

void llamadaReferencia(int* parametro){
	// Aqu� le imprimimos al usuario lo que coloc� en la llamada de la funci�n, tenemos que usar * porque se pas� un apuntador
	printf("\nValor de argumento (llamadaReferencia()): %d\n", *parametro);
	*parametro *= 2; /* *parametro = *parametro*2; */
	
	// Lo modificamos e imprimimos lo modificado, utilizando el * porque parametro sigue siendo un apuntador
	printf("Valor de argumento (llamadaReferencia()): %d\n", *parametro);
	
}
