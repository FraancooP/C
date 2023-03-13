#include <iostream>
#include <cstring>

using namespace std;

class Libro {
private:
	string titulo; //atributos
	string autor;
	float precio;
	
public:
	Libro(); // constructor de objetos
	//funciones publicas que permiten asignar o leer los datos del objeto
	void setTitulo(string tit); 
	string getTitulo();
	void setAutor(string au); 
	string getAutor();
	void setPrecio(float pre);
	float getPrecio();
	string toString();
};
//desarrollo de las funciones de la clase.
Libro::Libro() { //es el contructor por defecto
}

void Libro::setTitulo(string tit) {
	titulo = tit; }
string Libro::getTitulo() {
	return titulo; }

void Libro::setAutor(string au) {
	autor = au; }
string Libro::getAutor() {
	return autor; }

void Libro::setPrecio(float pre) {
	precio = pre;}
float Libro::getPrecio() {
	return precio; }

string Libro::toString(){
	string cadena="Titulo: "+titulo+" Autor: "+autor+" Precio: $"+std::to_string(precio);
	return cadena;
}
