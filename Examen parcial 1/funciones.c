#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

char* fun2(char c, char* str){
	
	int i, cont = 0;
	
	for(i=0; i< strlen(str); i++){
		if(str[i] == c) cont++;
	}
	
	
	
	
	
	
	
	
	
}

char* fun3(char** ap){
	
	
	
	
	
	
	
	
	
}
