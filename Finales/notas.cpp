#include <iostream>
#include "Calificaciones.h"
#include <cstring>
#include <string.h>
#include <ctime>
using namespace std;
void mostrar(Calificaciones [5]);
void buscarAlumno(Calificaciones[5]);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	Calificaciones objeto1;
	Calificaciones objeto2;
	Calificaciones objeto3;
	Calificaciones objeto4;
	Calificaciones objeto5;
	Calificaciones lista[5];
	
	
	string nombresito;
	int notita1;
	int notita2;
	int notita3;
	int recuperatorito;
	float promedito;
	string resultadito;
	char opcion=' ';
	 
	cout<<"ingrese nombre"<<endl;
	cin>>nombresito;
	objeto1.setNommbre_alumno(nombresito);
	notita1=rand()%11;
	objeto1.setNota1(notita1);
	notita2=rand()%11;
	objeto1.setNota2(notita2);
	notita3=rand()%11;
	objeto1.setNota3(notita3);
	recuperatorito=-1;
	objeto1.setRecuperatorio(recuperatorito);
	promedito=(notita1+notita2+notita3)/3;
	objeto1.setPromedio(promedito);
	if(promedito>=6){
		resultadito="Aprobado";
		objeto1.setResultado(resultadito);
		
	}else{
		recuperatorito=rand()%11;
		objeto1.setRecuperatorio(recuperatorito);
		if(recuperatorito>=6){
			resultadito="Aprobado";
			objeto1.setResultado(resultadito);
			
		}else{
			if(recuperatorito<6){
				resultadito="Desaprobado";
				objeto1.setResultado(resultadito);
			}
		}
	}
	lista[0]=objeto1;
	
	cout<<"ingrese nombre"<<endl;
	cin>>nombresito;
	objeto2.setNommbre_alumno(nombresito);
	notita1=rand()%11;
	objeto2.setNota1(notita1);
	notita2=rand()%11;
	objeto2.setNota2(notita2);
	notita3=rand()%11;
	objeto2.setNota3(notita3);
	recuperatorito=-1;
	objeto2.setRecuperatorio(recuperatorito);
	promedito=(notita1+notita2+notita3)/3;
	objeto2.setPromedio(promedito);
	if(promedito>=6){
		resultadito="Aprobado";
		objeto2.setResultado(resultadito);
		
	}else{
		recuperatorito=rand()%11;
		objeto2.setRecuperatorio(recuperatorito);
		if(recuperatorito>=6){
			resultadito="Aprobado";
			objeto2.setResultado(resultadito);
			
		}else{
			if(recuperatorito<6){
				resultadito="Desaprobado";
				objeto2.setResultado(resultadito);
			}
		}
	}
	lista[1]=objeto2;
	
	cout<<"ingrese nombre"<<endl;
	cin>>nombresito;
	objeto3.setNommbre_alumno(nombresito);
	notita1=rand()%11;
	objeto3.setNota1(notita1);
	notita2=rand()%11;
	objeto3.setNota2(notita2);
	notita3=rand()%11;
	objeto3.setNota3(notita3);
	recuperatorito=-1;
	objeto3.setRecuperatorio(recuperatorito);
	promedito=(notita1+notita2+notita3)/3;
	objeto3.setPromedio(promedito);
	if(promedito>=6){
		resultadito="Aprobado";
		objeto3.setResultado(resultadito);
		
	}else{
		recuperatorito=rand()%11;
		objeto3.setRecuperatorio(recuperatorito);
		if(recuperatorito>=6){
			resultadito="Aprobado";
			objeto3.setResultado(resultadito);
			
		}else{
			if(recuperatorito<6){
				resultadito="Desaprobado";
				objeto3.setResultado(resultadito);
			}
		}
	}
	lista[2]=objeto3;
	
	cout<<"ingrese nombre"<<endl;
	cin>>nombresito;
	objeto4.setNommbre_alumno(nombresito);
	notita1=rand()%11;
	objeto4.setNota1(notita1);
	notita2=rand()%11;
	objeto4.setNota2(notita2);
	notita3=rand()%11;
	objeto4.setNota3(notita3);
	recuperatorito=-1;
	objeto4.setRecuperatorio(recuperatorito);
	promedito=(notita1+notita2+notita3)/3;
	objeto4.setPromedio(promedito);
	if(promedito>=6){
		resultadito="Aprobado";
		objeto4.setResultado(resultadito);
		
	}else{
		recuperatorito=rand()%11;
		objeto4.setRecuperatorio(recuperatorito);
		if(recuperatorito>=6){
			resultadito="Aprobado";
			objeto4.setResultado(resultadito);
			
		}else{
			if(recuperatorito<6){
				resultadito="Desaprobado";
				objeto4.setResultado(resultadito);
			}
		}
	}
	lista[3]=objeto4;
	
	cout<<"ingrese nombre"<<endl;
	cin>>nombresito;
	objeto5.setNommbre_alumno(nombresito);
	notita1=rand()%11;
	objeto5.setNota1(notita1);
	notita2=rand()%11;
	objeto5.setNota2(notita2);
	notita3=rand()%11;
	objeto5.setNota3(notita3);
	recuperatorito=-1;
	objeto5.setRecuperatorio(recuperatorito);
	promedito=(notita1+notita2+notita3)/3;
	objeto5.setPromedio(promedito);
	if(promedito>=6){
		resultadito="Aprobado";
		objeto5.setResultado(resultadito);
		
	}else{
		recuperatorito=rand()%11;
		objeto5.setRecuperatorio(recuperatorito);
		if(recuperatorito>=6){
			resultadito="Aprobado";
			objeto5.setResultado(resultadito);
			
		}else{
			if(recuperatorito<=5){
				resultadito="Desaprobado";
				objeto5.setResultado(resultadito);
			}
		}
	}
	lista[4]=objeto5;
	
	
	
	
	cout<<"Nota: si el alumno desapueba en el promedio, este devera ir a un "<<endl;
	cout<<"recuperatorio, el cual si lo aprueba contara como materia aprobada"<<endl;
	do{
		cout<<"menu de opciones\n";
		cout<<"a_mostrar alumnos"<<endl;
		cout<<"b_buscar alumno"<<endl;
		cin>>opcion;
		switch(opcion){
		case 'a':
			mostrar(lista);
			break;
		case 'b':
			buscarAlumno(lista);
			break;
		}
		
	cout<<"continuar? s/n"<<endl;
	cin>>opcion;	
		
	}while(opcion=='s');
	return 0;
	
}
void mostrar(Calificaciones lista [5]){
	cout<<"Lista de alumnos:"<<endl;
	for(int i=0;i<5;i++){
		Calificaciones v=lista[i];
		cout<<v.toString()<<endl;
	}
	cout<<"\n";
}
void buscarAlumno(Calificaciones lista[5]){
	string elnombre;
	cout<<"ingrese nombre del alumno"<<endl;
	cin>>elnombre;
	for(int i=0;i<5;i++){
		if(lista[i].getNombre_alumno().compare(elnombre)==0){
			Calificaciones v=lista[i];
			cout<<v.toString()<<endl;
		}
	}
}
