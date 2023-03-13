/*Crear un programa en la cual cargue una lista de 5 numeros aleatoriamente (entre 1 y 10), 
luego los muestre los todos los valores. Finalmente borre un valor y vuelva a mostrar la lista resultante.*/
#include <iostream>
#include <ctime>
using namespace std;
struct node{
	int data;
	struct node *next;
};
int main(int argc, char *argv[]) {
	srand(time(NULL));
	struct node* head=NULL;
	struct node* temp=NULL;
	struct node *new_node=NULL;
	int dato=0;
	int i=0;
	int borrar=0;
	printf("Generando Numeros aleatorios\n");
	do{
		dato=1+rand()%9;
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
		struct node* prev=NULL;
		struct node* current=NULL;
		printf("Ingrese el dato a borrar: \n");
		scanf("%d",&borrar);
		if(borrar==head->data){
			temp=head;
			head=head->next;
			free(temp);
		}else{
			prev=head;
			current=head->next;
			while(current!=NULL and current->data!=borrar){
				prev=current;
				current=current->next;
			}
			if(current!=NULL){
				temp=current;
				prev->next = current->next;
				free(temp);
			}
		}
	}
	temp=head;
	if(head==NULL){
		printf("LA LISTA ESTA VACIA\n");
		exit(1);
	}else{
		node*temp=head;
		printf("LOS VALORES SON: \n");
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
	return 0;
}
