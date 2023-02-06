#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Point2D{
	float x,y;
} point2D;

typedef struct Circulo{
	point2D c;
	float r;
} circulo;

float generaRandomAB(float a, float b);
float distancia(circulo a, circulo b);
int seTraslapan(circulo a, circulo b);
circulo circAleatorio(float X, float Y);
circulo* circulosAleatorios(int n, float dimx, float dimy);
int indice(float* ap, int n);
float minimo(float* pt, int n);

int main(int argc, char* argv[]){
	
	int n = atoi(argv[1]);
	float dimx = atof(argv[2]);
	float dimy = atof(argv[3]);
	
	srand(time(NULL));
	
	circulo* arrCirculos = circulosAleatorios(n,dimx,dimy);
	
	int i;
	for(i=0;i<n;i++){
		// La coordenada en x de los círculos se queda en 0 si y solo si no se encontró espacio para el círculo (ver función circulosAleatorios)
		if(arrCirculos[i].c.x != 0){
			printf("El circulo %d tiene centro en (%f,%f) y radio %f.\n", i+1, arrCirculos[i].c.x, arrCirculos[i].c.y, arrCirculos[i].r);
		}
	} 
	
	free(arrCirculos);
	
	return 0;
}


float generaRandomAB(float a, float b){
	float f;
	f= (float) rand()*(b-a) / RAND_MAX  +  a;
	return f;
}

float distancia(circulo a, circulo b){
	
	float aux = (a.c.x - b.c.x)*(a.c.x - b.c.x) + (a.c.y - b.c.y)*(a.c.y - b.c.y);
	float d = sqrt(aux);
	
	return d;
}

int seTraslapan(circulo a, circulo b){
	if(distancia(a,b) < a.r + b.r) return 1; // Los círculos se traslapan
	else return 0; // No se traslapan
}

circulo circAleatorio(float X, float Y){ // genera un círculo aleatorio en un semiplano dado
	
	circulo circ;
	circ.c.x = generaRandomAB(0.05,X-0.05); // Se acotan de esta forma los márgenes porque el radio es al menos 0.05, 
	circ.c.y = generaRandomAB(0.05,Y-0.05); // entonces la cercanía entre el centro y los bordes no puede sobrepasar 0.05.
	
	float v[5] = {1, circ.c.x, circ.c.y, X - circ.c.x, Y - circ.c.y};
	float Rmax = minimo(v,5); // Regresa el mínimo en el arreglo v, esto es para que el círculo no se salga del semiplano
	
	circ.r = generaRandomAB(0.05,Rmax); // Genera el radio entre 0.05 y el radio máximo
	
	return circ;
}

circulo* circulosAleatorios(int n, float dimx, float dimy){
	
	circulo* arr = (circulo*) malloc(n*sizeof(circulo));
	int i, N=0, indicador=1, x=1;
	circulo c;
	
	arr[0] = circAleatorio(dimx,dimy); // Creamos el primer círculo
	
	while(N < 1000000){
		
		c = circAleatorio(dimx,dimy); // Creamos un círculo
		
		// La variable indicador nos dice cuántos círculos ya hemos puesto correctamente
		for(i=1;i<=indicador;i++){
			if(seTraslapan(arr[i-1],c)) x = 0; // La variable x nos ayuda a ver si el círculo no se traslapa con ningún otro
		}
		
		if(x){
			arr[indicador] = c;
			indicador++;
		}
		
		if(indicador == n) break; // Si esto pasa, ya hemos colocado los n círculos correctamente
		
		x=1; 
		N++;
	}
	
	// Si se completaron 1000000  iteraciones, significa que ya no se ha podido encontrar espacios para nuevos círculos
	if(N == 1000000) printf("No se pudieron generar todos los circulos sin que se traslapen\n\n");
	
	return arr;
}

int indice(float* ap, int n){
	
	int i,r=0;

	for(i=0;i<n;i++){
		if(ap[i] < ap[r]) r=i;
	}
	
	return r;
}

float minimo(float* pt, int n){
	// regresa el mínimo en un arreglo
	
	float aux;
	int ind;
	
	ind = indice(pt, n);
	
	return pt[ind];
}


