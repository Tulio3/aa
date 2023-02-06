#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct poly{
	int grado; 
	double* coef;
} Poly;

void createPoly(Poly* P);
void freePoly(Poly* P);
Poly sumaPolys(Poly p, Poly q);
void sumaPolysFILE();

#endif
