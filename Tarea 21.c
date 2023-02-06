#include <stdio.h>

int main(){
	
	int i,n;
	
	printf("Ingresa el tamanio del vector char: "); scanf("%d", &n);
	char* orC = (char*) malloc(n*sizeof(char));
	
	printf("\nIngresa el tamanio del vector int: "); scanf("%d", &n);
	int* orI = (int*) malloc(n*sizeof(int));
	
	printf("\nIngresa el tamanio del vector unsigned int: "); scanf("%d", &n);
	unsigned int* orUI = (unsigned int*) malloc(n*sizeof(unsigned int));
	
	printf("\nIngresa el tamanio del vector float: "); scanf("%d", &n);
	float* orF = (float*) malloc(n*sizeof(float));
	
	printf("\nIngresa el tamanio del vector double: "); scanf("%d", &n);
	double* orD = (double*) malloc(n*sizeof(double));
	
	printf("\nIngresa el tamanio del vector long double: "); scanf("%d", &n);
	long double* orLD = (long double*) malloc(n*sizeof(long double));
	
	char* aC = orC;
	int* aI = orI;
	unsigned int* aUI = orUI;
	float* aF = orF;
	double* aD = orD;
	long double* aLD = orLD;
	
	for()
	
	printf("Vector char: ");
	for(i=0; i<sizeof(orC); i++); printf("%c ", orC[i]); printf("\n");
	printf("Vector int: ");
	for(i=0; i<sizeof(orI); i++); printf("%d ", orI[i]); printf("\n");
	printf("Vector unsigned int: ");
	for(i=0; i<sizeof(orUI); i++); printf("%u ", orUI[i]); printf("\n");
	printf("Vector float: ");
	for(i=0; i<sizeof(orF); i++); printf("%f ", orF[i]); printf("\n");
	printf("Vector double: ");
	for(i=0; i<sizeof(orD); i++); printf("%lf ", orD[i]); printf("\n");
	printf("Vector long double: ");
	for(i=0; i<sizeof(orLD); i++); printf("%Le ", orLD[i]); printf("\n");
	
	
	
	
	
	printf("Vector char: ");
	for(i=0; i<sizeof(orC); i++); printf("%c ", orC[i]); printf("\n");
	printf("Vector int: ");
	for(i=0; i<sizeof(orI); i++); printf("%d ", orI[i]); printf("\n");
	printf("Vector unsigned int: ");
	for(i=0; i<sizeof(orUI); i++); printf("%u ", orUI[i]); printf("\n");
	printf("Vector float: ");
	for(i=0; i<sizeof(orF); i++); printf("%f ", orF[i]); printf("\n");
	printf("Vector double: ");
	for(i=0; i<sizeof(orD); i++); printf("%lf ", orD[i]); printf("\n");
	printf("Vector long double: ");
	for(i=0; i<sizeof(orLD); i++); printf("%Le ", orLD[i]); printf("\n");
	
	free(orC);
	free(orI);
	free(orUI);
	free(orF);
	free(orD);
	free(orLD);
	
	return 0;
}
