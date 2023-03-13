/*Desarrollar el ejercicio anterior con funciones. 
Crear una funcion que pase los valores a mayusculas y una funcion que pase los valores a minusculas. 
Desarrollar un programa que declare e inicialice un vector tipo char con el abecedario. 
Luego mostrar en pantalla el abecedario en mayuscula y minuscula,  utilizando punteros. 
Nota: la funcion para pasar a mayuscula es toupper() y a minusculas es tolower(). 
Ejemplo: cadena[i] = tolower(cadena[i]); En codigo ASCII A=65*/
#include <iostream>
using namespace std;
void mayus(char *puntero);
void minuss(char *puntero);
int main(int argc, char *argv[]) {
	char abecedario[26]={' '};
	char *puntero;
	puntero=&abecedario[0];
	for(int i=0;i<26;i++){
		abecedario[i]=65+i;
	}
	mayus(puntero);
	minuss(puntero);
	return 0;
}
void mayus(char *p){
	
	for(int i=0;i<26;i++){
		printf(" %c",toupper(*p+i));
	}
	printf(" \n");
}
void minuss(char *p){
	for(int i=0;i<26;i++){
		printf(" %c",tolower(*p+i));
	}
	printf(" \n");
}
