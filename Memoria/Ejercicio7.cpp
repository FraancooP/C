/*Crear un programa que pregunte al usuario cuántos caracteres desea introducir, 
reserve espacio para dicho número de caracteres, le permita al usuario introducirlos desde teclado y
 luego mostrar por pantalla los valores. Luego, el programa pregunta cuántos caracteres desea agregar a 
 la lista de elementos ya introducida, agrega espacio de memoria y solicita el ingreso de los nuevos valores. 
 Por último, mostrar la lista resultante. Utilizar funciones.*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void cargar(int *,int,int);
void carga_nuevo(int *,int,int,int);
void total(int *,int);
int main(int argc, char *argv[]) {
	int cantidad=0, numeros=0, nuevacanto=0,tot=0;
	char op=' ';
	int *puntero=NULL;
	printf("Ingrese la cantidad de elementos ENTEROS que desea cargar.\n");
	scanf("%d",&cantidad);
	puntero=(int *)malloc(cantidad*sizeof(int));
	if(puntero==NULL){
		printf("No hay memoria suficiente para ingresar esa cantidad de elementos.\n");
		exit(1);
	}else{
		cargar(puntero,cantidad,numeros);
	}
	printf("¿Desea cargar mas valores?S/N\n");
	scanf(" %c",&op);
	if(op=='s'){
		printf("¿Cuantos valores mas desea añadir?");
		scanf("%d",&nuevacanto);
		carga_nuevo(puntero,cantidad,nuevacanto,numeros);
	}
	printf("Todos los valores totales son: \n");
	
	free(puntero);
	return 0;
}
void cargar(int *p,int c,int n){
	printf("Ingrese los numeros: \n");
	for(int i=0;i<c;i++){
		scanf("%d", &n);
		*(p+i)=n;
	}
	printf("Los valores son: \n");
	for(int i=0;i<c;i++){
		printf("%d",*(p+i));
	}
}
void carga_nuevo(int *p,int c,int cn,int n){
	//p=(char *)realloc(p, c+cn *sizeof(int));
	printf("Ingrese los nuevos numeros: \n");
	for(int i=0;i<c;i++){
		scanf("%d", &n);
		*(p+i)=n;
	}
	printf("Los nuevos valores son: \n");
	for(int i=0;i<c;i++){
		printf("%d",*(p+i));
	}
}
