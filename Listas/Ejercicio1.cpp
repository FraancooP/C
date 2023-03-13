/*Crear un programa en la cual se solicite al usuario el ingreso de 5 valores numericos y luego muestre la lista.*/
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
	
	
	
	
	
	
	
	
	return 0;
}

