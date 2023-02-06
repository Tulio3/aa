#include <stdio.h>
void imprimeValor();
main()
{
	imprimeValor();
	imprimeValor();
	imprimeValor();
	imprimeValor();
	return 0;
}
void imprimeValor()
{
	static int contador = 0;
	printf("El valor de contador es: %d\n", contador);
	contador++;
}
