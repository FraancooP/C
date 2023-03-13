#include "Vehiculo.h"
#include <cstring>
#include <iostream>

using namespace std;

void mostrarListado(Vehiculo [2]);
void buscarPorPatente(Vehiculo [2]);

int main(){
	
	Vehiculo objeto1;
	Vehiculo objeto2;
	
	Vehiculo listaVehiculo[2]; //creamos un vector de objetos de Vehiculo

	//Setea los datos
	objeto1.setTipo("auto");
	objeto1.setCapacidad(5);
	objeto1.setPatente("123");
	objeto1.setColor("rojo");
	listaVehiculo[0]=objeto1;
	
	objeto2.setTipo("moto");
	objeto2.setCapacidad(2);
	objeto2.setPatente("456");
	objeto2.setColor("verde");
	listaVehiculo[1]=objeto2;
	
	
	mostrarListado(listaVehiculo);
	buscarPorPatente(listaVehiculo);
	return 0;
}
	
	
void mostrarListado(Vehiculo listaVehiculo[2]){
	cout<<"Listado de vehiculos \n";
	for(int i=0;i<2;i++){
		Vehiculo v=listaVehiculo[i];
		cout<<v.toString()<<endl;
	}
	cout<<"\n";
}
	
void buscarPorPatente(Vehiculo listaVehiculo[2]){
	string patente=" ";
	cout<<"Ingrese la patente del vehiculo a buscar: ";
	cin>>patente;
	cout<<"\n";
	for(int i=0;i<2;i++){
		Vehiculo v=listaVehiculo[i];
		if(listaVehiculo[i].getPatente().compare(patente)==0){
			cout<<v.toString()<<endl;
		}
	}
	cout<<"\n";
}
