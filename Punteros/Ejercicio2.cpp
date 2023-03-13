/*Cargar las 3 notas de un alumno como valores enteros. 
Luego mostrar el promedio teniendo en cuenta si tiene parte decimal.*/
#include <iostream>
using namespace std;
int main(int argc, char *argv[]){
int nota1=0,nota2=0,nota3=0;
float prom=0.0f;
printf("Ingrese 3 notas: \n");
scanf("%d",&nota1);
scanf("%d",&nota2);
scanf("%d",&nota3);
prom=(nota1+nota2+nota3)/3.0;
printf("El promedio final de las notas es de: %f\n",prom);
system("pause");
return 0;
}