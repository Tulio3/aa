#include <stdio.h>
#include <stdlib.h>

float absol(float a){
	if(a>=0) return a;
	else return -a;
}

int main(){
	
	// eps es el épsilon
	float S, xi, xii, eps = 0.00001;
	// n es la variable que nos evitará caer en un bucle infinito
	// si no encontramos una solución satisfactoria en 1000 iteraciones. 
	int n=0;
	
	printf("Ingresa un numero no negativo: "); scanf("%f", &S);
	
	xii = S;
	
	while(n < 1000 && absol(xii*xii - S) > eps){
		
		// xi toma el lugar de x_n y xii el de x_{n+1}
		xi = xii;
		xii = (xi + S/xi)/2;
		
		n++;
	}
	
	printf("La raiz es: %f", xii);
	
	return 0;
}
