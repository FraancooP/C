/*
Escriba un programa que cree un archivo binario llamado "pares.txt” 
que contenga los valores pares del 1 al 100. Luego abrir el archivo y
mostrarlo.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void check(FILE *fp);
int main(int argc, char *argv[]){
    FILE *fp=NULL;
    int nums[50],i=0,j=0;
    fp=fopen("numeros_pares.txt","w");
    check(fp);
    printf("Buscando numeros pares entre 1 y 100.\n");
    for (int i = 0; i < 100; i++)
    {
        if(i%2==0){
            nums[j]=i;
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        fprintf(fp,"%d\n",nums[i]);
    }
    fclose(fp);
    fp=fopen("numeros_pares.txt","r");
    check(fp);
    i=0;
    while (!feof(fp))
    {
        fscanf(fp,"%d",&nums[i]);
        printf("%d\n",nums[i]);
        i++;
    }
    fclose(fp);
    return 0;
}
void check(FILE *fp){
    if(fp==NULL){
        printf("Imposible abrir el archivo.\n");
        exit(1);
    }
}