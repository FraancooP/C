#ifndef FECHA_H
#define FECHA_H

using namespace std;

//SECCION DE DECLARACION DE CLASE
class Fecha{
private:
	int mes;
	int dia;
	int anio;
public:
	Fecha(); //constructor por defecto
	Fecha(int, int, int); //otro constructor que se crea con datos
	void setFecha(int, int, int);
	void printFecha(void);
	~Fecha(); //destructor
};

//SECCION DE IMPLEMENTACION DE CLASE
Fecha::Fecha(){
	cout<<"Se creo un objeto nuevo, sin datos."<<endl;
}

Fecha::Fecha(int d, int m, int a){
	mes=m;
	dia=d;
	anio=a;
	cout<<"Se creo un objeto nuevo, con datos "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

void Fecha::setFecha(int d, int m, int a){
	mes=m;
	dia=d;
	anio=a;
}

void Fecha::printFecha(){
	cout<<"La fecha es "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

Fecha::~Fecha(){
	cout<<"Ejecutando el destructor."<<endl;
}

#endif
