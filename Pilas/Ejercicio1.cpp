/*Crear un programa con el siguiente menu de opciones: 
- Agregar un nodo a la pila. (se deben agregar 5 valores)
- Borrar el ultimo nodo de la pila.
- Imprimir pila.
- Suma de los valores de la pila.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

struct node{
	int data;
	struct node *next;
};

/*Prototipado de funciones*/
int menu(void);
void push(struct node **, int);
void pop(struct node **);
void print(struct node **);
bool isempty(struct node *);
int add(struct node **);
int count_nodes(struct node **);

int main(int argc, char *argv[]) {
	int op=0, value=0, i=0;
	struct node *stack_p =NULL;
	do{
		op=menu();
		switch(op){
			case 1:
			{
				printf("Ingresa los 5 numeros a la pila: \n");
				for(i=0; i<5;i++){
					scanf("%d", &value);
					push(&stack_p, value);
				}
				break;
			}
			case 2:
			{
				pop(&stack_p);
				break;
			}
			case 3:
			{
				print(&stack_p);
				break;
			}
			case 4:
			{
				printf("Suma: %d\n\n", add(&stack_p));
				break;
			}
		}
	} while(op<5);
	return 0;
}

int menu(void){
	int op=0;
	do{
		printf("--------------------------------------------\n");
		printf("1.- Agregar un nodo a la pila\n");
		printf("2.- Borrar un nodo de la pila\n");
		printf("3.- Imprimir pila\n");
		printf("4.- Suma de valores de una pila\n");
		printf("5.- Salir\n");
		scanf("%d", &op);
		printf("--------------------------------------------\n");
	}while((op<1)||(op>5));
	return op;
}
	
void push(struct node **sp, int value){
	struct node *new_node = NULL;
	/* Creacion de memoria*/
	new_node = (struct node*)malloc(sizeof(struct node));
	/*Verificacion de memoria disponible*/
	if(new_node==NULL){
		printf("No hay memoria disponible");
		exit(0);
	}
	/*Carga util*/
	new_node->data=value;
	/*Asignamos el siguiente del nuevo nodo al stack pointer actual*/
	new_node->next=*(sp);
	/*Ahora el nuevo nodo es el stackptr*/
	*(sp)=new_node;	
}
	
bool isempty(struct node *sp){
	if(sp==NULL)
		return(true);
	else
		return(false);
}
void pop(struct node **sp){
	if(isempty(*sp)==false){
		struct node *temp=NULL;	
		/*Asignamos en temp el stack pointer actual*/
		temp=*(sp);
		/*Asignamos al stack pointer, el valor siguiente del primer nodo*/
		*(sp)=(*sp)->next;
		/*Liberamos la memoria ocupada por el primer nodo*/
		free(temp);	
	}else{
		printf("Pila vacia\n");
	}
}
void print(struct node **sp){
	if(isempty(*sp)==false){
		printf("Pila\n");
		/*Comenzamos a recorrer desde el stack pointer*/
		struct node *temp;
		temp=*(sp);
		while(temp!=NULL){
			printf("%d\n", temp->data);
			temp=temp->next;
			/*Recordar que el ultimo nodo de la stack, en siguiente apunta a NULL*/
		}
	}else{
		printf("Pila vacia\n");
	}
}
int add(struct node **sp){
	int suma=0;
	if(isempty(*sp)==false){
		/*Comenzamos a recorrer desde el stack pointer*/
		struct node *temp;
		temp=*(sp);
		while(temp!=NULL){
			suma+=temp->data;
			temp=temp->next;
			/*Recordar que el ultimo nodo de la stack, en siguiente apunta a NULL*/
		}
	}else{
		printf("Pila vacia\n");
	}
	return suma;
}
int count_nodes(struct node **sp){
	int acum=0;
	if(isempty(*sp)==false){
		struct node *temp;
		temp=(*sp);
		while(temp!=NULL){
			acum+=1;
			temp=temp->next;
		}
	}else{
		printf("Pila vacia\n");
	}
	return (acum);
}
