/*Escriba un programa que cree un archivo binario llamado "datos_personales.txt� 
que pregunte los siguientes datos personales: nombre, apellido, dni, edad, nacionalidad.
Luego abrir el archivo y mostrarlo.*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void checkear_null(FILE *fp);
int main(int argc, char *argv[]) {
	FILE *fp=NULL;
	char nombre[30];
	char apellido[30];
	int dni=0;
	int edad=0;
	char nacionalidad[30];
	fp=fopen("datos_personales.txt","w");
	checkear_null(fp);
	printf("Porfavor Escriba los siguientes datos:\n");
	    printf("Nombre: \n");
		scanf(" %s", &nombre);
		printf("Apellido: ");
		scanf(" %s", &apellido);
		printf("DNI: \n");
		scanf(" %d", &dni);
		printf("EDAD: ");
		scanf(" %d", &edad);
		printf("Nacionalidad: ");
		scanf(" %s", &nacionalidad);
		//GUARDAR DATOS:
	fprintf(fp,"%s\n%s\n%d\n%d\n%s\n", nombre, apellido, dni, edad, nacionalidad);
	fclose(fp);
	fp=fopen("datos_personales.txt","r");
	checkear_null(fp);
	while (!feof(fp))
	{
		fscanf(fp,"%s\n%s\n%d\n%d\n%s\n", &nombre, &apellido, &dni, &edad, &nacionalidad);
		printf("%s\n%s\n%d\n%d\n%s\n", nombre, apellido, dni, edad, nacionalidad);
	}
	fclose(fp);
	return 0;
}
void checkear_null(FILE *fp){
	if(fp==NULL){
		printf("Imposible abrir el archivo.");
		exit(1);
	}
}
