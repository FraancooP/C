/*Crear un programa en la cual cargue una cola de 5 numeros aleatoriamente (entre 1 y 10), luego los muestre y muestre los valores pares.*/
#include <iostream>
#include <ctime>
using namespace std;
struct node
{
    int data;
    struct  node *link;
};
void push(struct node **,struct node **, int);
void mostrar(struct node *);
void mostrar_pares(struct node *);
int main(int argc, char *argv[]){
struct node *front = NULL;
struct node *back = NULL;
int valores=0, i=0;
char op=' ',cass=' ';
srand(time(NULL));
do{
printf("Selecciona una opcion:\n");
printf("A)Cargar nuevos valores en la cola.\n");
printf("B)Mostrar los valores.\n");
printf("C)Mostrar solo los valores pares.\n");
scanf(" %c",&cass);
switch (cass)
{
case 'a':
case 'A':
valores=valores*0;
for (int i = 0; i < 5; i++)
{
    valores=rand()%10+1;
    push(&front,&back,valores);
}
printf("VALORES CARGADOS.\n");
    break;
case 'b':
case 'B':
mostrar(front);
    break;
case 'c':
case 'C':
mostrar_pares(front);
    break;
default:
printf("No se selecciono ninguna opcion propuesta.\n");
    break;
}
printf("¿Desea continuar?S/N\n");
scanf(" %c",&op);
}while(op=='s');
    return 0;
}
void push(struct node **front,struct node **back,int datos){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
if(temp==NULL){
printf("No hay memoria suficiente.");
exit(0);
}
temp->data=datos;
temp->link=NULL;
if(*back==NULL){
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
printf("Los nuevos valores generados son: \n");
while (temp!=NULL)
{
    printf("%d\t",temp->data);
    temp=temp->link;
}
printf("\n");
}
void mostrar_pares(struct node *front){
struct node *temp = NULL;
temp=front;
printf("Los valores pares son: \n");
while (temp!=NULL)
{
    if(temp->data%2==0){
 printf("%d\t",temp->data);
    }
    temp=temp->link;
}
printf("\n");
}
