#include<stdio.h>
#include "funciones.h"

int main(){
	
	double p1 = 0,p2 = 0;
	
	cuadratica(3,5,4.5, &p1, &p2);
	
	printf("%f", &p1); 
	
	
	return 0;
}
