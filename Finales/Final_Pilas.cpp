/*Desarrolle un programa que cree una estructura llamada Calificaciones de la 
materia Ingles, en la cual tiene los siguientes atributos: nombre de alumno,
nota1, nota2, nota3, recuperatorio, nota final, resultado. La nota final  es 
el promedio de las 3 notas y en el caso de que tuvo un ausente o reprobï¿½ una 
instancia,
puede rendir el recuperatorio. La carga de las notas 1,2, 3 y recuperatorio 
deben ser
aleatorias entre 0 y 10. En caso de que la nota o el recuperatorio sea 0
significa q
es ausente. En caso de que el alumno haya aprobado las 3 instancias, no rinde
recuperatorio 
entonces su valor es -1. En el caso de que el alumno se ausenta en una instancia
y en el 
recuperatorio pieden la posibilidad de aprobar (no se le calcula el promedio)
Luego crear una lista de calificaciones, y cargar los datos del informe de 
calificaciones.
El promedio debe ser calculado por una funciï¿½n. Una vez cargada la lista, mostrar
un menu de opciones con los siguientes datos:
1. Mostrar el listado de calificaciones del curso.
2. Borrar un alumno
2. Mostrar el mejor alumno. (En caso de que haya mas de uno, mostrarlos a todos)
3. Mostrar todos los alumnos que reprobaron (promedio menor a 4).
4. Mostrar todos los alumnos que aprobaron (promedio mayor o igual a 4).
5. Mostrar todos los alumnos que tuvieron al menos un ausente (nota 1,2 o 3 tiene un 0).
5. Contar cuantos alumnos en total hay en el curso.
6. Grabar un archivo llamado calificaciones.txt en donde se listen los datos, por ejemplo:
INFORME DE CALIFICACIONES DE INGLES
Alumno       Nota1        Nota2        Nota3        Recup.       Promedio           Resultado
Vilma           10             8           2           -1           6.66            Aprobado
Bety            8              0           5            6           6.33            Aprobado
Pablo           9              7           0            0           0               Reprobado
Pedro           2              0           4            2           2.66            Reprobado*/
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;
struct Calificaciones{
	char nombre_alumno[50];
	int nota_1;
	int nota_2;
	int nota_3;
	int recuperatorio;
	float promedio;
	char resultado[50];
};
struct node{
	struct Calificaciones c;
	struct node *next;
};
void push(struct node **, struct Calificaciones);
int notas();
int recuperatorio(int, int, int, int);
bool isempty(struct node **);
float promedio(int, int, int);
void mostrar(struct node **);
void pop(struct node **);
void grabar_archivo(struct node **, FILE *fp);
void check_null(FILE *fp);
void mejor_alumno(struct node **);
void alumnos_reprobaron(struct node **);
void alumnos_aprobaron(struct node **);
void faltaron(struct node **);
int main(int argc, char *argv[]) {
	srand(time(NULL));
	struct node *stackptr = NULL;
	struct Calificaciones c;
	FILE *fp=NULL;
	char op=' ',sele=' ';
	int max=0, contador=0;
	char nombre_main[50];
	do{
		printf("Bienvenido, a continuacion, seleccione una opcion.\n");
		printf("A)Cargar alumnos.\n");
		printf("B)Mostrar listado de calificaciones.\n");
		printf("C)Borrar un alumno(Ultimo de la pila).\n");
		printf("D)Mostrar el mejor alumno.\n");
		printf("E)Mostrar todos los que reprobaron.\n");
		printf("F)Mostrar todos los que aprobaron.\n");
		printf("G)Mostrar todos los que faltaron 1 vez.\n");
		printf("H)Mostrar total de alumnos del curso.\n");
		printf("I)Grabar en un archivo txt.\n");
		scanf(" %c",&sele);
		switch(sele){
		case 'a':
		case 'A':
			printf("¿Cuantos alumnos desea cargar?\n");
			scanf("%d",&max);
			contador=contador+max;
			for(int i=0;i<max;i++){
				printf("Nombre del alumno:\n");
				scanf("%s",&nombre_main[0]);
				strcpy(c.nombre_alumno,nombre_main);
				push(&stackptr, c);
			}
			break;
		case 'b':
		case 'B':
			mostrar(&stackptr);
			break;
		case 'c':
		case 'C':
			contador=contador-1;
			pop(&stackptr);
			break;
		case 'd':
		case 'D':
			mejor_alumno(&stackptr);
			break;
		case 'e':
		case 'E':
			alumnos_reprobaron(&stackptr);
			break;
		case 'f':
		case 'F':
			alumnos_aprobaron(&stackptr);
			break;
		case 'g':
		case 'G':
			faltaron(&stackptr);
			break;
		case 'h':
		case 'H':
			printf("Hay un total de %d alumnos registrados.\n",contador);
			break;
		case 'i':
		case 'I':
			grabar_archivo(&stackptr, fp);
			break;
		default:
			printf("No se selecciono ninguna opcion propuesta.\n");
			break;
		}
		printf("Desea continuar? S/N");
		scanf(" %c",&op);
	}while(op=='s');
	printf("Gracias, que tenga un buen dia.\n");
	return 0;
}
void push(struct node **sp, struct Calificaciones c){
	struct node * new_node = NULL;
	c.nota_1=notas();
	c.nota_2=notas();
	c.nota_3=notas();
	c.promedio=promedio(c.nota_1,c.nota_2,c.nota_3);
	if(c.promedio!=0){
		c.recuperatorio=-1;
	}else{
		c.recuperatorio=rand()%11;
		c.promedio=recuperatorio(c.nota_1,c.nota_2,c.nota_3,c.recuperatorio);
	}
	if(c.promedio>=6){
		strcpy(c.resultado,"Aprobado");
	}else{
		strcpy(c.resultado,"Desaprobado");
	}
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("No hay memoria suficiente.\n");
		exit(0);
	}
	new_node->c=c;
	new_node->next=*(sp);
	*(sp)=new_node;
}
int notas(){
	int nota=rand()%11;
	return nota;
}
int recuperatorio(int nota1, int nota2, int nota3, int recu){
	float prom=0.0f;
	if((nota1 or nota2 or nota3)==0 and (recu==0)){
		prom=0;
	}else{
		if(nota1 and nota2>=4){
			prom=(recu+nota2+nota3)/3.0;
		}else if(nota1 and nota3>=4){
			prom=(recu+nota1+nota2)/3.0;
		}else if(nota2 and nota3>=4){
			prom=(recu+nota2+nota3)/3.0;
		}
	}
	return prom;
}
float promedio(int nota1, int nota2, int nota3){
	float promedio=(nota1+nota2+nota3)/3.0;
	if(promedio>=6){
		return promedio;
	}
	return 0;
}
void mostrar(struct node **sp){
	struct node *temp=NULL;
	temp=*(sp);
	printf("Alumnos:\n");
	printf("Nombre\tNota1\tNota2\tNota3\tRecuperatorio\tPromedio\tResultado\n");
	while(temp!=NULL){
		printf("%s\t%d\t%d\t%d\t%d\t\t%.2f\t\t%s\n",temp->c.nombre_alumno,temp->c.nota_1,temp->c.nota_2,temp->c.nota_3,temp->c.recuperatorio,temp->c.promedio,temp->c.resultado);
		temp=temp->next;
	}
}
bool isempty(struct node **sp){
	if(*(sp)==NULL){
		return (false);
	}else{
		return(true);
	}
}
void pop(struct node **sp){
	struct node *temp=NULL;
	if(isempty(sp)==0){
		printf("La pila esta vacia.\n");
		exit(0);
	}else{
		temp=*(sp);
		*(sp)=(*sp)->next;
		free(temp);
	}
	printf("Dato borrado.\n");
}
void check_null(FILE *fp){
	if(fp==NULL){
		printf("Imposible abrir el archivo.\n");
			exit(1);
	}
}
void grabar_archivo(struct node **sp, FILE *fp){
	fp=fopen("./Lista_de_alumnos.txt", "w");
	check_null(fp);
	struct node *temp = NULL;
	temp=*(sp);
	fprintf(fp,"Nombre\tNota1\tNota2\tNota3\tRecuperatorio\tPromedio\tResultado\n");
	while(temp!=NULL){
		fprintf(fp, "%s\t%d\t%d\t%d\t%d\t\t%.2f\t\t%s\n",temp->c.nombre_alumno,temp->c.nota_1,temp->c.nota_2,temp->c.nota_3,temp->c.recuperatorio,temp->c.promedio,temp->c.resultado);
		temp=temp->next;
	}
	fclose(fp);
	printf("Archivo grabado en Lista_de_alumnos_listas.\n");
}
void mejor_alumno(struct node **sp){
	struct node *temp=NULL;
	float mayor_promedio=0.0f;
	if(*(sp)==NULL){
		printf("No hay alumnos cargados.\n");
		return;
	}
	temp=*(sp);
	while(temp!=NULL){
		if(mayor_promedio<temp->c.promedio){
			mayor_promedio=temp->c.promedio;
		}
		temp=temp->next;
	}
	temp=*(sp);
	printf("Alumno\tPromedio\n");
	while(temp!=NULL){
		if(temp->c.promedio==mayor_promedio){
			printf("%s\t%.2f\n",temp->c.nombre_alumno,temp->c.promedio);
		}
		temp=temp->next;
	}
}
void alumnos_reprobaron(struct node **sp){
	struct node *temp=NULL;
	if(*(sp)==NULL){
		printf("No hay alumnos cargados.\n");
		return;
	}
	temp=*(sp);
	printf("Nombre\tPromedio\n");
	while(temp!=NULL){
		if(temp->c.promedio<6){
			printf("%s\t%.2f\n",temp->c.nombre_alumno,temp->c.promedio);
		}
		temp=temp->next;
	}
}
void alumnos_aprobaron(struct node **sp){
	struct node *temp=NULL;
	if(*(sp)==NULL){
		printf("No hay alumnos cargados.\n");
		return;
	}
	temp=*(sp);
	printf("Nombre\tPromedio\n");
	while(temp!=NULL){
		if(temp->c.promedio>=6){
			printf("%s\t%.2f\n",temp->c.nombre_alumno,temp->c.promedio);
		}
		temp=temp->next;
	}
}
void faltaron(struct node **sp){
	struct node *temp=NULL;
	if(*(sp)==NULL){
		printf("No hay alumnos cargados.\n");
		return;
	}
	temp=*(sp);
	printf("Alumnos Ausentes:\n");
	while(temp!=NULL){
		if(temp->c.nota_1==0 or temp->c.nota_2==0 or temp->c.nota_3==0 or temp->c.recuperatorio==0){
			printf("%s\n",temp->c.nombre_alumno);
		}
		temp=temp->next;
	}
}
