/*Desarrollar un programa que declare e inicialice un vector tipo char con el abecedario. 
Luego mostrar en pantalla el abecedario en mayuscula y minuscula, utilizando punteros. 
Nota: la funcion para pasar a mayuscula es toupper() y a minusculas es tolower().  
Ejemplo: cadena[i] = tolower(cadena[i]); En codigo ASCII A=65*/
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char abecedario[26]={' '};
	char *puntero;
	puntero=&abecedario[0];
	for(int i=0;i<26;i++){
		abecedario[i]=65+i;
	}
	printf("\n");
	for(int i=0;i<26;i++){
		printf(" %c",toupper(*puntero+i));
	}
	printf(" \n");
	
	
	for(int i=0;i<26;i++){
		printf(" %c",tolower(*puntero+i));
	}
	return 0;
}