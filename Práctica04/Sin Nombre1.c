#include<math.h>

int cuadratica(double a, double b, double c, double*x1, double *x2){
	
	int n;
	double dis;
	
	dis = b*b - 4*a*c;
	
	if(dis > 0) n=2;
	if(dis = 0) n=1;
	if(dis < 0) n=0;
	
	if(n == 2 || n == 1){
		*x1 = (-b + sqrt(dis)/2*a;
		*x2 = (-b - sqrt(dis)/2*a;
	}
	
	return n;
}
	
void sumarPolinomios(int n, double *c1, int m, double*c2, int *k, double *c3){
	
	int v;
	
	if(n > m){
	  	k = n;
	  	v = m;
	}	
	else{
		k = m;
		v = n;
}
	
	for(int i=0; i<n; i++ ) c3[i] = c1[i] + c2[i];
	
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
