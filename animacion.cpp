#include "Shell.cpp"

Window ventana("Proyecto Shell", 256, 144);

COLORREF** createImage(int nr, int nc);
void freeImage(COLORREF** imagen, int nr);

int main()
{	
	int *nr, *nc, nimages=5, i;
	COLORREF*** imagenes;
	char filename[100];
	
	// reservamos 5 apuntadores a imagen, y 5 apuntadores para las dimensiones de cada imagen
	imagenes = (COLORREF***) malloc(nimages * sizeof(COLORREF**));
	nr = (int*) malloc(nimages * sizeof(int));
	nc = (int*) malloc(nimages * sizeof(int));
	
	// reserva memoria para cada imagen y lee cada imagen
	for(i=0; i<nimages; i++){
		
		// esto imprime en una cadena de caracteres
		sprintf(filename, "%d.bmp", i);
		
		// leo dimensiones del bmp
		DimensionesBmp(filename, &nr[i], &nc[i]); // solo bmp de 24 bits
		
		// memoria para la imagen i
		imagenes[i] = createImage(nr[i], nc[i]);
		
		// leemos imagen i
		LeeBmpColor(imagenes[i], filename);
	}
	
	// ciclo infinito imprimiendo las imagenes
	i = 0;
	while(1){
		ventana.PlotCBitmap(imagenes[i], nr[i], nc[i], 100, 100, 1.0);
		
		i = (i+1)%5;
		
		Sleep(100);
	}

	// liberamos cada imagen
	for(i=0; i<nimages; i++){
		freeImage(imagenes[i], nr[i]);
	}
	//liberamos los punteros a imagen
	free(imagenes);
	free(nr);
	free(nc);
	
	return MainLoop();
}




// definicion de funciones
COLORREF** createImage(int nr, int nc)
{
	// memoria para la imagen
	int i;
	COLORREF** imagen;
	
	imagen = (COLORREF**) malloc(nr * sizeof(COLORREF*));
	for (i=0; i < nr; i++){
		imagen[i] = (COLORREF*) malloc(nc * sizeof(COLORREF));
	}
	
	return imagen;
}

void freeImage(COLORREF** imagen, int nr)
{	
	int i;
	
	for (i=0; i < nr; i++){
		free(imagen[i]);
	}
	
	free(imagen);
}
