#include<stdio.h>

int main(){

	int N, i;
	float max, min, a;
	
	printf("Dame N: ");
	scanf("%d", &N);
	getchar();
	
	for(i=0;i<N;i++){
		
		printf("Dame un numero: ");
		scanf("%f", &a);
		getchar();
		
		if(i==0){
			max = a;
			min = a;
		}		
		
		if(a > max) max = a;
		
		if(a < min) min = a;
		
	}

	printf("El numero maximo es %f \n", max);
	printf("El numero minimo es %f", min);

	return 0;
}
