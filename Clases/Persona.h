#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Persona {
private:
	string nombre; //atributos
	int edad;
public:
	Persona(); // constructor de objetos
	//funciones publicas que permiten asignar o leer los datos del objeto
	void setNombre(string nom); 
	string getNombre();
	void setEdad(int ed);
	float getEdad();
	string toString();
};

#endif //PERSONA_H

