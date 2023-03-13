/*Desarrollo un programa que cree una cola de vehiculos que pasan por un peaje,
en la cual se deben registrar patente, marca, color, cantidad de ejes, precio, direccion.
El precio es segun la cantidad de ejes. (1 eje = $100, 2 ejes = $150, 3 ejes = $200 y 4 ejes o mas $300).
La direccion es a la que se dirige el vehiculo, en este caso puede ser de Norte a Sur o Sur a Norte. Luego,
arme un menu de opciones que muestre lo siguiente: 
Agregar un vehiculo a la cola
Borrar el primer nodo de la cola.
Mostrar todos los vehiculos. 
Mostrar los vehiculos por dirección
Mostrar los vehiculos por ejes. */
#include <iostream>
using namespace std;
struct vehiculo
{
    int patente;
    int marca;
    string color;
    int cant_ejes;
    int precio;
    int direccion;
};
struct node
{
    struct vehiculo a;
    struct node *link;
};
void push(struct node **, struct node **, struct producto);
int main(int argc, char *argv[]){
    struct vehiculo a;
    struct node *back = NULL;
    struct node *front = NULL;
    char op=' ', cass=' ';
    do
    {
        printf("Bienvenido, Selecciona una opcion.\n");
        printf("A)Cargar un vehiculo.\n");
        printf("B)Borrar el primer nodo de la lista.\n");
        printf("C)Mostrar todos los vehiculos.\n");
        printf("D)Mostrar los vehiculos por direccion.\n");
        printf("E)Mostrar los vehiculos por ejes.\n");
        scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
            break;
        case 'b':
        case 'B':
            break;
        case 'c':
        case 'C':
            break;
        case 'd':
        case 'D':
            break;
        case 'e':
        case 'E':
            break;
        default:
        printf("No se selecciono ninguna opcion propuesta.\n");
            break;
        }
        printf("Desea continuar? S/N");
        scanf(" %c",&op);
    }while(op=='s');
    return 0;
}