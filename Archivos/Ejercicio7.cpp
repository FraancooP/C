/*Escribir un programa que cree una estructura llamada "Producto",
y que contenga los siguientes datos (nombre del producto, marca, 
precio unitario, fecha de elaboración, tamaño) y lo guarde en un
archivo de texto con el nombre “Datos_Producto_Estructura.txt”.*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct Producto
{
    char nombre[30],marca[10],fecha_elaboracion[10],tamanio[20];
    float precio=0.0f;
};
void check(FILE *fp);
int main(int argc, char *argv[]){
    FILE *fp = fopen("Datos_Producto_Estructura.txt", "w");
    check(fp);
    struct Producto p;
    printf("Ingrese los datos del producto.\n");
    printf("Nombre: ");
    scanf("%s",p.nombre);
    printf("Marca: ");
    scanf("%s",p.marca);
    printf("Precio del producto: ");
    scanf("%f",&p.precio);
    printf("Fecha de elaboracion: ");
    scanf("%s",p.fecha_elaboracion);
    printf("Tamanio del producto(cm): ");
    scanf("%s",p.tamanio);
    fprintf(fp,"%s\n%s\n%f\n%s\n%s\n", p.nombre, p.marca, p.precio, p.fecha_elaboracion, p.tamanio);
    fclose(fp);
    fp=fopen("Datos_Producto_Estructura.txt","r");
    check(fp);
    while (!feof(fp))
    {
        fscanf(fp,"%s\n%s\n%f\n%s\n%s\n", &p.nombre, &p.marca, &p.precio, &p.fecha_elaboracion, &p.tamanio);
        printf("%s\n%s\n%f\n%s\n%s\n", p.nombre, p.marca, p.precio, p.fecha_elaboracion, p.tamanio);
    }
    fclose(fp);
    return 0;
}
void check(FILE *fp){
    if (fp==NULL)
    {
        printf("Imposible abrir el archivo.\n");
        exit(1);
    }
}