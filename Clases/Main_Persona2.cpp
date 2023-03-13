#include <iostream>
#include <string>
//se agrega la libreria para poder crear objetos de esta clase.
#include "Persona.h" 
#include "Persona.cpp"

using namespace std;

int main(int argc, char *argv[]) {
	Persona p;  //p es una instancia de la clase Persona.
	string nom=" ";
	int ed=0;
	
	Persona listaPersona[3]; //se crea un vector de objetos de Persona
	
	//carga de datos
	cout<<"--------------------------------------------------";
	cout<<"\nCARGAR LISTADO";
	for(int i=0;i<3;i++){
		cout<<"\nPersona "<<i+1<<"\nNombre: ";
		getline(cin,nom,'.');
		p.setNombre(nom);
		cout<<"Edad: ";
		cin>>ed;
		p.setEdad(ed);
		listaPersona[i]=p;
	}
	
	//muestra los datos
	cout<<"--------------------------------------------------";
	cout<<"\nLISTADO DE PERSONAS\nNombre\t\tEdad\n";
	for(int i=0;i<3;i++){
		Persona p=listaPersona[i];
		cout<<p.toString(); //utiliza el metodo de la clase Persona
	}
	cout<<"\n--------------------------------------------------";
	
	return 0;
}
