#include<stdio.h>

int main(){
	
	int N,i,var,suma = 0,prod = 1;
	int s = 0,p = 0;

	printf("Ingresa N: ");
	scanf("%d", &N);
	getchar();
	
	for(i=0;i<N;i++){
		
		printf("Dame un numero entero: ");
		scanf("%d", &var);
		getchar();
		
		if((var % 2) == 0) s = 1;
		if((var % 2) == 1) p = 1;
		
		if((var % 2) == 0) suma = suma + var;
		else prod = prod * var;
		
		
	}


	if(s == 1) printf("La suma de los pares es %d \n", suma);
	else printf("No se han introducido pares \n");
	
	if(p == 1) printf("El producto de los impares es %d \n", prod);
	else printf("No se han introducido impares \n");
	

	return 0;
}
