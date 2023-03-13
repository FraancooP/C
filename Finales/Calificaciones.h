#include <iostream>
#include <cstring>
using namespace std;
class Calificaciones{
private:
	string nombre_alumno;
	int nota_1;
	int nota_2;
	int nota_3;
	int recuperatorio;
	float promedio;
	string resultado;
public:
	Calificaciones();
	Calificaciones(string,int,int,int,int,float,string);
	void setNombre_alumno(string nomb);
	string getNombre_alumno();
	void setNota_1(int nota1);
	int getNota_1();
	void setNota_2(int nota2);
	int getNota_2();
	void setNota_3(int nota3);
	int getNota_3();
	void setRecuperatorio(int recu);
	int getRecuperatorio();
	void setPromedio(float prom);
	float getPromedio();
	void setResultado(string resul);
	string getResultado();
	string toString;
	~Calificaciones();
};
Calificaciones :: Calificaciones(){
	
}
Calificaciones :: Calificaciones(string nom,int n1,int n2,int n3,int rec,float pro,string resu){
	nombre_alumno=nom;
	nota_1=n1;
	nota_2=n2;
	nota_3=n3;
	recuperatorio=rec;
	promedio=pro;
	resultado=resu;			
}
void Calificaciones::setNombre_alumno(string nomb){
	nombre_alumno=nomb;
}
string Calificaciones::getNombre_alumno(){
	return nombre_alumno;
}
void Calificaciones::setNota_1(int nota1){
	nota_1=nota1;
}
int Calificaciones::getNota_1(){
	return nota_1;
}
void Calificaciones::setNota_2(int nota2){
	nota_2=nota2;
}
int Calificaciones::getNota_2(){
	return nota_2;
}
void Calificaciones::setNota_3(int nota3){
	nota_3=nota3;
}
int Calificaciones::getNota_3(){
	return nota_3;
}
void Calificaciones :: setRecuperatorio(int recu){
	recuperatorio=recu;
}
int Calificaciones :: getRecuperatorio(){
	return recuperatorio;
}
void Calificaciones :: setPromedio(float pro){
	promedio=pro;
}
float Calificaciones :: getPromedio(){
	return promedio;
}
void Calificaciones :: setResultado(string resul){
	resultado=resul;
}
string Calificaciones :: getResultado(){
	return resultado;
}
string Calificaciones :: toString(){
	string cadena="Nombre Alumno "+ nombre_alumno+" nota1 "+std::to_string(nota1)+" nota2 "+std::to_string(nota2)+" nota3 "+std::to_string(nota3)+" recuperatorio "+std::to_string(recuperatorio)+" promedio "+std::to_string(promedio)+" resultado"+resultado;
	return cadena;
}
Calificaciones :: ~Calificaciones(){
	cout<<"destruyendo"<<endl;
}
