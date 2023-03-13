/*Realice un programa que permita cargar 10 números enteros en un vector. 
Luego utilizando punteros calcule el promedio de ellos. 
Finalmente mostrar todos los valores y su promedio utilizando punteros.*/
#include <iostream>
using namespace std;
int main(int argc, char *argv[]){
    int suma=0;
    float prom=0.0f;
    int vector[10]={0};
    int *punterovector;
    int *p1;
    float *p2;
    p1=&suma;
    p2=&prom;
    punterovector=vector;
    printf("Porfavor ingrese 10 numeros en orden: \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&*(punterovector+i));
    }
    printf("LOS VALORES INGRESADOS SON:\t");
    for (int i = 0; i < 10; i++)
    {
        *p1+=*(punterovector++);
        printf("%d\t",*(punterovector+i));
    }
    printf("\n");
    *p2=*p1/10.0;
    printf("La suma total de todos los valores es: %d, su promedio eso: %f\n",*p1,*p2);
    system("pause");
    return 0;
}



