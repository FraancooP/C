#include "Mascota.h"
#include <string>
#include <iostream>

using namespace std;

void mostrarListado(Mascota [3]);
void mostrarListadoPorTipo(Mascota [3]);

int main(){
	Mascota m;
	
	int tipo_animal; 
	string raza;
	string nombre_mascota;
	string persona_responsable;
	int edad;
	
	Mascota listaMascota[3];
	
	for(int i=0;i<3;i++){
		cout<<"Ingrese tipo de animal [1. Perro  2. Gato]: ";
		cin>>tipo_animal;
		m.setTipo_animal(tipo_animal);
		
		cout<<"Ingrese raza: ";
		cin>>raza;
		m.setRaza(raza);
		
		cout<<"Ingrese nombre mascota: ";
		cin>>nombre_mascota;
		m.setNombre_mascota(nombre_mascota);
		
		cout<<"Ingrese persona responsable: ";
		cin>>persona_responsable;
		m.setPersona_responsable(persona_responsable);
		
		cout<<"Ingrese edad: ";
		cin>>edad;
		m.setEdad(edad);
		
		listaMascota[i]=m;
	}
	mostrarListado(listaMascota);
	mostrarListadoPorTipo(listaMascota);
	
	return 0;
}
	
void mostrarListado(Mascota listaMascota[3]){
	cout<<"Listado de Mascotas \n";
	cout<<"Tipo\tRaza\tNom. M.\tRespo.\tEdad"<<endl;
	for(int i=0;i<3;i++){
		Mascota m=listaMascota[i];
		cout<<m.toString()<<endl;
	}
	cout<<"\n";
}
	
void mostrarListadoPorTipo(Mascota listaMascota[3]){
	int tipo_animal=0;
	cout<<"Ingrese el tipo de animal: \n1. Perro \n2. Gato \n";
	cin>>tipo_animal;
	
	cout<<"Tipo\tRaza\tNom. M.\tRespo.\tEdad"<<endl;
	for(int i=0;i<3;i++){
		Mascota m=listaMascota[i];
		if(tipo_animal==m.getTipo_animal())
			cout<<m.toString()<<endl;
	}
	cout<<"\n";
}
