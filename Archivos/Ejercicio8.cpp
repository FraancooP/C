/*Escribir un programa que tenga un menú de opciones,
cada una de ellas una función: a. Cargar lista de productos en el archivo de texto . 
b. Leer la lista de productos del archivo de texto . 
Para ello deberá crear un vector de estructura llamada "Producto" y de tamaño 3. 
La estructura "Producto" contendrá los siguientes atributos: nombre del producto, 
marca, precio unitario, fecha de elaboración, tamaño. El archivo se llamará 
“Listado_Producto.txt”.*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;
struct Producto
{
    char nombre[30];
    char marca[10];
    float precio_unitario=0.0f;
    char fecha_elaboracion[20];
    char tamanio[10];
};

void check(FILE *fp);
int main(int argc, char *argv[]){
    char op=' ',cass=' ';
    struct Producto p[3];
    FILE *fp = fopen("Listado_Productos.txt","w");
    check(fp);
    do
    {
        printf("Selecciona una opcion.\n");
        printf("A)Cargar lista de productos.\n");
        printf("B)Mostrar lista de productos.\n");
        scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
        FILE *fp = NULL;
        fp = fopen("Listado_Productos.txt","w");
        check(fp);
        for (int i = 0; i < 3; i++)
        {
            printf("Ingrese los datos de los productos en orden.\n");
            printf("Nombre: ");
            scanf("%s",p[i].marca);
            printf("Marca: ");
            scanf("%s",p[i].marca);
            printf("Precio: ");
            scanf("%f",&p[i].precio_unitario);
            printf("Fecha de elaboracion: ");
            scanf("%s",p[i].fecha_elaboracion);
            printf("Tamanio: ");
            scanf("%s",p[i].tamanio);
            fprintf(fp,"%s\n%s\n%f\n%s\n%s\n",p[i].nombre,p[i].marca,p[i].precio_unitario,p[i].fecha_elaboracion,p[i].tamanio);
        }
        fclose(fp);
            break;
        case 'b':
        case 'B':
        fp=fopen("Listado_Productos.txt","r");
        check(fp);
        while (!feof(fp))
        {
            for (int i = 0; i < 3; i++)
            {
                fscanf(fp,"%s\n%s\n%f\n%s\n%s\n",&p[i].nombre,&p[i].marca,&p[i].precio_unitario,&p[i].fecha_elaboracion,&p[i].tamanio);
                printf("%s\n%s\n%f\n%s\n%s\n",p[i].nombre,p[i].marca,p[i].precio_unitario,p[i].fecha_elaboracion,p[i].tamanio);
            }
        }
        fclose(fp);
            break;
        default:
        printf("No se selecciono ninguna opcion.\n");
            break;
        }
        printf("Desea continuar?S/N\n");
        scanf(" %c",&op);
    } while (op=='s' && 'S');
    return 0;
}
void check(FILE *fp){
    if (fp==NULL)
    {
        printf("Imposible abrir el archivo.\n");
        exit(1);
    }
}