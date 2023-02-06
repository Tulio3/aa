#include<stdlib.h>
#include<stdio.h>
#include "funciones.h"

int ejercicio1(int N){
	
	// Esto es un caso particular del ejercicio 3
	return ejercicio3(0,N);
}

float ejercicio2(){
	return (float) rand() / RAND_MAX;
}

int ejercicio3(int a,int b){
	int n;
	n= ejercicio2()*(b-a)  +  a;
	
	return n;
}

float ejercicio4(int a, int b){
	float f;
	// Lo mismo que el anterior pero cambiando el tipo solamente
	f= ejercicio2()*(b-a)  +  a;
	
	return f;
}

float ejercicio5(int a, int b, int c, int d){
	
	// Usamos el ejercicio 4 para encontrar el primer aleatorio y luego lo escalamos
	float f, x = ejercicio4(a,b);
	f= (x-a)*(d-c)/(b-a)  +  c;
	
	return f;
}
