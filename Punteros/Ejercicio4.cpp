/*Escribir un programa que intercambie los valores enteros de a y b utilizando punteros.*/
#include <iostream>
using namespace std;
int main(int argc, char *argv[]){
int a=22, b=45,inte1=0,inte2=0;
int *puntero1=&a;
int *puntero2=&b;
printf("El valor de la variable a es: %d\n",*puntero1);
printf("El valor de la variable b es: %d\n",*puntero2);
inte1=*puntero1;
inte2=*puntero2;
*puntero1=inte2;
*puntero2=inte1;
printf("INTERCAMBIANDO CON PUNTEROS----------\n");
printf("El valor de a es: %d\n",a);
printf("El valor de b es: %d\n",b);
system("pause");
return 0;
}