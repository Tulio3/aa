#include<stdio.h>

int main(){
	
	float q1,q2,p1,p2;
	float a,b;
	
	printf("Ingresa el porcentaje de objetos provenientes de la línea I\n");
	scanf("%f", &q1);
	getchar();
	
	printf("Ingresa el porcentaje de objetos provenientes de la línea II\n");
	scanf("%f", &q2);
	getchar();
	
	printf("Ingresa la probabilidad de que los objetos provenientes de la línea I sean defectuosos\n");
	scanf("%f", &p1);
	getchar();
	
	printf("Ingresa la probabilidad de que los objetos provenientes de la línea II sean defectuosos\n");
	scanf("%f", &p2);
	getchar();
	
	q1 = q1/100;
	q2 = q2/100;
	p1 = p1/100;
	p2 = p2/100;
	
	a = p1*q1 + p2*q2;
	b = 1-a;
	b=b*100;
	
	printf("La probabilidad de que el producto no sea defectuoso es %f%", b);
	
	return 0;
}
