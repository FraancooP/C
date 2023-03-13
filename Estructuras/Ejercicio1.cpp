/*Crear un programa que pida los siguientes datos de una canción: 
Artista, Titulo, Duración (en segundos),Tamaño del archivo (en KB). 
Crear una estructura que almacene datos de la canción y luego los muestre por pantalla.*/
#include <iostream>
#include <stdio.h>
using namespace std;
struct cancion
	{
	string artista;
	string titulo;
	long dura;
	long memor;
};
int main(int argc, char *argv[]) {
	struct cancion c;
	printf("Ingrese los datos de la cancion(finalizar con (.)): \n");
	printf("Artista: \n");
	scanf(" %s",&c.artista);
	printf("Titulo: \n");
	scanf(" %s",&c.titulo);
	printf("Duracion de la cancion(minutos): \n");
	scanf("%d",&c.dura);
	printf("Peso de la cancion en KB: \n");
	scanf("%d",&c.memor);
	printf("Datos ingresados: \n");
	printf("Artista: %s\n",c.artista);
	printf("Titulo: %s\n",c.titulo);
	printf("Duracion: %d\n",c.dura);
	printf("Memoria: %d\n",c.memor);
	return 0;
}