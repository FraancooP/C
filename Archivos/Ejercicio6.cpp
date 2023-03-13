/*Escribir un programa que solicite los datos de un producto 
(nombre del producto, marca, precio unitario, fecha de elaboración, tamaño)
y lo guarde en un archivo de texto con el nombre “Datos_Producto.txt”.*/
//CON FSTREAM

#include <iostream>
#include <fstream> 

using namespace std;

int main(int argc, char *argv[]) {
	string lista="";
	
	ofstream ofs; //creo la libreria ofstream
	ofs.open("Datos_Producto.txt"); //Abro un archivo, sino existe se crea.
	//Ingreso por teclado
	cout<<"nombre del producto/ marca/ precio unitario($)/ fecha de elaboración(00-00-00)/ tamaño(cm): [fin = '.']"<<endl;   
	getline(cin, lista, '.');
	
	//Escribir el archivo con el mensaje
	ofs <<"Mensaje: "<<endl; 
	ofs<<lista<<endl;
	ofs.close();  //Cierra
	
	//Leer 
	lista=" ";
	ifstream ifs; //objeto libreria ifstream
	ifs.open("Datos_Producto.txt"); //abrir
	cout << "\nContenido del Archivo"<<endl;
	while(!ifs.eof()) { //recorre el bucle
		getline(ifs,lista); //saca el mensaje
		cout<<lista<<endl; //lo muestra en pantalla
	}
	ifs.close(); //Cierra
	return 0;
}
