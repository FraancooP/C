/*Escriba un programa que cree un menu de opciones que permita
a) abrir un archivo, b) escribir un archivo, c) leer un archivo.*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void check(FILE *fp);
int main(int argc, char *argv[]){
    FILE *fp=NULL;
    char escritura[1000],op=' ',cass=' ';
    do
    {
        printf("Seleccione una opcion.\n");
        printf("A)Abrir un archivo.\n");
        printf("B)Escribir en un archivo.\n");
        printf("C)Leer un archivo.\n");
        scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
        fp=fopen("archivo.txt","a");
        check(fp);
        printf("Archivo abierto.\n");
        fclose(fp);
            break;
        case 'b':
        case 'B':
        fp=fopen("archivo.txt","w");
        check(fp);
        printf("Ingrese lo que desea cargar.\n");
        scanf(" %[^\n]",escritura);
        fprintf(fp,"%s",escritura);
        fclose(fp);
            break;
        case 'c':
        case 'C':
        fp=fopen("archivo.txt","r");
        check(fp);
        while (!feof(fp))
        {
            fscanf(fp,"%s",&escritura);
            printf("%s",escritura);
        }
        
            break;
        default:
        printf("No se elijio ninguna opcion propuesta.\n");
            break;
            printf("Desea continuar?S/N");
            scanf(" %c",&op);
        }
        fclose(fp);
    } while (op=='s' && 'S');
    return 0;
}
void check(FILE *fp){
    if (fp==NULL)
    {
        printf("Imposible abrir el archivo.\n");
        exit(1);
    }
}