#include <stdio.h>

main ( )
{
	int edad;
	char sexo;
	
	printf ("Escriba su edad (en a�os) y sexo (H o M):\n");
	scanf ("%i %c", &edad, &sexo) ;
	printf("Su sexo es %c y su edad %i a�os\n", sexo, edad);
	return 0;
}
