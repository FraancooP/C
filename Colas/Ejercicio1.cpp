/*Crear un programa con el siguiente menu de opciones: 
Agregar un nodo a la cola. (se deben agregar 5 valores)
Borrar el primer nodo de la cola.
Imprimir cola.
Suma de los valores de la cola.*/
#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *link;
};
int main(int argc, char *argv[]) {
	struct node *front = NULL;
	struct node *back = NULL;
	struct node *temp = NULL;
	int valor=0,suma=0;
	char op=' ',cass=' ';
	int i=0;
	do{
		printf("A continuacion seleccione una opcion:\n");
		printf("A)Agregar un nodo a la cola(5 valores.)\n");
		printf("B)Borrar el primer nodo de la cola\n");
		printf("C)Impromir toda la cola.\n");
		printf("D)Sumar todos los valores\n");
		scanf(" %c",&cass);
		switch(cass){
		case 'a':
		case 'A':
			printf("Ingrese 5 valores.\n");
			do{
				scanf("%d",&valor);
				suma=suma+valor;
				temp=(struct node *)malloc(sizeof(struct node));
				if(temp==NULL){
					printf("No hay suficiente memora.\n");
					exit(0);
				}else{
					temp->data = valor;
					temp->link =NULL;
					if(back==NULL){
						back=temp;
						front=back;
					}else{
						back->link = temp;
						back = temp;
					}	
				}
				i++;
			}while(i!=5);
			break;
		case 'b':
		case 'B':
			i=i*0;
			do{
				if((front==back)&&(back==NULL)){
					printf("COLA VACIA");
				}
				temp=front;
				front = (front)->link;
				if(front==NULL){
					back=NULL;
				}
				free(temp);
				i++;
			}while(i!=1);
			break;
		case 'c':
		case 'C':
			temp=front;
			printf("VALORES INGRESADOS:\n");
			while(temp!=NULL){
				printf("%d\t",temp->data);
				temp=temp->link;
			}
			break;
		case 'd':
		case 'D':
			printf("La suma de todos los valores es: %d\n",suma);
			break;
		default:
			printf("No se selecciono ninguna opcion propuesta.\n");
			break;
		}
		printf("Desea continuar?S/N");
		scanf(" %c",&op);
	}while(op=='s');
	return 0;
}