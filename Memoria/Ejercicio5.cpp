/*Modificar el codigo para crear una función mostrar los valores. */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void mostrar(char *,int);
int main(int argc, char *argv[]) {
	char *puntero;
	char letras=' ';
	int cantidad=0,nuevacant=0;
	printf("Ingrese la cantidad de letras que desea cargar: \n");
	scanf("%d",&cantidad);
	puntero=(char *)malloc(cantidad*sizeof(int));
	printf("Ingrese las letras: \n");
	if(puntero==NULL){
		printf("No hay suficiente memoria");
		exit(1);
	}else{
		for(int i=0;i<cantidad;i++){
			scanf(" %c",&letras);
			*(puntero+i)=letras;
		}
	}
	mostrar(puntero,cantidad);
	printf("Ingrese los nuevos valores que desea agregar: \n");
	scanf("%d",&nuevacant);
	puntero=(char *)realloc(puntero, cantidad+nuevacant *sizeof(int));
	printf("Ingrese las nuevas letras\n");
	if(puntero==NULL){
		printf("No hay suficiente memoria");
		exit(1);
	}else{
		for(int i=0;i<nuevacant;i++){
			scanf(" %c",&letras);
			*(puntero+i
			  )=letras;
		}
	}
	mostrar(puntero,nuevacant);
	free(puntero);
	return 0;
}
void mostrar(char *p,int c){
	printf("Los nuevos valores ingresados son: \n");
	for(int i=0;i<c;i++){
		printf(" %c\t",*(p+i));
	}
	
	
	
}
