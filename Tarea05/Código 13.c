#include <stdio.h>

char caracteres[10];
int i;

main()
{
	
	for(i=0; i<10; i++){
		printf("Introduce un carácter\n");
		caracteres[i]=getchar();
		getchar();  /* se utiliza para leer el retorno de carro */
	}
	
	/* Impresión del encabezado de la tabla */
	printf("***********************************\n");
	printf("CARÁCTER \tCÓDIGO ASCII\n");
	
	/* Bucle para imprimir los caracteres leídos en orden inverso */
	for(i=9;i>=0;i--){
		putchar(caracteres[i]);
		printf("\t\t"); /* imprime dos tabulaciones */
		printf("%d",caracteres[i]);
		printf("\n");
	}
		return 0;
}
