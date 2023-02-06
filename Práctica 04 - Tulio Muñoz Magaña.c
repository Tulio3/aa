#include <stdio.h>

int main(){
	
	int n, i, j;
	
	printf("Dame el numero de pisos del triangulo: ");
	scanf("%d", &n);
	getchar();
	
	// arr contendr� la l�nea anterior para calcular la siguiente, que ser� arr2
	
	int *arr = (int*) malloc(n * sizeof(int));
	int *arr2 = (int*) malloc(n * sizeof(int));
	
	arr[0] = 1;
	arr2[0] = 1;
	
	printf("\n1");
	
	for (i=1; i< n; i++) {
		
		// El �ltimo elemento de cada piso debe ser 1
		
		arr2[i] = 1;
		
		// Aqu� hacemos el c�lculo de la nueva fila
		
		for (j = 1; j < i; j++) arr2[j] = arr[j-1] + arr[j];
	
		printf("\n\n");
		
		// Imprimimos la nueva fila
		
		for( j = 0; j<= i; j++) printf("%d ", arr2[j]);
		
		// Colocamos la l�nea producida en arr para que sirva de referencia para construir la nueva
		
		for(j=0; j<n; j++) arr[j] = arr2[j];
		
	}
	
	// Imprimimos la �ltima fila del arreglo
	
	printf("\n\nLa ultima fila es: ["); 
	
	for (i=0; i<n-1; i++) printf("%d, ", arr2[i]);
	
	printf("%d]", arr2[n-1]);
	
	free(arr);
	free(arr2);
	
	return 0;
}
