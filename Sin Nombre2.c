#include<stdio.h>

int main(){
	
	int i; 
	int sum = 0, p;
	
	
	char cadena[50];
	
	for (i =0; i<50;i++) cadena[i] = 0;
	
	
	printf("Dame una cadena de texto (no mas de 50 caracteres): ");
	gets(cadena);
	
	
	for(i = 0; i < 50; i++) {
		
		if(cadena[i] != 0) sum += cadena[i];
		else break;
		
		
	}
	
	p = sum/i;
	
	printf("El caracter promedio es: %c", p);
	
	getchar();
	
	return 0;
}
