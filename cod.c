#include<stdio.h>

int main(){
	
	
	int i, in = 0, f = 0;
	
	char cadena[50], Ncadena[51];
	
	for (i =0; i<50;i++) cadena[i] = 0;

	for (i =0; i<51;i++) Ncadena[i] = 0;
	
	printf("Dame una cadena de texto (de a lo mas 50 caracteres): ");
	
	gets(cadena);
	
	
	while(in < 50){
		
		while(in < 50){

			if(cadena[in] != 0 && cadena[in] != 32) break;
			
			in++;
		}
		
		f = in;
		
		while(in < 49){
			
			if(cadena[f] != 32 && (cadena[f+1] == 32 || cadena[f+1] == 0)) break;
			 
			f++;
		}
		
		for(i = in; i<= f; i++)	Ncadena[i] = cadena[f - (i - in)];

		in = f+1;
		f= f+1;
		
	}
	
	for(i=0; i<50; i++){
		if(Ncadena[i] == 0) Ncadena[i] = 32;
	}
	
	Ncadena[50] = 0;
	
	printf("\n%s", Ncadena);
	
	
	return 0;
}
