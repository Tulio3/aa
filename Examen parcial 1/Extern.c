#include <stdio.h>

int numero;

void abre();

main(){
	
	int clave;
	
	printf("Da la clave: "); scanf("%d", &clave);
	
	extern int numero;
	
	if(clave == 3547) numero = 1;
	
	// Permite llamar a "abre" sin parámetros.
	// Permite que varias personas puedan abrir la puerta
	// desde diferentes consolas.
	abre();
	
	return 0;
}

void abre(){
	
	if(numero==1) printf("Se abre la puerta");

}
