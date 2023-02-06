#include<stdio.h>
#include "funciones.h"

int indice(float* ap, int n){
	
	int i,r=0;
	
	// r almacena el índice
	for(i=0;i<n;i++){
		if(ap[i] > ap[r]) r=i;
	}
	
	return r;
}

void fun(float* pt, int n){
	
	float aux;
	int ind;
	
	ind = indice(pt, n);
	aux = pt[0];
	pt[0] = pt[ind];
	pt[ind] = aux;
	
}

float promedio(){
	
	float n=0, suma =0,prom;
	int cont =-1;
	
	do{
		
		suma += n;
		printf("Ingresa un numero: "); scanf("%f", &n);
		cont++;
		
	}while(n >=0);
	
	// cont guarda cuántos números se ingresaron
	// cont >= 1 evita división entre 0
	if(cont >= 1) prom = suma/ (float) cont;
	
	return prom;
}

float varianza(){
	
	// Se usa la fórmula de varianza igual a la suma de los cuadrados de los datos sobre n
	// menos la media al cuadrado
	
	float n=0, suma =0,prom, cuadrados = 0, aux;
	int cont =-1;
	
	do{
		
		suma += n;
		cuadrados += n*n;
		printf("Ingresa un numero: "); scanf("%f", &n);
		cont++;
		
	}while(n >=0);

	aux = cuadrados / cont;
	prom = suma / cont;
	
	return aux - prom*prom;
}
