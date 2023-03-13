/*Desarrolle un programa que cargue una cola de numeros enteros aleatorios.  Luego realice un menu de opciones:

Agregar un nodo a la cola. (cuando agrega un valor, el mismo no tiene que estar repetido en la cola)
Borrar el primer nodo de la cola.
Imprimir cola.*/
#include <iostream>
#include <ctime>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
void push(struct node **, struct node **, int);
void pop(struct node **,struct node **);
void mostrar(struct node *);
int main(int argc, char *argv[]){
    srand(time(NULL));
    int datos=0,rep=0;
    char op=' ',cass=' ';
    struct node *front = NULL;
    struct node *back = NULL;
    do
    {
        printf("Selecciona una opcion.\n");
        printf("A)Cargar un dato nuevo.\n");
        printf("B)Borrar el primer nodo de la cola.\n");
        printf("C)Mostra la cola.\n");
        scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
        for (int i = 0; i < 20; i++)
        {
            datos=rand()%25+25;
            if(datos==datos){
                rep=rep+1;
            }
            push(&front,&back,datos);
        }
        printf("Se repetieron %d numeros.\n",rep);
            break;
        case 'b':
        case 'B':
        pop(&front,&back);
            break;
        case 'c':
        case 'C':
        mostrar(front);
            break;
        
        default:
        printf("No se eligio ninguna opcion propuesta.\n");
            break;
        }
        printf("¿Desea continuar?S/N");
        scanf(" %c",&op);
    } while (op=='s');
    return 0;
}
void push(struct node **front, struct node **back,int datos){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("No hay memoria suficiente.\n");
        exit(1);
    }
    temp->data=datos;
    temp->link=NULL;
    if(*back==NULL){
        *back=temp;
        *front=*back;
    }else{
        (*back)->link=temp;
        *back=temp;
    }
}
void mostrar(struct node *front){
    struct node *temp=NULL;
    temp=front;
    printf("Los valores ingresados son: \n");
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}
void pop(struct node **front, struct node **back){
    struct node *temp = NULL;
    if((*front==*back)&&(*back==NULL)){
        printf("Vacia\n");
        exit(0);
    }
    temp=*front;
    *front = (*front)->link;
    if(*back==temp){
        *back=(*back)->link;
    }
    printf("Primer nodo borrado.\n");
    free(temp);
}