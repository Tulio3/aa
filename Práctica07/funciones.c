#include <stdlib.h>
#include <stdio.h>

int check(int n, int i){
	return n & (1 << i);
}

int ejercicio1(unsigned int n){
	
	int i, cont=0;
	
	for(i=0; i<sizeof(unsigned int)*8; i++){
		if(check(n,i)) cont++;
	}
	
	return cont;
}

unsigned int ejercicio2(unsigned int n){
	return ~n;
} 

// Los siguientes son 2 de los ejercicios extra

int posicion(unsigned int n){
	
	int c=0, i=-1;
	
	while(i==-1 && c < 32){
		if(check((int) n,c)) i = c;
		c++;
	}
	
	return i; 
}

unsigned int cadena(unsigned int n){
	
	if(posicion(n) == -1) return 0;
	
	return 1 << posicion(n);	
}
