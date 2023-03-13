/*Cree un programa que permita reservar memoria para n valores enteros. 
Luego cargar los n valores, imprimirlos y liberar la memoria.*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	int cantidad=0, numeros=0;
	int *puntero=NULL;
	printf("Ingrese la cantidad de elementos ENTEROS que desea cargar.\n");
	scanf("%d",&cantidad);
	puntero=(int *)malloc(cantidad*sizeof(int));
	if(puntero==NULL){
		printf("No hay memoria suficiente para ingresar esa cantidad de elementos.\n");
		exit(1);
	}else{
		printf("Ingrese los numeros: \n");
		for(int i=0;i<cantidad;i++){
			scanf("%d", &numeros);
			*(puntero+i)=numeros;
		}
		printf("Los valores ingresados son: \n");
		for(int i=0;i<cantidad;i++){
			printf("%d\t",*(puntero+i));
		}
		printf("Sus direcciones de memoria son: \n");
		for(int i=0;i<cantidad;i++){
			printf("%d\t",(puntero+i));
		}
	}
	free(puntero);
	return 0;
}
