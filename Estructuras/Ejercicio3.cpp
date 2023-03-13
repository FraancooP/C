/*Crear un programa que gestione el listado de los empleados de la empresa. 
Para ello crear una estructura Empleado, en la cual contenga los siguientes datos: 
legajo, puesto de trabajo, sueldo y anios_antiguedad. 
Luego, crear un vector de estructuras del tipo empleado de tamaño 3. Crear un menú que permita las opciones: 
a. agregar un empleado
b. mostrar todos los empleados
c. buscar un empleado por legajo para ver si existe o no.
d. actualizarSueldo(float porcentaje)
e. ordenar por sueldo
f. ordenar por anios_antiguedad*/
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
struct empleado
{
	long legajo;
	string puesto_trabajo;
	long sueldo;
	long antiguedad;
};
void cargar_empleados(empleado[3]);
void mostrar_empleados(empleado[3]);
void buscar_empleado(empleado[3]);
void actualizar_sueldo(empleado[3]);
int main(int argc, char *argv[]) {
	struct empleado e[3];
	char op=' ',cass=' ';
	do{
		printf("Seleccione una opcion.\n");
		printf("A)Cargar empleados.\n");
		printf("B)Mostrar todos los empleados.\n");
		printf("C)Buscar empleado por legajo.\n");
		printf("D)Actualizar sueldo.\n");
		printf("E)Ordenar por sueldo.\n");
		printf("F)Ordenar por antiguedad.\n");
		cin>>cass;
		switch(cass){
		case 'a':
		case 'A':
			cargar_empleados(e);
			break;
		case 'b':
		case 'B':
			mostrar_empleados(e);
			break;
		case 'c':
		case 'C':
			buscar_empleado(e);
			break;
		case 'd':
		case 'D':
		actualizar_sueldo(e);
			break;
		case 'e':
		case 'E':
			
			
			break;
		case 'f':
		case 'F':
			
			
			break;
		}
		printf("¿Desea continuar?S/N\n");
		scanf(" %c",&op);
	}while(op=='s');
	return 0;
}
void cargar_empleados(empleado e[3]){
	for(int i=0;i<3;i++){
		cout<<"Ingrese el numero del empleado."<<endl;
		cin>>e[i].legajo;
		cout<<"Ingrese su Puesto(Jefe/Operario/Encargado)."<<endl;
		cin>>e[i].puesto_trabajo;
		if(e[i].puesto_trabajo=="Jefe"){
			e[i].sueldo=30000;
		}else{
			if(e[i].puesto_trabajo=="Operario"){
				e[i].sueldo=20000;
			}else{
				if(e[i].puesto_trabajo=="Encargado"){
					e[i].sueldo=10000;
				}
			}
		}
		cout<<"Ingrese su antiguedad."<<endl;
		cin>>e[i].antiguedad;
	}
}
void mostrar_empleados(empleado e[3]){
	for(int i=0;i<3;i++){
		cout<<"Leajo de empleado: "<<e[i].legajo<<"\t"<<endl;
		cout<<"Puesto de empleado: "<<e[i].puesto_trabajo<<"\t"<<endl;
		cout<<"Sueldo de empleados: "<<e[i].sueldo<<"\t"<<endl;
		cout<<"Antiguedad de empleado: "<<e[i].antiguedad<<"\t"<<endl;
	}
}
void buscar_empleado(empleado e[3]){
	long legajo_buscar=0;
	cout<<"Ingrese el leajo que desea buscar."<<endl;
	cin>>legajo_buscar;
	for(int i=0; i<3; i++){
		if(legajo_buscar==e[i].legajo){
			cout<<"Empleado encontrado. ";
			cout<<"\nLegajo: "<<e[i].legajo<<"\n";
			cout<<"\nPuesto: "<<e[i].puesto_trabajo<<"\n";
			cout<<"\nSueldo: "<<e[i].sueldo<<"\n";
			cout<<"\nAntiguedad: "<<e[i].antiguedad<<"\n";
		}
	}
}
void actualizar_sueldo(empleado e[3]){
	printf("¿Que sueldo desea actualizar?\n");
}