/*Escribir un programa que declare una variable llamada a, 
un puntero del tipo de la variable creada, inicialice la variable e inicialice el puntero
 para que apunte a la variable creada. Luego que imprima por pantalla: la direccion de memoria de
  la variable, el valor que almacena la variable, el valor del puntero y el valor al que apunta el puntero.*/
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    int a=10;
    int *puntero;
    puntero=&a;
    printf("La direccion de memoria de la variable es: %X\n",puntero);
    printf("El valor de la variable es: %d\n",*puntero);
    printf("El valor del puntero es: %X\n",&puntero);
    printf("El valor al que apunta el puntero eso: %X\n",puntero);
    system("pause");
    free(puntero);
    return 0;
}