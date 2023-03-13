//1.Escribir un programa que declare una variable llamada a, un puntero del tipo
//de la variable creada, inicialice la variable e inicialice el puntero para 
//que apunte a la variable creada. Luego que imprima por pantalla: la dirección 
//de memoria de la variable, el valor que almacena la variable, el valor del puntero 
//y el valor al que apunta el puntero.
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
    int a=10;
	int *puntero=&a;
	printf("Direccion de a %X\n",&a);
	printf("Valor de a %d\n",a);
	printf("Valor del puntero %X\n",puntero);
	printf("Direccion del puntero %X\n",&puntero);
    system("pause");
	return 0;
}
