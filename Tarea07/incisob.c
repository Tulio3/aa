#include<stdio.h>
#include<math.h>

int main(){
	
	float x1,x2,r1,y1,y2,r2,c1,c2,d;
	
	printf("Dame la coordenada en x del primer circulo: "); scanf("%f", &x1);
	printf("Dame la coordenada en y del primer circulo: "); scanf("%f", &y1);
	printf("Dame el radio del primer circulo: "); scanf("%f", &r1);
	printf("Dame la coordenada en x del segundo circulo: "); scanf("%f", &x2);
	printf("Dame la coordenada en y del segundo circulo: "); scanf("%f", &y2);
	printf("Dame el radio del segundo circulo: "); scanf("%f", &r2);
	
	// Calculamos primero los cuadrados que van dentro de la raíz por limpieza
	c1 = (y2-y1)*(y2-y1);
	c2 = (x2-x1)*(x2-x1);
	// d es la distancia entre los centros
	d = sqrt(c1+c2);
	
	if(d < (r1+r2)) printf("Hay traslape de areas");
	else printf("No hay traslape de areas");
	
	return 0;
}
