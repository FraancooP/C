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
	
	//carga de datos
	cout<<"--------------------------------------------------";
	cout<<"\nCARGAR LISTADO\n";
	cout<<"Ingrese su nombre: ";
	cin>>nom;
	p.setNombre(nom); //asigna el valor recien ingresado al atributo privado de nombre de la clase Persona.
	
	cout<<"Ingrese su edad: ";
	cin>>ed;
	p.setEdad(ed); 
	
	//muestra los datos
	cout<<"--------------------------------------------------";
	cout<<"\nDATOS DE PERSONA\nNombre\t\tEdad\n";
	cout<<p.getNombre()<<"\t\t"<<p.getEdad(); //obtenemos los valores del objeto con los metodos get() de la clase Persona
	cout<<"\n--------------------------------------------------";
	
	return 0;
}

