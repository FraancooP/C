#include <iostream>
#include <string>
//se agrega la libreria para poder crear objetos de esta clase.
#include "Persona.h" 
#include "Persona.cpp"

using namespace std;

void cargarListado(Persona [3]);
void mostrarListado(Persona [3]);

int main(){
	
	Persona listaPersona[3]; //se crea un vector de objetos de Persona
	
	//llamada de funciones
	cargarListado(listaPersona);
	mostrarListado(listaPersona);
	cout<<"\n--------------------------------------------------";

	return 0;
}
	
void cargarListado(Persona listaPersona[3]){
	Persona p; //p es una instancia de la clase Persona.
	string nombre=" ";
	int edad=0;
	cout<<"--------------------------------------------------";
	cout<<"\nCARGAR LISTADO";
	for(int i=0;i<3;i++){
		cout<<"\nPersona "<<i+1<<"\nNombre: ";
		getline(cin,nombre,'.');
		p.setNombre(nombre);
		cout<<"Edad: ";
		cin>>edad;
		p.setEdad(edad);
		listaPersona[i]=p;
	}
}
	
void mostrarListado(Persona listaPersona[3]){
	cout<<"--------------------------------------------------";
	cout<<"\nLISTADO DE PERSONAS\nNombre\t\tEdad\n";
	for(int i=0;i<3;i++){
		Persona p=listaPersona[i];
		cout<<p.toString(); //utiliza el metodo de la clase Persona
	}
}
			
