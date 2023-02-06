#include<stdio.h>

int main(void){
	
	float num, *res;
	
	printf("Introduzca un número\n: "); scanf("%f", &num);
	res = 2*num;
	printf("%f", *res);
	
	
	
	
	return 0;
}
