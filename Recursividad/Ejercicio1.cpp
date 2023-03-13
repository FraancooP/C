/*Realizar un programa que solicite el ingresar de un número
y mostrar su equivalente en binario usando una función recursiva.
Por ejemplo:
SISTEMA DECIMAL SISTEMA BINARIO

2 10

3 11

4 100

5 101*/
#include <iostream>
using namespace std;
int convertir_binario(int);
int main(int argc, char *argv[]) {
	int num=0;
	cout<<"Ingrese un numero."<<endl;
	cin>>num;
	convertir_binario(num);
	return 0;
}
int convertir_binario(int num){
	if(num>1){
		convertir_binario(num/2);
	}
	cout<<num%2;
	return 0;
}
