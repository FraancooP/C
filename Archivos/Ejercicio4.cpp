/*Escriba un programa que busque dentro del archivo el_quijote.txt
la cantidad de veces que aparecen las palabras 
“Quijote”, 
“Rocinante” y “Sancho”. Recuerden descargar
el archivo en el mismo lugar donde corren el programa.*/
 #include <iostream>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 using namespace std;
 void check(FILE *fp);
 int main(int argc, char *argv[]){
    FILE *fp=NULL;
    fp=fopen("el_quijote.txt","r");
    check(fp);
    char palabra[20]={0};
    int cant_qui=0,cant_roc=0,cant_san=0;
    while (fscanf(fp,"%s",&palabra)!=EOF)
    {
      if(strcmp(palabra, "Quijote")==0){
         cant_qui++;
      }
      if (strcmp(palabra,"Rocinante")==0)
      {
         cant_roc++;
      }
      if (strcmp(palabra,"Sancho")==0)
      {
         cant_san++;
      }
    }
      printf("Cantidad de veces que se repitieron las palabras.\n");
      printf("Quijote: %d\n",cant_qui);
      printf("Rocinante: %d\n",cant_roc);
      printf("Sancho: %d\n",cant_san);
      system("pause");
    return 0;
 }
 void check(FILE *fp){
    if (fp==NULL)
    {
        printf("Imposible abrir el archivo.\n");
        exit(1);
    }
 }