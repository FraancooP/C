#include <iostream>
#include <cstring>

using namespace std;

class Mascota {
private:
	int tipo_animal; //atributos
	string raza;
	string nombre_mascota;
	string persona_responsable;
	int edad;
	
public:
	Mascota(); // constructor de objetos
	//funciones publicas que permiten asignar o leer los datos del objeto
	void setTipo_animal(int tipo); 
	int getTipo_animal();
	void setRaza(string raz); 
	string getRaza();
	void setNombre_mascota(string nom_mas); 
	string getNombre_mascota();
	void setPersona_responsable(string per_res); 
	string getPersona_responsable();
	void setEdad(int ed);
	float getEdad();
	string toString();
};
//desarrollo de las funciones de la clase.
Mascota::Mascota() { //es el contructor por defecto
}

void Mascota::setTipo_animal(int tipo) {
	tipo_animal = tipo; }
int Mascota::getTipo_animal() {
	return tipo_animal; }

void Mascota::setRaza(string raz) {
	raza= raz; }
string Mascota::getRaza() {
	return raza; }

void Mascota::setNombre_mascota(string nom_mas) {
	nombre_mascota= nom_mas; }
string Mascota::getNombre_mascota() {
	return nombre_mascota; }

void Mascota::setPersona_responsable(string per_res) {
	persona_responsable= per_res; }
string Mascota::getPersona_responsable() {
	return persona_responsable; }

void Mascota::setEdad(int ed) {
	edad = ed;}
float Mascota::getEdad() {
	return edad; }

string Mascota::toString(){
	string cadena=std::to_string(tipo_animal)+
		"\t"+raza+
		"\t"+nombre_mascota+
		"\t"+persona_responsable+
		"\t"+std::to_string(edad);
	return cadena;
}
