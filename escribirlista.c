  #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "auxiliar.h"



      int main(int argc, char* argv[]){
      char **linea;
      int a,j,contador;
argv0 = "delreves";
      char array[2048];//Array para guardar líneas
        int i;
       FILE *p;//Puntero del archivo




for(i=argc-1; i>0; i--){//recorremos los argumentos en orden inverso
linea=(char **)malloc(2048);
contador=0;
if(!linea){
Error(EX_NOINPUT,"No se pudo ubircar la memoria dinamica necesaria");}
p = fopen(argv[i],"r");
while(fgets(array,2048,p)){
linea[contador]=strdup(array);
contador++;
linea=(char **)realloc(linea,sizeof(char *) *(contador+1));
if(!linea){
Error(EX_NOINPUT,"No se pudo ubircar la memoria dinamica necesaria");}
}for(j=contador;j>0;j--){
printf("%s",linea[j-1]);}
 fclose(p);
}
}
