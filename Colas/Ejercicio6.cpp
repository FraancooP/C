/*Elaborar un sistema de stock, en la cual posee una cola de productos con los siguientes atributos: 
codigo, nombre, cantidad, precio lista. Desarrollar las siguientes funciones:

Agregar un nuevo producto.
Borrar el primer nodo de la cola.
Mostrar el stock. 
Descontar stock.
Reponer stock.*/
#include <iostream>
using namespace std;
struct producto
{
    int codigo;
    char nombre;
    int cantidad;
    float precio_lista;
};
struct node
{   struct producto p;
    struct node *link;
};
void push(struct node **, struct node **, struct producto);
void pop(struct node **, struct node **);
void mostrar_stock(struct node *);
int main(int argc, char * argv[]){
    struct producto p;
    struct node *back = NULL;
    struct node *front = NULL;
    char op=' ', cass=' ';
    do
    {
        printf("Bienvenido, Selecciona una opcion.\n");
        printf("A)Agregar un nuevo producto.\n");
        printf("B)Borrar el primer nodo de la lista.\n");
        printf("C)Mostrar el Stock.\n");
        printf("D)Descontar Stock.\n");
        printf("E)Reponer Stock.\n");
        scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
        printf("Ingrese el codigo del producto.\n");
        cin>>p.codigo;
        printf("Ingrese el Nombre del producto.\n");
        cin>>p.nombre;
        printf("Ingrese la cantidad que desea llevar.\n");
        cin>>p.cantidad;
        printf("Ingrese el precio del prodcuto.\n");
        cin>>p.precio_lista;
        push(&front,&back,p);
            break;
        case 'b':
        case 'B':
        pop(&front,&back);
            break;
        case 'c':
        case 'C':
        mostrar_stock(front);
            break;
        case 'd':
        case 'D':
            break;
        case 'e':
        case 'E':
            break;
        default:
        printf("No se selecciono ninguna opcion propuesta.\n");
            break;
        }
        printf("Desea continuar? S/N");
        scanf(" %c",&op);
    }while(op=='s');
    return 0;
}
void push(struct node **front, struct node **back, struct producto p){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("NO hay suficiente memora.\n");
        exit(0);
    }
    temp->p=p;
    temp->link=NULL;
    if(*back==NULL){
        *back=temp;
        *front=*back;
    }else{
        (*back)->link=temp;
        *back=temp;
    }
}
void pop(struct node **front, struct node **back){
    struct node *temp = NULL;
    if((*front==*back)&&(*back==NULL)){
        printf("Lista vacia.\n");
        exit(0);
    }
    temp=*front;
    *front= (*front)->link;
    *front = (*front)->link;
    if(*back==temp){
        *back=(*back)->link;
    }
    printf("Primer nodo borrado.\n");
    free(temp);
}
void mostrar_stock(struct node *front){
struct node *temp = NULL;
	temp=front;
	cout<<"El producto es: \n";
	cout<<"Codigo.\tNombre\tCantidad.\tPrecio\n";
	while(temp!=NULL){
		cout<<temp->p.codigo<<"\t"<<temp->p.nombre<<"\t"<<temp->p.cantidad<<"\t"<<temp->p.precio_lista<<"\n";
		temp=temp->link;
	}
}