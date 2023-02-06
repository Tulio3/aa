/* Programa que muestra el uso del modificador const con apuntadores,
   y el recorrido de cadenas por medio de apuntadores.
   @autor Ricardo Ruiz Rodríguez
*/
#include <stdio.h>
#define ESPACIO_EN_BLANCO ' '

void imprimeSinEspacios(const char *);
void imprimeAlReves(const char *);

int main(){
	char cadena[] = "Dabale arroz a la zorra el abad";
	
	printf("Cadena original: %s\n", cadena);
	imprimeAlReves(cadena); /* cPtr = &cadena[0] */
	imprimeSinEspacios(cadena); /* cPtr = cadena */
	printf("Cadena original: %s\n", cadena);
	
	return 0;
}

void imprimeSinEspacios(const char *cPtr){
	while(*cPtr != '\0'){ /* Mientras no hagas referencia a fin de cadena */
		if(*cPtr != ESPACIO_EN_BLANCO) 
			putchar(*cPtr);
		cPtr++; /* Avanza a la siguiente posición de la cadena*/
	} 
	
	
	
	
	
}











void imprimeAlReves(const char *cPtr);
