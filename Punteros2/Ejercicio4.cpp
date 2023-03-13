/*Se tiene un vector de 10 elementos con valores numéricos enteros . 
Luego crear una funcion que muestre los valores que están en posiciones impares,
y otra funcion con las posiciones pares.*/
#include <iostream>
#include <ctime>
using namespace std;
void pares(int *puntero);
void impar(int *puntero);
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int vector[10]={0};
	int *punteros;
	punteros=&vector[0];
	printf("Ingrese numeros enteros del 1 al 10. \n");
	for(int i=0;i<10;i++){
		*(punteros+i)=1+rand()%9;
	}
	for(int i=0;i<10;i++){
		printf("%d\t",*(punteros+i));
	}
	
	pares(punteros);
	return 0;
}
void pares(int *v){
	printf("\nLas posiciones pares son: \n");
	for(int i=0;i<10;i++){
		if(i%2==0){
			printf("%d\n",*(v+i));
		 }else{
			if(i%2!=0){
				//ç+printf("%d\n",*(v+i));
			}
		}
	}
		
}

