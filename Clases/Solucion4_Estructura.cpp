/*Crear una clase Actividad, las mismas corresponden a las actividades de un gym. 
Atributos: nombre, cupo, dias de la semana, horario, cant_inscriptos.

Funciones: mostrar, buscar, mostrar actividades que aun no tienen el cupo lleno.
*/

#include <iostream>
using namespace std;


struct actividad
{
	string nombre;
	int cupo;
	string dias_semana;
	string horario;
	int cant_inscripto;
};

void agregar(actividad[3]);
void mostrar(actividad[3]);
void mostrarActividadDisponible(actividad[3]);


int main(int argc, char *argv[]) {
	
	struct actividad lista[3]; 
	
	char op=' ';
	
	do{
		cout<<"---------------------------------------------------"<<endl;
		cout<<"MENU DE OPCIONES"<<endl;
		cout<<"a. Agregar.\nb. Mostrar.\nc. Mostrar Actividades Disponibles.\n";
		cin>>op;
		switch(op){
		case 'a': 
			agregar(lista);
			break;
		case 'b':
			mostrar(lista);
			break;
		case 'c':
			mostrarActividadDisponible(lista);
			break;
		}
		cout<<"\n¿Desea seguir (S/N)? ";
		cin>>op;
		
	}while(op=='s' || op=='S');
	
	return 0;
}

void agregar(actividad lista[3]){
	cout<<"---------------------------------------------------"<<endl;
	for(int i=0; i<3; i++){
		cout<<"\nINGRESE LOS DATOS DE ACTIVIDAD Nº"<<i+1<<": "<<endl;
		cout<<"Nombre: ";
		cin>>lista[i].nombre;
		cout<<"Cupo: ";
		cin>>lista[i].cupo;
		cout<<"Dias de la semana: ";
		cin>>lista[i].dias_semana;
		cout<<"Horario: ";
		cin>>lista[i].horario;
		cout<<"Cantidad de inscriptos: ";
		cin>>lista[i].cant_inscripto;
		
	}
}
	
	
void mostrar(actividad lista[3]){
	cout<<"---------------------------------------------------"<<endl;
	cout<<"Nombre\tCupo\tDias de la semana\tHorario\tCant. Inscriptos"<<endl;
	for(int i=0; i<3; i++){
		cout<<lista[i].nombre<<"\t"<<lista[i].cupo<<"\t"<<lista[i].dias_semana<<"\t"<<lista[i].horario<<"\t"<<lista[i].cant_inscripto<<endl;
	}	
}

void mostrarActividadDisponible(actividad lista[3]){
	cout<<"---------------------------------------------------"<<endl;
	cout<<"CUPOS DISPONIBLES"<<endl;
	cout<<"Nombre\tCupo\tDias de la semana\tHorario\tCant. Inscriptos"<<endl;
	for(int i=0; i<3; i++){
		if(lista[i].cant_inscripto<lista[i].cupo)
			cout<<lista[i].nombre<<"\t"<<lista[i].cupo<<"\t"<<lista[i].dias_semana<<"\t"<<lista[i].horario<<"\t"<<lista[i].cant_inscripto<<endl;
	}	
}
		
		
		
