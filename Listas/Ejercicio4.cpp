/*Crear una lista con 10 letras y luego mostrar solo las vocales.*/
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
	char dato=0;
	char i=0;
	printf("Ingrese 10 letras.\n");
	do{
		scanf(" %c", &dato);
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
	}while(i!=10);
	temp=head;
	if(head==NULL){
		printf("Lista vacia\n");
		exit(1);
	}else{
		node*temp=head;
		printf("Lista completa\n");
		while(temp!=NULL){
			printf(" %c\t",temp->data);
			temp=temp->next;
		}
	}
	if(head==NULL){
		printf("Lista vacia\n");
		exit(1);
	}else{
		node*temp=head;
		printf("LAS VOCALES INGRESADAS SON:\n");
		while(temp!=NULL){
			if(temp->data=='a' || temp->data=='e' || temp->data=='i' || temp->data=='o' || temp->data=='u'){
			printf(" %c\t",temp->data);	
			};
			temp=temp->next;
		}

	}
	return 0;
}

