#include <stdio.h>
#include <stdlib.h>

int esPalindroma(char* palabra, int l);
char* palabraSimplificada(char* palabra);
int longitud(char* palabra);
void concatena(char* palabra1, char* palabra2);
void freeMat(char** M, int nr);

int main(int argc, char* argv[]){
	
	int i,Ltotal=0;
	
	char** libro = (char**) malloc((argc-1)*sizeof(char*));
	
	for(i=0;i<argc-1;i++) libro[i] = palabraSimplificada(argv[i+1]);
	
	for(i=0;i<argc-1;i++) Ltotal += longitud(libro[i]); // Ltotal es la longitud total de todas las palabras simplificadas (sin comas ni espacios) juntas

	char* v = (char*) malloc(Ltotal*sizeof(char)); // Aquí vamos a guardar todas las palabras simplificadas concatenadas
	
	v[0] = '\0'; // Partimos de un string vacío
	
	for(i=0;i<argc-1;i++) concatena(v,libro[i]); // Vamos pegando las palabras ya simplificadas
	
	if(esPalindroma(v,Ltotal)) printf("La concatenacion de los argumentos es una palabra palindroma");
	else printf("La concatenacion de los argumentos no es una palabra palindroma");

	freeMat(libro,argc);
	
	return 0;
}

int esPalindroma(char* palabra, int l){
	
	// El indicador nos dice si la palabra sigue siendo palíndroma
	int i, indicador = 1;
	for(i=0; i<l/2; i++){
		if(palabra[i] != palabra[l-i-1]) indicador = 0;
	}
	
	return indicador;
}

int longitud(char* palabra){
	
	int i,cont=0;
	char c = 'a';
	
	while(c != '\0'){
		c = palabra[cont];
		cont++; // Nos va a decir la longitud de la palabra
	}
	
	return cont-1;
}

char* palabraSimplificada(char* palabra){
	
	int L = longitud(palabra);
	int i;

	char* palabra2 = (char*) malloc((L+1)*sizeof(char));
	char* ap = palabra2;

	for(i=0;i<L;i++){
		if(palabra[i] != ' ' && palabra[i] != ','){
			*ap = palabra[i];
			ap++;
		}
	}
	
	*ap = '\0'; // Terminamos el string

	return palabra2;
}

void concatena(char* palabra1, char* palabra2){
	
	int i;
	
	int L1 = longitud(palabra1);
	int L2 = longitud(palabra2);

	// Concatenamos
	for(i=L1; i<L1+L2; i++) palabra1[i] = palabra2[i-L1];
	
	palabra1[L1+L2] = '\0';

}

void freeMat(char** M, int nr){
	int i;
	for(i=0;i<nr;i++) free(M[i]);
	free(M);
}
