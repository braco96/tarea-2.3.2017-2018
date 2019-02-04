#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include "auxiliar.h"
 

      int main(int argc, char* argv[]){
     
       char **linea; 
        FILE *archivo;
        char array[2048];
        int contador;
        int i,j;
      //Cuando se quiere mostrar ayuda
   if(argc==2) {
      if((strcmp(argv[1],"-h") ==0)||((argc==2) && strcmp(argv[1], "--help")==0)){
           fprintf(stdout, "bocabajo: Uso: bocabajo [ fichero... ]\n");
           fprintf(stdout, "bocabajo: Invierte el orden de las líneas de los ficheros (o de la entrada).\n");
       
           return EX_OK;
      }
      
       int i;
        FILE *entrada;
        short err = 0;
       for(i=1; i<argc; i++){//Mientras haya ficheros sin abrir
           entrada = fopen(argv[i],"r");//Abrir el fichero
           err = entrada == NULL;
          if(!err)
             fclose(entrada);
          
       }//Cerramos el for


      if (err){           
          Error(EX_NOINPUT, "El fichero \"%s\" no puede ser leido.", argv[i]);
      }//Cerrmaos este if
    }//Cerramos el if de argc 2

     // No hay error en los archivos ni se pide ayuda
	
        if (argc == 1) {
              
		
		linea = (char **)malloc(sizeof(char *));
                contador =0;
		if (!linea)
			Error(EX_OSERR,"No se pudo ubicar la memoria dinámica necesaria.");
		while (fgets(array,2048, stdin)) {
			linea[contador] = strdup(array);
                         contador++;
			linea = (char **)realloc(linea,sizeof(char *) * (contador+1));
			if (!linea )
				Error(EX_OSERR,"No se pudo ubicar la memoria dinámica necesaria.");
		}
               for(i=contador;i>0;i--)
                   printf("%s",linea[i-1]);
               for(i=0;i<contador;i++)
                   free(linea[i]);
            free(linea);
         }  
      if(argc>1){ int i;
           for(i=argc-1;i >0 ;i--){
             linea = (char **)malloc(sizeof(char *));
             contador=0;
             archivo = fopen(argv[contador],"r");
                if(archivo==NULL){
                   Error(EX_NOINPUT, "El fichero \"%s\" no puede ser leido.", argv[i]);}
                else{
                   while(fgets(array,2048,archivo) !=NULL){
                        linea[contador] = strdup(array);
                         contador++;
	    linea = (char **)realloc(linea,sizeof(char *) * (contador+1));
			if (!linea )
				Error(EX_OSERR,"No se pudo ubicar la memoria dinámica necesaria.");
		}
               
        }
	fclose(archivo); 
          

              }
           for(j=contador;j>0;j--)
                 printf("%s",linea[j-1]);
               for(j=0;j<contador;j++)
                   free(linea[j]);
            free(linea);
        


}
return EX_OK;
}


