#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char* fun1(char* str1, char* str2){
	
	int m,i;
	
	printf("%s\n", str1);
	printf("%s\n", str2);
	
	if(strlen(str1) < strlen(str2)) m = strlen(str1);
	else m = strlen(str2);
	
	printf("%d\n", m);
	
	char * str = (char*) malloc(m*sizeof(char));
	
	printf("%s\n", strlen(str));
	printf("%s\n", str);
	
	for(i=0; i< m; i++){
		if(str1[i] == str2[i]) {
			
			*str = str1[i];
			str++;
			
	}
	
		printf("%c\n", *str);
		
	}
	
	printf("%s\n", str);
	
	return str;
	
}

int main(int argc, char *argv[]) {
	
	char a[] = "a44453";
	char b[] = "adgg";
	
	printf("%d\n",strlen(b));
	
	char* c = fun1(a,b);
	
	printf("%s", c);
	
	
	return 0;
}
