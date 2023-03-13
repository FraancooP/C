#include <iostream>
#include "Fecha.h"
using namespace std;

int main(int argc, char *argv[]) {
	int dia=0, mes=0, anio=0;
	
	//creamos una instancia de la clase (es decir creamos un objeto)
	//con el constructor con datos
	printf("-----------------------------------------------\n");
	Fecha f1(20,10,2022); 
	f1.printFecha();
	printf("-----------------------------------------------\n");
	//creamos una instancia de la clase (es decir creamos un objeto)
	//con el constructor sin datos (por defecto)
	Fecha f2 = Fecha();
	//Solicitamos los datos por teclado
	printf("Ingrese la fecha:\nDia: ");
	scanf("%d", &dia);
	printf("Mes: ");
	scanf("%d", &mes);
	printf("Año: ");
	scanf("%d", &anio);
	f2.setFecha(dia, mes, anio); //seteamos los datos en el objeto
	f2.printFecha();
	printf("-----------------------------------------------\n");
	return 0;
}

