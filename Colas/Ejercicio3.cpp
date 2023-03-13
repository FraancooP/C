/*Crear un programa con el siguiente menu de opciones: 

Agregar un nodo a la cola. (se deben agregar 5 valores)
Borrar el primer nodo de la cola.
Imprimir cola.
Tamaño de la cola
Valor del frente de la cola*/
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
void push(struct node **,struct node **,int);
void mostrar(struct node *);
void pop(struct node **, struct node **);
int main(int argc, char *argv[]){
    char op=' ',cass=' ';
    struct node *front = NULL;
    struct node *back = NULL;
    int valores=0,cantidad=0;
    do
    {
        printf("Seleccione una opcion:\n");
        printf("A)Cargar valores en la cola.(MAX 5)\n");
        printf("B)Borrar el primer nodo de la cola.\n");
        printf("C)Mostrar todo.\n");
        printf("D)Tamanio cola.\n");
        printf("E)Valor de frente de la cola.\n");
        scanf(" %c",&cass);
        switch (cass)
        {
            case 'a':
            case 'A':
            for (int i = 0; i < 5; i++)
            {
                scanf("%d",&valores);
                push(&front,&back,valores);
                cantidad++;
            }
                break;
            case 'b':
            case 'B':
            cantidad=cantidad-1;
            pop(&front,&back);
                break;
            case 'c':
            case 'C':
            mostrar(front);
                break;
            case 'd':
            case 'D':
            printf("El tamanio de la cola es de %d valores.\n",cantidad);
                break;
            case 'e':
            case 'E':
            printf("Valor del frente de la cola: %d\n",front->data);
                break;        
            default:
            printf("No se selecciono ninguna opcion propuesta.\n");
                break;
        }
        printf("Desea continuar?S/N\n");
        scanf(" %c",&op);
    } while (op=='s');
    return 0;
}
void push(struct node **front, struct node **back, int datos){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("No hay memoria suficiente.\n");
        exit(1);
    }
    temp->data=datos;
    temp->link=NULL;
    if (*back==NULL)
    {
        *back=temp;
        *front=*back;
    }else{
        (*back)->link =temp;
        *back=temp;
    }
}
void mostrar(struct node *front){
    struct node *temp = NULL;
    temp=front;
    printf("Los valores ingresados son: \n");
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void pop(struct node **front, struct node **back){
    struct node  *temp = NULL;
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