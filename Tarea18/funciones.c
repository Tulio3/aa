#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void representar(unsigned int num){
	
	int i;
	int str1[32];
	
	// Se guarda en el string los lugares que tienen un 1
	for(i=0; i<32; i++) str1[i] = check(num, i);
	
	// Se imprimen al revés para generar el orden original
	for(i=0; i<32; i++){
		if(str1[31-i] == 0) printf("0");
		else printf("1");
	} 
	
}

int intAleatorio(int a,int b){
	int n;
	n= aleat()*(b-a)  +  a;
	return n;
}

float aleat(){
	return (float) rand() / RAND_MAX;
}

float floatAleatorio(int a, int b){
	float f;
	f= aleat()*(b-a)  +  a;
	return f;
}

int check(int n, int i){
	return n & (1 << i);
}
