#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *fileIn  = fopen("sample.txt", "r");

    if (!fileIn){
        printf("No se pudo abrir archivo de entrada");
        return 0;
    }



    FILE *fileOut = fopen("result.txt", "w");
    if (!fileOut){
        printf("No se pudo abrir archivo de salida");
        fclose(fileIn);
        return 0;
    }




    char hold = 'A';

    while(1) // End Of File
    {
        
       
       /*
       int r = fscanf(fileIn,"%c",&hold);
       if(r < 0){ 
          printf("\n No Mas datos r = %d, c=%d",r,(int)hold);
          break; // ya no lee nada
       }
       */
      
		
       hold = getc(fileIn);
       
       
       if(hold == EOF){ 
          printf("\n EOF ");
          break; // to prevent EOF from print to the stream
       }
       

       printf("\n%c <%d>",hold, (int) hold);
       
       fprintf(fileOut,"%c",hold);
       //fputc(hold, fileOut);
       //getchar();
       
    }

    printf("\n FIN DE CICLO");

    fclose(fileIn);
    fclose(fileOut);
    printf("\n");
    return 0;
}
