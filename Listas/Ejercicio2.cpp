/*Crear un programa en la cual se solicite al usuario el ingreso de 5 valores numericos. 
Luego muestre la lista y calcule el promedio de ellos*/
#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
int main(int argc, char *argv[]) {
	struct node* head=NULL;
	struct node* temp=NULL;
	struct node *new_node=NULL;
	int dato=0;
	int i=0;
	int suma=0;
	float prom=0.0f;
	printf("Ingrese 5 numeros.\n");
	do{
		scanf("%d", &dato);
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node = (struct node *) new_node;
		if(new_node==NULL){
			printf("NO hay memoria disponible.\n");
			exit(1);
		}
		new_node->data=dato;
		new_node->next=NULL;
		if(head==NULL){
			head=new_node;
		}else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new_node;
		}
		i++;
	}while(i!=5);
	temp=head;
	if(head==NULL){
		printf("Lista vacia\n");
		exit(1);
	}else{
		node*temp=head;
		printf("Lista completa\n");
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
	if(head==NULL){
		printf("Lista vacia\n");
		exit(1);
	}else{
		node*temp=head;
		while(temp!=NULL){
			suma+=temp->data;
			temp=temp->next;
		}
		prom=suma/5.0;
		printf("La suma de todos los valores es: %d\n",suma);
		printf("El promedio es: %f\n",prom);
	}
	return 0;
}

