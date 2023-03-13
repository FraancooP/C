/*Cree un programa que permita reservar memoria para n valores decimales (float).
 Luego cargar los n valores, imprimirlos y liberar la memoria.*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	float cantidad=0.0f, numeros=0.0f;
	float *p=NULL;
	printf("Ingrese la cantidad de valores que desea cargar: \n");
	scanf("%f",&cantidad);
	p=(float *)malloc(cantidad*sizeof(float));
	if(p==NULL){
		printf("No hay suficiente memoria.\n");
		exit(1);
	}else{
		printf("Ingrese los numeros: \n");
		for(int i=0;i<cantidad;i++){
			scanf("%f", &numeros);
			*(p+i)=numeros;
		}
		printf("Los numeros ingresados son: \n");
			for(int i=0;i<cantidad;i++){
				printf("%f\t",*(p+i));
			}
	}
	free(p);
	return 0;
}
