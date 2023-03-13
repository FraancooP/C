/*Escriba un programa que busque dentro del archivo el_quijote.txt la cantidad 
de veces que aparecen las palabras "Quijote", "Rocinante" y "Sancho". 
Recuerden descargar el archivo en el mismo lugar donde corren el programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_null(FILE *fp);

int main(int argc, char *argv[]) {
	FILE *fp = fopen("el_quijote.txt", "r");
	check_null(fp);
	
	char palabra[20]={0};
	int cont_Quijote=0, cont_Rocinante=0, cont_Sancho=0;
	
	while(fscanf(fp,"%s",&palabra) != EOF)
	{
		if (strcmp(palabra, "Quijote") == 0){ 
			cont_Quijote++ ;
		}
		if (strcmp(palabra,"Rocinante") == 0) { 
			cont_Rocinante++ ;
		}
		if (strcmp(palabra, "Sancho") == 0) { 
			cont_Sancho++ ;
		}
		
	}
	
	printf("Cantidad de veces que aparece cada palabra\n");
	printf("Quijote: %d\n", cont_Quijote);
	printf("Rosinante: %d\n", cont_Rocinante);
	printf("Sancho: %d\n", cont_Sancho);
	return 0;
}

void check_null(FILE *fp){
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		exit(1);
	}
}
