/* Programa que muestra la diferencia entre un parámetro
   por valor y uno por referencia (apuntador).
   @autor Ricardo Ruiz Rodríguez
*/
#include <stdio.h>

void llamadaValor(int);
void llamadaReferencia(*int);

int main(){
	int argumento = 10;
	
	// Esto es para ver como está el valor antes de entrar a las funciones
	printf("Valor de argumento (main()): %d\n", argumento);
	
	// Pasamos el argumento y se evidencía el cambio de nombre para entrar en la función
	llamadaValor(argumento); /* parametro = argumento */
	printf("\nValor de argumento (main()): %d\n", argumento);
	
	// Ahora lo pasamos a otra función que tiene el parámetro como apuntador, por eso el &
	llamadaReferencia(&argumento); /* parametro = &argumento */
	printf("\nValor de argumento (main()): %d\n", argumento);

	return 0;
}

void llamadaValor(int parametro){
	
	// Aquí le imprimimos al usuario lo que colocó en la llamada de la función
	printf("\nValor de argumento (llamadaValor()): %d\n", parametro);
	parametro *= 2;
	
	// Lo modificamos e imprimimos lo modificado
	printf("Valor de argumento (llamadaValor()): %d\n", parametro);
}

void llamadaReferencia(int* parametro){
	// Aquí le imprimimos al usuario lo que colocó en la llamada de la función, tenemos que usar * porque se pasó un apuntador
	printf("\nValor de argumento (llamadaReferencia()): %d\n", *parametro);
	*parametro *= 2; /* *parametro = *parametro*2; */
	
	// Lo modificamos e imprimimos lo modificado, utilizando el * porque parametro sigue siendo un apuntador
	printf("Valor de argumento (llamadaReferencia()): %d\n", *parametro);
	
}
