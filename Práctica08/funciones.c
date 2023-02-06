#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void representar(unsigned int num){
	
	int i;
	int str1[32];
	
	// Se guarda en el string los lugares que tienen un 1
	for(i=0; i<32; i++) str1[i] = check(num, i);
	
	for(i=0; i<32; i++){
		if(str1[i] == 0) printf("0");
		else printf("1");
	} 
	
}

int check(int n, int i){
	return n & (1 << i);
}

