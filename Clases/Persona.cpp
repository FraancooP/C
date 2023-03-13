#include "Persona.h"

//desarrollo de las funciones de la clase.
Persona::Persona() { //es el contructor por defecto
}

void Persona::setNombre(string nom) {
	nombre = nom; }
string Persona::getNombre() {
	return nombre; }

void Persona::setEdad(int ed) {
	edad = ed;}
int Persona::getEdad() {
	return edad; }

string Persona::toString(){
	string cadena=nombre+"\t\t"+std::to_string(edad);
	return cadena;
}
