/*Crear una clase Libro con sus atributos (a elección) y métodos (setter(),
getter(), toString()). Luego, crear una clase Principal en donde se declare
un vector de objetos Libro. Luego llenar este vector con datos y llamar
a las  funciones mostrarListado y calcularSumaPrecio. Hacer el diagrama
de clase de Libro.*/
#include <iostream>
#include "Libro.h"
#include <cstring>
using namespace std;
void mostrar(Libro [5]);
void calcularSumaPrecio(Libro [5]);
int main(int argc, char *argv[]) {
	Libro libro1;
	Libro libro2;
	Libro libro3;
	Libro libro4;
	Libro libro5;
	Libro lista[5];
	
	libro1.setNombre("El_asesino");
	libro1.setPaginas(350);
	libro1.setAutor("Jorgue_Oscar");
	libro1.setTipo("Suspenso");
	libro1.setValor(500);
	lista[0]=libro1;
	
	libro2.setNombre("Interestelar");
	libro2.setPaginas(500);
	libro2.setAutor("Anderson_Met");
	libro2.setTipo("Ciencia_Ficcion");
	libro2.setValor(375);
	lista[1]=libro2;
	
	libro3.setNombre("Metro");
	libro3.setPaginas(455);
	libro3.setAutor("Dimitry_vorskman");
	libro3.setTipo("Fantasia");
	libro3.setValor(1250);
	lista[2]=libro3;
	
	libro4.setNombre("Soy_leyenda");
	libro4.setPaginas(120);
	libro4.setAutor("Leonel_villaba");
	libro4.setTipo("Apocalipsis");
	libro4.setValor(780);
	lista[3]=libro4;
	
	libro5.setNombre("El_cantante");
	libro5.setPaginas(378);
	libro5.setAutor("Joaquin");
	libro5.setTipo("Arte");
	libro5.setValor(654);
	lista[4]=libro5;
	mostrar(lista);
	calcularSumaPrecio(lista);
	return 0;
}
void mostrar(Libro lista_libros[5]){
	cout<<"Libros disponibles para comprar: \n";
	for(int i=0;i<5;i++){
		Libro v=lista_libros[i];
		cout<<v.toString()<<endl;
	}
	cout<<"\n";
}
void calcularSumaPrecio(Libro lista_libros[5]){
	string libro_nombre=" ";
	int cant=0,total=0;
	cout<<"Que libro desea llevar?"<<endl;
	cin>>libro_nombre;
	cout<<"\n";
	for(int i=0;i<5;i++){
		Libro v=lista_libros[i];
		if(lista_libros[i].getNombre().compare(libro_nombre)==0){
			cout<<"El libro que usted desea: \n";
			cout<<v.toString()<<endl;
			cout<<"Cuantos desea llevar?\n";
			cin>>cant;
			total=cant*(lista_libros[i].getValor());
		}
	}
	cout<<"\n";
	cout<<"El total a pagar los "<<cant<<" libros es de:$ "<<total<<endl;
}
