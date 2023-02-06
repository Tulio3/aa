#include "Shell.cpp"

Window ventana("Proyecto Shell", 256, 144);

// colores
COLORREF rojo  = RGB(255,0,0);
COLORREF verde = RGB(0,255,0);
COLORREF azul  = RGB(0,0,255);

int main()
{
	int x0=10,y0=10, x1=30,y1=50, size=5;
	
	// dibuja una linea de grosor size con color azul que une los puntos (x0,y0) y (x1,y1) 
	ventana.line(x0, y0, x1, y1, azul, size);
	ventana.Paint();
	
	return MainLoop();
}
