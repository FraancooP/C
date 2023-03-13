/*Crear un programa que pregunte al usuario cuántos caracteres desea introducir, 
reserve espacio para dicho número de caracteres, le permita al usuario introducirlos desde teclado. 
Por último se los muestre todos seguidos y en el orden inverso al que fueron introducidos. 
Crear funciones para cargar, mostrar en orden y mostrar en orden inverso. Utilizar funciones.*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void cargar(int *,int,int);
void mostrar_orden(int *,int);
void mostrar_inverso(int *,int);
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
		cargar(puntero,cantidad,numeros);
		mostrar_orden(puntero,cantidad);
		mostrar_inverso(puntero,cantidad);
	}
	free(puntero);
	return 0;
}
void cargar(int *p,int c,int n){
	printf("Ingrese los numeros: \n");
	for(int i=0;i<c;i++){
		scanf("%d", &n);
		*(p+i)=n;
	}
}
void mostrar_orden(int *p,int c){
	printf("Los valores en orden son: \n");
	for(int i=0;i<c;i++){
		printf("%d\t",*(p+i));
	}
}
void mostrar_inverso(int *p,int c){
	printf("\n Los valores en inverso son: \n");
	for(int i=c;i!=0;i--){
		 printf("%d\t",*(p+i-1));
		}
}
