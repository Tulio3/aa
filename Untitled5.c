#include<stdio.h>

void fun(unsigned char *cad1, unsigned char *cad2){
	
	while(*cad1++ = *cad2++){
		printf("1");	
	}
}

int main(){
	
	char a[8] = "Hghghfgh";
	char b[4] = "wal6";
	
	fun(a,b);
	
	printf("%s", a);
	printf("\n%s", b);
	
	return 0;
}
