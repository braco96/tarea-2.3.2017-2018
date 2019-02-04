#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "auxiliar.h"
int contar(char **cadena,int l);
      int main(int argc, char* argv[]){
      char **copiar;
      int a,j,i;
 char array[2048];//Array para guardar líneas
       FILE *p;//Puntero del archivo
argv0 = "bocabajo";
     
       

if(((argc==2) && strcmp(argv[1],"-h") ==0)||((argc==2) && strcmp(argv[1], "--help")==0)){
           fprintf(stdout, "bocabajo: Uso: bocabajo [ fichero... ]\n");
           fprintf(stdout, "bocabajo: Invierte el orden de las líneas de los ficheros (o de la entrada).\n");
       
      return EX_OK;
}
       if(argc<2){




while(fgets(array, 2048, p)){
                      fputs(array, stdout);
                  }
                  fclose(p);
               
             return EX_OK;

}
else{


      //metodo de la entrada estandar
for(i=1; i<argc; i++){//hacemos todas las prubeas
copiar=(char **)malloc(2040);

a=0;
if(!copiar){
Error(EX_OSERR,"No se pudo ubircar la memoria dinamica necesaria");}

p = fopen(argv[i],"r");
          if(p == NULL){

             Error(EX_NOINPUT, "El fichero \"%s\" no puede ser leido.", argv[i]);

          }
while(fgets(array,3000,p)){
if( (strlen(array)-1)>2048){Error(EX_OSERR,"No se pudo ubircar la memoria dinamica necesaria");}
copiar[a]=strdup(array); 
a++;

copiar=(char **)realloc(copiar,sizeof(char *) *(a+1));
if(!copiar){
Error(EX_OSERR,"No se pudo ubircar la memoria dinamica necesaria");}

}
 fclose(p);



}

for(i=argc-1; i>0; i--){//hacemos todas las prubeas
a=0;
p = fopen(argv[i],"r");

while(fgets(array,2050,p)){
copiar[a] = strdup(array);
 fputs(array, stdout);
a++;}
 for(j=a;j>0;j--){
                }

fclose(p);
} 
//si hemos llegado aqui todo esta bien
return EX_OK;


      
}
  
int contar(char **cadena,int l){
int res=0;
int contador=0;
int i=0;
        while ( cadena[l-1][i] != '\0' ) { 
if(contador==2048){res=1;}
contador++; 
i++;
    }contador--;
return res;
}
}
