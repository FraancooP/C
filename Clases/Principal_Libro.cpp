#include "Libro.h"
#include <string>
#include <iostream>

using namespace std;

void mostrarListado(Libro [3]);
float calcularSumaPrecio(Libro [3]);

int main(){
	Libro l;
	string titulo;
	string autor;
	float precio;
	
	Libro listaLibro[3];
	for(int i=0;i<3;i++){
		cout<<"Ingrese titulo: ";
		getline(cin,titulo,'.');
		l.setTitulo(titulo);
		
		cout<<"Ingrese autor: ";
		getline(cin,autor,'.');
		l.setAutor(autor);

		cout<<"Ingrese precio: ";
		cin>>precio;
		l.setPrecio(precio);
		listaLibro[i]=l;
	}
	mostrarListado(listaLibro);
	cout<<"La suma total es: "<<calcularSumaPrecio(listaLibro);
	
	return 0;
}

void mostrarListado(Libro listaLibro[3]){
	cout<<"Listado de libros \n";
	for(int i=0;i<3;i++){
		Libro l=listaLibro[i];
		cout<<l.toString()<<endl;
	}
	cout<<"\n";
}
float calcularSumaPrecio(Libro listaLibro[3]){
	float suma=0;
	for(int i=0;i<3;i++){
		Libro l=listaLibro[i];
		suma=suma+l.getPrecio();
	}
	return suma;
}
