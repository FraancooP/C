/*Desarrolle un programa que declare e inicialice un vector de 5 valores (4.5,8,2.3,1.1,3). 
Luego, se pide que calcule y muestre la sumatoria y el promedio. 
Utilice punteros para realizar el ejercicio.*/
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float *p1,*p2;
	float suma=0.0f, promedio=0.0f;
	p1=&suma;
	p2=&promedio;
	float vector[5]={4.5,8,2.3,1.1,3};
	float *vectorpuntero;
	vectorpuntero=vector;
	//vectorpuntero=&vector[0];
	for(int i=0;i<5;i++){
		*p1+=*(vectorpuntero++);
	}
	*p2=*p1/5;
	printf("La suma total es %f , el promedio total es: %f \n", *p1,*p2);
	return 0;
}

