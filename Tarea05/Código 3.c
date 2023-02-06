#include <stdio.h>

void primera(void);
void segunda(void);

main()
{
	printf("La primera función llamada, main\n");
	primera();
	segunda();
	printf("Final de la función main\n");
	return 0;
}

void primera(void)
{
	printf("Llamada a la función primera\n");
	return;
}

void segunda(void)
{
	printf("Llamada a la función segunda\n");
	return;
}
