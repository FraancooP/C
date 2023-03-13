/*Ampliar el programa del ejercicio anterior, para que almacene datos de hasta 3 canciones en un vector de estructura. 
Luego crear un menú que permita las opciones (cada una es una función): 
a. agregar una nueva canción
b. mostrar todas las canciones
c. buscar una canción por titulo*/
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
struct cancion
{
	string artista;
	string titulo;
	long dura;
	long memor;
};
void cargar_cancion(cancion [3]);
void mostrar_canciones(cancion [3]);
void buscar_cancion(cancion [3]);
int main(int argc, char *argv[]) {
	struct cancion c[3];
	char op=' ',cass=' ';
	do{
		cout<<"Ingrese una de las siguientes opciones: \n";
		cout<<"A)Cargar una nueva cancion.\n";
		cout<<"B)Mostrar todas las canciones.\n";
		cout<<"C)Buscar una cancion por titulo.\n";
		scanf(" %c",&cass);
		switch(cass){
		case 'a':
		case 'A':
			cargar_cancion(c);
			break;
		case 'b':
		case 'B':
			mostrar_canciones(c);
			break;
		case 'c':
		case 'C':
			buscar_cancion(c);
			break;
		}
		cout<<"¿Desea elejir otra opcion?S/N";
		scanf(" %c",&op);
	}while(op=='s' && 'S');
	return 0;
}
void cargar_cancion(cancion c[3]){
	for(int i=0;i<3;i++){
	cout<<"Ingrese los datos de la cancion(finalizar con (.)): \n";
	cout<<"Artista: \n";
	cin>>c[i].artista;
	cout<<"Titulo: \n";
	cin>>c[i].titulo;
	cout<<"Duracion de la cancion(minutos): \n";
	cin>>c[i].dura;
	cout<<"Peso de la cancion en KB: \n";
	cin>>c[i].memor;
	}
}
void mostrar_canciones(cancion c[3]){
	for(int i=0;i<3;i++){
		cout<<"Datos ingresados: \n";
		cout<<"Artista: \n"<<c[i].artista<<"\n";
		cout<<"Titulo: \n"<<c[i].titulo<<"\n";
		cout<<"Duracion: \n"<<c[i].dura<<"\n";
		cout<<"Memoria: \n"<<c[i].memor<<"\n";
	}
}
void buscar_cancion(cancion c[3]){
	string buscar_titulo=" ";
	cout<<"INGRESE EL TITULO DE LA CANCION A BUSCAR: "<<endl;
	cin>>buscar_titulo;
	for(int i=0; i<3; i++){
		if(buscar_titulo.compare(c[i].titulo)==0){
			cout<<"Titulo de cancion encontrado. ";
			cout<<"\nArtista: "<<c[i].artista<<"\n";
			cout<<"\nTitulo: "<<c[i].titulo<<"\n";
			cout<<"\nDuracion: "<<c[i].dura<<"\n";
			cout<<"\nTamaño: "<<c[i].memor<<"\n";
		}
	}
}
