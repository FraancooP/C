/*Cree un programa que permita reservar memoria para n caracteres (char). 
Luego cargar los n caracteres e imprimirlos por pantalla. El usuario desea agregar mas caracteres,
por lo que ingresa la n cantidad de caracteres a agregar. Luego cargar los n caracteres,
imprimirlos y finalmente liberar la memoria.*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
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
	for(int i=0;i<cantidad;i++){
		printf("%c\t",*(puntero+i));
	}
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
	for(int i=0;i<nuevacant;i++){
		printf("%c\t",*(puntero+i));
	}
	free(puntero);
	return 0;
}