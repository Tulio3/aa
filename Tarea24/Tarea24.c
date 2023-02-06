#include <stdio.h>
#include <stdlib.h>

typedef struct Complex{
	float r,i;
} complex;

// Las siguientes 3 estructuras son para
// el inciso b)
typedef struct Struc1{
	char c1,c2;
} struc1;

typedef struct Struc2{
	int n1,n2;
	double d;
} struc2;

typedef struct Struc3{
	complex c;
	int n;
	float f1,f2;
} struc3;


complex suma(complex c1, complex c2);
complex resta(complex c1, complex c2);
complex multiplica(complex c1, complex c2);
void imprime(complex c);
float** productoExteriorVectorial(float* u, int size_u, float* v, int size_v);
void printMatrix(float ** mat,int nRens, int mCols);
void printHorizontalVector(float* vec2, int n2);
void printVerticalVector(float* vec1, int n1);;

int main(){
	
	// Inciso a)
	
	complex comp1;
	comp1.r = 1;
	comp1.i = -2;
	
	complex comp2;
	comp2.r = -4;
	comp2.i = 3;
	
	printf("\n Inciso a)\n");
	
	printf("\nLos complejos son "); imprime(comp1); printf(" y "); imprime(comp2);
	
	printf("\nLa suma es "); imprime(suma(comp1,comp2));
	printf("\nLa resta es "); imprime(resta(comp1,comp2));
	printf("\nEl producto es "); imprime(multiplica(comp1,comp2));
	
	// Inciso b)
	
	struc1* ptr1;
	struc1 apuntado1;
	ptr1 = &apuntado1;
	
	struc2* ptr2;
	struc2 apuntado2;
	ptr2 = &apuntado2;
	
	struc3* ptr3;
	struc3 apuntado3;
	ptr3 = &apuntado3;
	
	printf("\n\n Inciso b)");
	
	// Este avanza 2, dos chars
	printf("\n\nptr1 apunta a %u", ptr1);
	ptr1++;
	printf("\nptr1++ apunta a %u", ptr1);
	
	// Este avanza 16, dos enteros y un doble
	printf("\n\nptr2 apunta a %u", ptr2);
	ptr2++;
	printf("\nptr2++ apunta a %u", ptr2);
	
	// Este avanza 20, un complejo (8), un entero y dos flotantes 
	printf("\n\nptr3 apunta a %u", ptr3);
	ptr3++;
	printf("\nptr3++ apunta a %u", ptr3);
	
	// Inciso c)
	
	int n1=7, n2=5, i;
	
	float* vec1 = (float*) malloc(n1*sizeof(float));
	float* vec2 = (float*) malloc(n2*sizeof(float));	
	
	for(i=0;i<n1;i++) vec1[i] = 0.25*(i+1);
	for(i=0;i<n2;i++) vec2[i] = (-0.25)*(i+1);
	
	float** prod = productoExteriorVectorial(vec1,n1,vec2,n2);
	
	printf("\n\n Inciso c)\n");
	printVerticalVector(vec1,n1);
	printf("\n  *\n");
	printHorizontalVector(vec2,n2);
	printf("\n  =\n");
	printMatrix(prod,n1,n2);
	
	return 0;
}

complex suma(complex c1, complex c2){
	complex c;
	c.r = c1.r + c2.r;
	c.i = c1.i + c2.i;
	return c;
}

complex resta(complex c1, complex c2){
	complex c;
	c.r = c1.r - c2.r;
	c.i = c1.i - c2.i;
	return c;
}

complex multiplica(complex c1, complex c2){
	complex c;
	c.r = c1.r*c2.r - c1.i*c2.i;
	c.i = c1.i*c2.r + c2.i*c1.r;
	return c;
}

void imprime(complex c){
	// El .2 para que quede más estético
	printf("%.2f + %.2fi", c.r, c.i);
}

float** productoExteriorVectorial(float* u, int size_u, float* v, int size_v){
	
	int i,j;
	
	// Pedir el espacio para la matriz resultante
	float** mat = (float**) malloc(size_u*sizeof(float*));
	for(i=0;i<size_u;i++) mat[i] = (float*) malloc(size_v*sizeof(float));
	
	for(i=0;i<size_u;i++){
		for(j=0;j<size_v;j++) mat[i][j] = u[i]*v[j];
	}
	
	return mat;
}

void printMatrix(float ** mat,int nRens, int mCols){
	int i,k;
	printf("\n");
	for(i=0;i<nRens;i++){
		for(k=0;k<mCols;k++){
			printf("%10.3f",mat[i][k]);
		}
		printf("\n");
	}
}

void printHorizontalVector(float* v,int l){
	int i;
	printf("\n");
	for(i=0;i<l;i++) printf("%10.3f",v[i]);
}

void printVerticalVector(float* v,int l){
	int i;
	printf("\n");
	for(i=0;i<l;i++){
		printf("%10.3f",v[i]);
		printf("\n");
	}
}
