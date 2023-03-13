/*Escribir un programa que solicite dos numeros y luego una de las operaciones del menu de opciones: 
a. sumar
b. restar
c. multiplicar
d. dividir dos numeros
e. elevar a una potencia
f. calcular la raiz de numero
Luego mostrar el resultado y preguntar si desea realizar otra operacion o terminar el programa.
Utilizar punteros para el calculo de las operaciones. Libreria: #include <math.h>*/
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]){
int num1=0,num2=0,operador=0,potencia=0,np1=0,np2=0;
int *puntero1;
int *puntero2;
char cass=' ',op=' ';
printf("Porfavor ingrese 2 numeros.\n");
scanf("%d",&num1);
scanf("%d",&num2);
puntero1=&num1;
puntero2=&num2;
do
{
    printf("Porfavor, seleccione una opción.\n");
    printf("A)Sumar los numeros.\n");
    printf("B)Restar ambos numeros.\n");
    printf("C)Multiplicar los numeros entre si.\n");
    printf("D)Dividir los numeros entre si.\n");
    printf("E)Elevar a una potencia ambos numeros.\n");
    printf("F)Calcular la raiz de los numeros\n");
    scanf(" %c",&cass);
    switch (cass)
    {
    case 'a':
    case 'A':
    operador=operador*0;
    operador=(*puntero1)+(*puntero2)+0.0;
    printf("La suma de los numeros es: %f\n",operador);
        break;
    case 'b':
    case 'B':
    operador=operador*0;
    operador=(*puntero1)-(*puntero2)+0.0;
    printf("La resta de los numeros es: %f\n",operador);
        break;
    case 'c':
    case 'C':
    operador=operador*0;
    operador=(*puntero1)*(*puntero2);
    printf("La multiplicacion de ambos numeros es: %f\n",operador);
        break;
    case 'd':
    case 'D':
    operador=operador*0;
    operador=(*puntero1)/(*puntero2);
    printf("La division de ambos numeros es: %f\n",operador);
        break;
    case 'e':
    case 'E':
    printf("Elija a la potencia entera que desea elevar:\n");
    scanf("%d",&potencia);
    np1=pow((*puntero1),potencia);
    np2=pow((*puntero2),potencia);
    printf("%f elevado es: %f\n",*puntero1,np1);
	printf("%f elevado es: %f\n",*puntero2,np2);
        break;
    case 'f':
    case 'F':
    printf("SE ELIJIO LA OPCION f\n");
        break;
    default:
    printf("No se selecciona ninguna opcion.\n");
        break;
    }
    printf("¿Desea continuar?S/N");
    scanf(" %c",&op);
} while (op=='s' && 'S');
system("pause");
return 0;
}