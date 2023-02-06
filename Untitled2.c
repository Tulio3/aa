#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int* x = (int*) malloc(5*sizeof(int));
	
	int i=0;
	
	x[0] = 3;
	x[1] = 88;
	x[2] = 6;
	x[3] = 67;
	x[4] = 99;
	
	
	while(*x <= 90){
		
		
		printf("%d ", *x++);
}

	free(x);
	
	getchar();

	return 0;
	
}
