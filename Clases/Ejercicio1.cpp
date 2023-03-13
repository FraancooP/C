#include <iostream>
#include "Vehiculo.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void mostrar(Vehiculo [2]);
void buscar(Vehiculo [2]);
void checkear_null(FILE *fp);
int main(int argc, char *argv[]) {
	//FILE *fp=NULL;
	//fp=fopen("datos_vehiculos.txt","w");
	//checkear_null(fp);
	
	
	//fclose(fp);
	Vehiculo objeto1;
	Vehiculo objeto2;
	Vehiculo lista[2];
	objeto1.setTipo("Auto");
	objeto1.setCapacidad(5);
	objeto1.setPatente("12345");
	objeto1.setColor("Amarillo");
	lista[0]=objeto1;
	
	objeto2.setTipo("Moto");
	objeto2.setCapacidad(2);
	objeto2.setPatente("678910");
	objeto2.setColor("Verde");
	lista[1]=objeto2;
	//GUARDADO DE DATOS.
//	fprintf(fp,"%s\n%d\n%s\n%s\n",&objeto1.setTipo,&objeto1.setCapacidad,&objeto1.setPatente,&objeto1.setColor);
	//fclose(fp);
	mostrar(lista);
	buscar(lista);
	
	
	
	//MOSTRAR LOS DATOS.
	/*fp=fopen("datos_personales.txt","r");
	checkear_null(fp);
	while (!feof(fp))
	{
		fscanf(fp,"%s\n%d\n%s\n%s\n",&objeto1.getTipo, &objeto1.getCapacidad, &objeto1.getPatente, &objeto1.getColor);
		printf("%s\n%d\n%s\n%s\n",objeto1.getTipo,objeto1.getCapacidad, objeto1.getPatente, objeto1.getColor);
	}*/
	return 0;
}
void mostrar(Vehiculo lista[2]){
	cout<<"Lista de Vehiculos registrados: \n";
	for(int i=0;i<2;i++){
		Vehiculo v=lista[i];
		cout<<v.toString()<<endl;
	}
	cout<<"\n";
}
void buscar(Vehiculo lista[2]){
	string patente=" ";
	cout<<"Ingrese la patente del Vehiculo a buscar: "<<endl;
	cin>>patente;
	cout<<"\n";
	for(int i=0;i<2;i++){
		Vehiculo v=lista[i];
		if(lista[i].getPatente().compare(patente)==0){
			cout<<v.toString()<<endl;
		}
	}
	cout<<"\n";
}/*
void checkear_null(FILE *fp){
	if(fp==NULL){
		printf("Imposible abrir el archivo.");
		exit(1);
	}
*/
