/*Desarrolle un programa que cree una estructura llamada Cargamento,
en la cual tiene los siguientes atributos: numero de cargamento,
peso del cargamento en toneladas, ceral, precio por tonelada, precio
total del cargamento. El precio total debe ser calculado por una función.
Luego crear un tda de cargamentos. Luego mostrar un menu de opciones 
con las siguientes acciones: 
1. Agregar un cargamento al TDA
2. Borrar un cargamento.
3. Mostrar todos los cargamentos.
4. Mostrar el cargamento mas pesado. 
5. Mostrar el cargamento mas liviano.
6. Mostrar la valuación total de todos los cargamentos 
(es decir la sumatoria de todos los precios totales)
7. Contar cuantos cargamentos hay en el tda.
8. Grabar un archivo llamado cargamentos.txt en donde se listen los datos,
por ejemplo:
INFORME DE CARGAMENTOS
Num      Peso(T)        Ceral        Precio(US$)        Precio Total(US$) 
1        10             Trigo        5.000                                             
2        8              Soja         10.500
3        2              Maiz         4.500
Hacer este ejercicio con lista, con pila y con cola.
El ejercicio debe mostrar los datos de manera clara y ordenada.
Agregar espacios y tabulaciones necesarias para una mejor lectura. 
El programa debe estar programada de forma modular. (usar funciones)
*/
#include <iostream>
#include <string.h>
using namespace std;
struct Cargamento{
	int numero_cargamento;
	int peso_toneladas;
	char ceral[20];
	float precio_tonelada;
	float precio_total;
};
struct node{
	struct Cargamento c;
	struct node *next;
};
void push(struct node **, struct Cargamento);
void print(struct node*);
void pop(struct node **, struct Cargamento);
float calcular_precio(int, int);
void total_precio(struct node *);
void check_null(FILE *fp);
void grabar_archivo(struct node *, FILE *fp);
void cargamento_mayor(struct node *);
void cargamento_menor(struct node *);
int main(int argc, char *argv[]) {
	struct node* head=NULL;
	struct Cargamento c;
	FILE *fp=NULL;
	char op=' ', sele=' ';
	int cantidad=0, contador=0;
	float total_precios=0.0f;
	do{
		printf("Bienvenido, a continuacion elija una opcion.\n");
		printf("A)Agregar un cargamento.\n");
		printf("B)Borrar un cargamento.\n");
		printf("C)Mostrar todos los cargamentos.\n");
		printf("D)Mostrar el cargamento mas pesado.\n");
		printf("E)Mostrar el cargamento mas liviano.\n");
		printf("F)Mostrar la recaudacio total.\n");
		printf("G)Contar cargamentos registrados.\n");
		printf("H)Grabar archivo en cargamento.txt.\n");
		scanf(" %c",&sele);
		switch(sele){
		case 'a':
		case 'A':
			printf("¿Cuantos cargamentos desea registrar?\n");
			scanf("%d", &cantidad);
			contador=contador+cantidad;
			for(int i=0;i<cantidad;i++){
				push(&head, c);
				total_precios=total_precios+c.precio_total;
			}
			break;
		case 'b':
		case 'B':
			contador=contador-1;
			pop(&head, c);
			break;
		case 'c':
		case 'C':
			print(head);
			break;
		case 'd':
		case 'D':
			cargamento_mayor(head);
			break;
		case 'e':
		case 'E':
			cargamento_menor(head);
			break;
		case 'f':
		case 'F':
			total_precio(head);
			break;
		case 'g':
		case 'G':
			printf("Se registraron un total de %d cargamentos\n",contador);
			break;
		case 'h':
		case 'H':
			grabar_archivo(head, fp);
			break;
		default:
			break;
		}
		printf("Desea continuar? S/N");
		scanf(" %c",&op);
	}while(op=='s' or op=='S');
	printf("Gracias, que tenga un buen dia.\n");
	return 0;
}
void push(struct node ** head, struct Cargamento c){
	struct node * new_node=NULL;
	int ceral=0;
	printf("Ingrese el número del cargamento.\n");
	scanf("%d",&c.numero_cargamento);
	printf("Ingrese la cantidad de cerales en toneladas.\n");
	scanf("%d",&c.peso_toneladas);
	printf("Ingrese el ceral.\n");
	printf("1)Trigo.\n");
	printf("2)Soja.\n");
	printf("3)Maiz.\n");
	scanf("%d",&ceral);
	if(ceral==1){
		strcpy(c.ceral,"Trigo");
		c.precio_tonelada=5000.0;
		c.precio_total=calcular_precio(ceral, c.peso_toneladas);
	}else if(ceral==2){
		strcpy(c.ceral,"Soja");
		c.precio_tonelada=10500.0;
		c.precio_total=calcular_precio(ceral, c.peso_toneladas);
	}else if(ceral==3){
		strcpy(c.ceral,"Maiz");
		c.precio_tonelada=4500.0;
		c.precio_total=calcular_precio(ceral, c.peso_toneladas);
	}
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("No hay memoria suficiente.\n");
		exit(0);
	}
	new_node->c=c;
	new_node->next=(*head);
	(*head)=new_node;
}
float calcular_precio(int ceral, int toneladas){
	float total=0.0f;
	if(ceral==1){
		total=toneladas*5000.0;
	}else if(ceral==2){
		total=toneladas*10500.0;
	}else if(ceral==3){
		total=toneladas*4500.0;
	}else if(ceral!=1 or ceral!=2 or ceral!=3){
		return 0;
	}
	return total;
}
void print(struct node *head){
	struct node *temp=NULL;
	temp=head;
	printf("Num_Cargamento\tPeso(T)\tCeral\tPrecio_Unidad($)\tPrecio_total($)\n");
	while(temp!=NULL){
		printf("%d\t\t%d\t%s\t%.2f\t\t\t%.2f\n",temp->c.numero_cargamento,temp->c.peso_toneladas,temp->c.ceral,temp->c.precio_tonelada,temp->c.precio_total);
		temp=temp->next;
	}
}
void pop(struct node ** head, struct Cargamento c){
	int numero_carga=0;
	printf("Ingrese el numero de cargamento que desea borrar.\n");
	scanf("%d",&numero_carga);
	struct node *temp=NULL;
	temp=*head;
	if(head==NULL){
		printf("Lista vacia\n");
		exit(1);
	}else{
		struct node* prev=NULL;
		struct node* current=NULL;
		if(((*head)->c.numero_cargamento) == numero_carga){
			temp = *head;
			*head = (*head)->next;
			free(temp);
		}else{
			prev = *head;
			current = (*head)->next;
			while(current != NULL and (current->c.numero_cargamento) != numero_carga){
				prev = current;
				current = current->next;
			}
			if(current != NULL){
				temp = current;
				prev->next = current->next;
				free(temp);
			}
		}
	}
	printf("Cargamento borrado.\n");
}
void check_null(FILE *fp){
	if(fp==NULL){
		printf("Imposible abrir el archivo.\n");
		exit(1);
	}
}
void grabar_archivo(struct node * head, FILE *fp){
	fp=fopen("./Cargamento_Listas.txt","w");
	check_null(fp);
	struct node *temp = NULL;
	temp=head;
	fprintf(fp,"Num_carga\tPeso(T)\tCeral\tPrecio($)\tTotal($)\n");
	while(temp!=NULL){
		fprintf(fp,"%d\t\t%d\t%s\t%.2f\t\t%.2f\n",temp->c.numero_cargamento,temp->c.peso_toneladas,temp->c.ceral,temp->c.precio_tonelada,temp->c.precio_total);
		temp=temp->next;
	}
	fclose(fp);
	printf("Archivo grabado en Cargamentos_listas.\n");
}
void cargamento_mayor(struct node *head){
	struct node *temp=NULL;
	if(head==NULL){
		printf("No hay cargamentos registrados.\n");
		return;
	}
	temp=head;
	int mayor=0;
	while(temp!=NULL){
		if(mayor<temp->c.peso_toneladas){
			mayor=temp->c.peso_toneladas;
		}
		temp=temp->next;
	}
	temp=head;
	printf("El cargamento mayor es:\n");
	printf("Num_carga\tPeso(T)\n");
	while(temp!=NULL){
		if(mayor==temp->c.peso_toneladas){
			printf("%d\t\t%d\n",temp->c.numero_cargamento,temp->c.peso_toneladas);
		}
		temp=temp->next;
	}
}
void cargamento_menor(struct node *head){
	struct node *temp=NULL;
	if(head==NULL){
		printf("No hay cargamentos registrados.\n");
		return;
	}
	temp=head;
	int mayor=0;
	int menor=0;
	while(temp!=NULL){
		if(mayor<temp->c.peso_toneladas){
			mayor=temp->c.peso_toneladas;
		}else{
			menor=temp->c.peso_toneladas;
		}
		temp=temp->next;
	}
	temp=head;
	printf("El cargamento menor es:\n");
	printf("Num_carga\tPeso(T)\n");
	while(temp!=NULL){
		if(menor==temp->c.peso_toneladas){
			printf("%d\t\t%d\n",temp->c.numero_cargamento,temp->c.peso_toneladas);
		}
		temp=temp->next;
	}
}
void total_precio(struct node *head){
	float total=0.0f;
	struct node *temp=NULL;
	if(head==NULL){
		printf("No hay cargamentos registrados.\n");
		return;
	}
	temp=head;
	while(temp!=NULL){
		total=total+temp->c.precio_total;
		temp=temp->next;
	}
	printf("El total de dinero recaudado es %.2f\n",total);
}
