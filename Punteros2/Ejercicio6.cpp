/*Se desea cargar en un vector los saldos de proveedores. 
La cantidad de saldos es ingresada por el usuario (maximo 10).
La carga finaliza con un saldo menor o igual a cero. Además, desarrolle las siguientes funciones para mostrar:
a. Cantidad de saldos cargados.
b. Promedio de saldos.
c. Cantidad de saldos menores al promedio.
d. Cantidad de saldos mayores al promedio.
e. Calcular cuánto fue lo recaudado en el mes.
Cada ítem es una función. Para recorrer el vector utilice punteros.*/
#include <iostream>
using namespace std;
void cantidad_saldos(int *puntrovector,int);
void promedio_saldos(int *punterovector,int);
void menores(int *punterovector,int);
int main(int argc, char *argv[]){
int cantidad=0;
char cass=' ',op=' ';
int vector[10]={0};
int *punterovector;
punterovector=vector;
printf("Ingrese la cantidad de saldos que desea cargar.\n");
scanf("%d",&cantidad);
printf("Comienze a cargar los suledes: \n");
for (int i = 0; i < cantidad; i++)
{
    scanf("%d",&*(punterovector+i));
}
printf("A continuacion seleccione una opcion: \n");
do
{
    printf("A)Cantidad de saldos cargados.\n");
    printf("B)Promedio de todos los saldos.\n");
    printf("C)Cantidad de saldos menores al promedio.\n");
    printf("D)Cantidad de saldos mayores al promedio\n");
    printf("E)Calcula recaudo total.\n");
    scanf(" %c",&cass);
    switch (cass)
    {
    case 'a':
    case 'A':
    cantidad_saldos(punterovector,cantidad);
    break;
    case 'b':
    case 'B':
    promedio_saldos(punterovector,cantidad);
    break;
    case 'd':
    case 'D':
    menores(punterovector,cantidad);
    break;
    case 'e':
    case 'E':
    break;
    default:
    printf("No se selecciono ninguna opcion propuesta.\n");
        break;
    }
    printf("Seleccionar otra opcion?S/N\n");
    scanf(" %c",&op);
} while (op=='s');
system("pause");
    return 0;
}
void cantidad_saldos(int *vector,int cantidad){
    printf("LA CANTIDAD DE SALDOS CARGADOS ES: %d\n",cantidad);
}
void promedio_saldos(int *vector,int cantidad){
int suma=0;
float promedio=0.0f;
for (int i = 0; i < cantidad; i++)
{
    suma=*(vector++);
}
promedio=suma/cantidad;
printf("El promedio de todos los saldos es: %f\n",promedio);
}
void menores(int *vector,int cantidad){
    int suma=0;
    float prom=0.0f;
    for (int i = 0; i < cantidad; i++)
    {
        suma=*(vector++);
    }
    prom=suma/cantidad;
    for (int i = 0; i < cantidad; i++)
    {
        if(*(vector+i)<prom)
        printf("SALDOS MENORES AL PROMEDIO: %d\t",*(vector+i));
    }
    printf("\n");
}

