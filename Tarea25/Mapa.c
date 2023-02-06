#include <stdio.h>
#include <stdlib.h>

void printMatScreen(char** mat, int nrens, int ncols);
char** guarda(char* nombre, int* ren, int* col, int* gotaX, int* gotaY);

int main(){
	
	// los renglones, las columnas y la posición en x e y de la gota
	int r,c,xG,yG,i;
	
	char** mapa = guarda("map.txt",&r,&c,&xG,&yG);

	printMatScreen(mapa,r,c);
	
	for(i=0;i<r;i++) free(mapa[i]);
	free(mapa);
	
	return 0;
}

char** guarda(char* nombre, int* ren, int* col, int* gotaX, int* gotaY){
	
	int i,k;
	char var; // Basura
	
	FILE* mapa = fopen(nombre, "r");
	
	if(!mapa){
		printf("No se pudo abrir %s", nombre);
		return;
	}
	
	fscanf(mapa,"%d",ren);
	fscanf(mapa,"%d",col);
	fscanf(mapa,"%d",gotaX);
	fscanf(mapa,"%d",gotaY);
	
	// El Enter
	fscanf(mapa,"%c",&var);
	fscanf(mapa,"%c",&var);
	
	char** mat = (char**) malloc(*ren*sizeof(char*));
	for(i=0;i<*ren;i++) mat[i] = (char*) malloc(*col*sizeof(char));
	
	for(i=0;i<*ren;i++){
		for(k=0;k<*col;k++){
			fscanf(mapa,"%c",&mat[i][k]);
		}
		// El Enter
		fscanf(mapa,"%c",&var);
		fscanf(mapa,"%c",&var);
	}
	
	fclose(mapa);
	
	return mat;
}


void printMatScreen(char** mat, int nrens, int ncols){
	int i,k;
	for(i=0;i<nrens;i++){
		for(k=0;k<ncols;k++){
			printf("%c",mat[i][k]);
		}
		printf("\n");
	}
}

