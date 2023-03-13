#include <iostream>//DECLARAMOS LAS LIBRERIAS....
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include<windows.h>//Libreria de colores.
#include "Tratamiento.h"//LLAMAMOS A LA CLASE Tratamiento.h
using namespace std;
//DECLARAMOS ESTRUCTURAS---------------------------------------------------------
struct dias
{
    int dia;
    int mes;
    int horas;
    int minutos;
};
struct clima
{
    float temp;
    float humedad;
    struct dias time;
};
struct ciudad
{
    struct ciudad *next;
    struct clima clime;
    int ciudad_id;
	int provincia;
    char nombre_ciudad[50];
};
//-------------------------------------------------------------------------------
//DECLARAMOS FUNCIONES PARA TRABAJAR CON LAS PILAS-------------------------------
void check(FILE *fp);//CHECK EXISTENCIA ARCHIVO.
void promedio_temp_provincias(struct ciudad *, struct ciudad *, struct ciudad *);//CALCULO PROMEDIO PROVINCIAS.
void promedio_temp_ciudad(struct ciudad *);//PROMEDIO DE CADA CIUDAD, MANDAMOS TODOS LOS DATOS.
void ciudad_mas_calidad_provincias(struct ciudad *, struct ciudad *, struct ciudad *);//CIUDAD MAS CALIDA POR PROVINCIA.
void ciudad_mas_fria_provincias(struct ciudad *,struct ciudad *, struct ciudad *);//CIUDAD MAS FRIA POR PROVINCIA.
void dia_mas_frio_provincia(struct ciudad *, struct ciudad *, struct ciudad *);//DIA MAS FRIO POR PROVINCIA.
void dia_mas_calido_ciudad(struct ciudad *);//DIA MAS CALIDO POR CIUDAD, MANDAMOS TODOS LOS DATOS.
//-------------------------------------------------------------------------------
int main(int argc, char *argv[]){
	Tratamiento t;//DECLARAMOS OBJETO DE LA CLASE
    struct ciudad *stakptr=NULL;//ACA ALMACENAMOS TODOS LOS DATOS DE ARCHIVO, TODOS.
    struct ciudad *new_node=NULL;
	struct ciudad *new_node2=NULL;//DECLARMAOS OTRO NODO PARA QUE NO SE SOBRE ESCRIBAN LOS DATOS EN LOS HEAD 1 2 y 3-
	struct ciudad *head_1=NULL;//PILA QUE SOLO CONTIENE CORDOBA.
	struct ciudad *head_2=NULL;//PILA QUE SOLO CONTIENE SANTA FE.
	struct ciudad *head_3=NULL;//PILA QUE SOLO CONTIENE MENDOZA.
    char op=' ',cass=' ',nombre[50];
	int id=0,valor=0,horas=0,minutos=0,dias=0,meses,bloque=219;
    float hum=0.0f,tempe=0.0f;
    FILE *fp;
    fp = fopen("data_set.txt","r");
    check(fp);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);//UTILIZAMOS ESTE CODIGO PARA MOSTRAR CON DISTINTOS COLORES.
	printf("MENU DE OPCIONES: \n");
	//LECTURA DEL ARCHIVO CON FSCAN Y CARGA DE DATOS EN HEADS 1 2 y 3 Y STAKPTR---------------------------------------------
    while (fscanf(fp,"%d %d %s %f %f %d %d %d %d", &id,&valor,&nombre,&tempe,&hum,&horas,&minutos,&dias,&meses) != EOF){
        new_node = (struct ciudad *) malloc(sizeof(ciudad));
		new_node = (struct ciudad *) new_node;
		//---------------------------------------------------------------------------------
		if(new_node == NULL) {
			cout<<"No hay memoria disponible"<<endl;
			exit(0);
		}
        new_node->ciudad_id=id;
        new_node->provincia=valor;
		for(int i=0;i<50;i++){
			new_node->nombre_ciudad[i] = nombre[i];
		}
        new_node->clime.temp=tempe;
        new_node->clime.humedad=hum;
        new_node->clime.time.horas=horas;
        new_node->clime.time.minutos=minutos;
        new_node->clime.time.dia=dias;
        new_node->clime.time.mes=meses;
		new_node->next = stakptr;
		stakptr = new_node;//GUARDAMOS TODO EN STAK
		switch(valor){
		case 1:
			new_node2=NULL;
			new_node2 = (struct ciudad *) malloc(sizeof(ciudad));
			new_node2 = (struct ciudad *) new_node2;
			new_node2->ciudad_id=id;
			new_node2->provincia=valor;
			for(int i=0;i<50;i++){
				new_node2->nombre_ciudad[i] = nombre[i];
			}
			new_node2->clime.temp=tempe;
			new_node2->clime.humedad=hum;
			new_node2->clime.time.horas=horas;
			new_node2->clime.time.minutos=minutos;
			new_node2->clime.time.dia=dias;
			new_node2->clime.time.mes=meses;
			new_node2->next = head_1;
			head_1 = new_node2;//GUARDAMOS SOLAMENTE CORDOBA
			break;
		case 2:
			new_node2=NULL;
			new_node2 = (struct ciudad *) malloc(sizeof(ciudad));
			new_node2 = (struct ciudad *) new_node2;
			new_node2->ciudad_id=id;
			new_node2->provincia=valor;
			for(int i=0;i<50;i++){
				new_node2->nombre_ciudad[i] = nombre[i];
			}
			new_node2->clime.temp=tempe;
			new_node2->clime.humedad=hum;
			new_node2->clime.time.horas=horas;
			new_node2->clime.time.minutos=minutos;
			new_node2->clime.time.dia=dias;
			new_node2->clime.time.mes=meses;
			new_node2->next = head_2;
			head_2 = new_node2;//GUARDAMOS SOLAMENTE SANTA FE
			break;
		case 3:
			new_node2=NULL;
			new_node2 = (struct ciudad *) malloc(sizeof(ciudad));
			new_node2 = (struct ciudad *) new_node2;
			new_node2->ciudad_id=id;
			new_node2->provincia=valor;
			for(int i=0;i<50;i++){
				new_node2->nombre_ciudad[i] = nombre[i];
			}
			new_node2->clime.temp=tempe;
			new_node2->clime.humedad=hum;
			new_node2->clime.time.horas=horas;
			new_node2->clime.time.minutos=minutos;
			new_node2->clime.time.dia=dias;
			new_node2->clime.time.mes=meses;
			new_node2->next = head_3;
			head_3 = new_node2;//GUARDAMOS SOLAMENTE MENDOZA
			break;
		}
    }
    fclose(fp);
//---------------------------------------------------------------------------------------------
//MENU DE OPCIONES-----------------------------------------------------------------------------
    do
    {
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),1);
		printf("%c	%c	%c	%c	%c	%c	%c	%c	\n",bloque,bloque,bloque,bloque,bloque,bloque,bloque,bloque);
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),2);
		printf("Elija una de las siguintes opciones.\n");
        printf("A)Total de temperaturas almacenadas por provincia.\n");
        printf("B)Temperatura promedio de cada provincia.\n");
        printf("C)Temperautra promedio de cada ciudad.\n");
        printf("D)Ciudad mas calida de todas las provincias.\n");
        printf("E)Ciudad mas fria de cada provincia.\n");
        printf("F)Dia mas frio de cada provincia.\n");
        printf("G)Dia mas calido de cada ciudad.\n");
        printf("H)Mejor provincia para cultivar pimientos.\n");//Temperatura promedio cercana a 23 C
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),1);
		printf("%c	%c	%c	%c	%c	%c	%c	%c	\n",bloque,bloque,bloque,bloque,bloque,bloque,bloque,bloque);
		scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);//LINEAS DE ESTE TIPO SON ASIGNACION DE COLORES.
			t.cantMuestras();//ACCEDEMOS A LOS METODOS DEL OBJETO CREADO DE LA CLASE Tratamiento.
            break;
        case 'b':
        case 'B':
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),13);
			promedio_temp_provincias(head_1,head_2,head_3);//LLAMADA DE FUNCIONES....
            break;
        case 'c':
        case 'C':
			
			promedio_temp_ciudad(stakptr);//LLAMADA DE FUNCIONES....
            break;
        case 'd':
        case 'D':
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
			ciudad_mas_calidad_provincias(head_1,head_2,head_3);//LLAMADA DE FUNCIONES....
            break;
        case 'e':
		case 'E':
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
			ciudad_mas_fria_provincias(head_1,head_2,head_3);//LLAMADA DE FUNCIONES....
            break;
        case 'f':
        case 'F':
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
			dia_mas_frio_provincia(head_1, head_2, head_3);//LLAMADA DE FUNCIONES....
            break;
        case 'g':
        case 'G':
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),8);
			dia_mas_calido_ciudad(stakptr);//LLAMADA DE FUNCIONES....
            break;
        case 'h':
        case 'H':
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),9);
			t.promPimientos();//CLASE TRATAMIENTO
            break;
        default:
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),11);
        printf("No se eligio ninunga opcion propuesta.\n");
            break;
        }
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),11);
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),6);
        printf("Desea continuar?S/N");
        scanf(" %c",&op);
    } while (op=='s' && 'S');
//-----------------------------------------------------------------------------------FIN DEL MENU
    return 0;
}
//DESARROLO DE FUNCIONES------------------------------------------------------------------------------------------------------------------------------------
void check(FILE *fp){
	//CHECKEO EXISTENCIA DEL ARCHIVO.
    if (fp==NULL)
    {
        printf("Imposible abrir el archivo.\n");
        exit(1);
    }
}
void promedio_temp_provincias(struct ciudad *head_1, struct ciudad *head_2, struct ciudad *head_3){
	float suma=0.0f,promedio=0.0f,cant=0.0f;
	struct ciudad *temp=NULL;
	temp=head_1;
	while(temp!=NULL){
		cant++;//Este contador, sera la cantidad de tempertaturas registradas.
		suma=(suma+temp->clime.temp);//CALCULAMOS LA SUMA DE TODOS LAS TEMPERATURAS REGISTRADAS EN HEAD_1
		temp=temp->next;
	}
	promedio=suma/cant;//CALCULAMOS SU PROMEDIO.
	printf("PROMEDIO DE TEMPERATURAS DE CORDOBA: %f\n",promedio);
	//REINICIAMOS LA SUMA Y PROMEDIO.
	suma=0;
	promedio=0;
	cant=0;
	temp=head_2;
	while(temp!=NULL){
		cant++;//Este contador, sera la cantidad de tempertaturas registradas.
		suma=(suma+temp->clime.temp);//CALCULAMOS LA SUMA DE TODOS LAS TEMPERATURAS REGISTRADAS EN HEAD_2
		temp=temp->next;
	}
	promedio=suma/cant;//CALCULAMOS SU PROMEDIO.
	printf("PROMEDIO DE TEMPERATURAS DE SANTA FE: %f\n",promedio);
	//REINICIAMOS LA SUMA Y PROMEDIO
	suma=0;
	promedio=0;
	cant=0;
	temp=head_3;
	while(temp!=NULL){
		cant++;//Este contador, sera la cantidad de tempertaturas registradas.
		suma=(suma+temp->clime.temp);//CALCULAMOS LA SUMA DE TODOS LAS TEMPERATURAS REGISTRADAS EN HEAD_3
		temp=temp->next;
	}
	promedio=suma/cant;//CALCULAMOS SU PROMEDIO.
	printf("PROMEDIO DE TEMPERATURAS DE MENDOZA: %f\n",promedio);
	//REINICIAMOS LA SUMA Y PROMEDIO
	suma=0;
	promedio=0;
	cant=0;
}
void promedio_temp_ciudad(struct ciudad *sp){
	//DECLARAMOS LOS TIPOS DE DATOS PARA CALCULAR EL PROMEDIO DE CADA CIUDAD
	float promedio=0.0f,suma=0.0f;
	int contador=0,i=0,j=0;
	struct ciudad *temp=NULL;
	temp=sp;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);//CALCULAMOS LA SUMA DE TODAS LAS TEMPERATURAS HASTA QUE EL CONTADOR i LLEGA A 80
		i++;
		
		if(i==80){//CUANDO EL CONTADOR i LLEGO A 80, MUESTRA LA CIUDAD Y TEMPERATURA PROMEDIO QUE LE CORRESPONDE
			promedio=suma/80.0;//CALCULO DE SU PROMEDIO.
			
			j++;
			if(j==1){
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),4);	
			printf("El promedio de %s es: %f\n",temp->nombre_ciudad,promedio);
			}else if(j==2){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),6);	
				printf("El promedio de %s es: %f\n",temp->nombre_ciudad,promedio);
			}else if(j==3){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),7);	
				printf("El promedio de %s es: %f\n",temp->nombre_ciudad,promedio);
			}else if(j==4){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);	
				printf("El promedio de %s es: %f\n",temp->nombre_ciudad,promedio);
			}else if(j==5){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);	
				printf("El promedio de %s es: %f\n",temp->nombre_ciudad,promedio);
			}else if(j==6){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),5);	
				printf("El promedio de %s es: %f\n",temp->nombre_ciudad,promedio);
				j=0;
			}
			//LUEGO DE MOSTRAR, REINICIAMOS EL CONTADOR i, suma y promedio y repetimos el proceso hasta que se llegemos al final del archivo.
			i=0;
			suma=0;
			contador++;
		}
		temp=temp->next;
	}
	printf("EL TOTAL DE MUESTRAS ES: %d\n",contador);//VERIFICAMOS QUE SE REGISTREN 100 CIUDADES.
}
void ciudad_mas_calidad_provincias(struct ciudad *head_1, struct ciudad *head_2, struct ciudad *head_3){
	struct ciudad *temp=NULL;
	//DECLARAMOS,TIPOS DE DATOS PARA BUSCAR MAYOR TEMPERATURA, Y MAYOR PROMEDIO ENTRE TEMPERATURAS
	float suma=0.0f, mayor_temp=0.0f,promedio=0.0f;
	char nombre[50];
	int i=0;
	temp=head_1;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);//CALCULAMOS LA SUMA DE TODAS LAS TEMPERATUAS EN EL HEAD 1 HASTA QUE EL CONTADOR i llegue a 80
		i++;
		if(i==80){//CUANDO EL CONTADOR i LLEGO A 80, CALCULAMOS UN PROMEDIO, Y COMPARAMOS ESTE PROMEDIO CON EL VALOR ANTERIOR GUARDADO(0),
			      //PARA REALIZAR LA BUSQUEDA DEL MAYOR PROMEDIO
			promedio=suma/80.0;
			if(promedio>mayor_temp){
				mayor_temp=promedio;//UNA VEZ QUE GUARDAMOS EL PROMEDIO MAS GRANDE, COPIAMOS EL NOMBRE DE LA CIUDAD A LA QUE LE CORRESPONDE
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			//REINICIAMOS CONTADOR Y REPETIMOS PROCESO.
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	//UNA VEZ REGISTRADO EL PROMEDIO MAS GRANDE, MOSTRAMOS SU CIUDAD CON SU PROMEDIO CORRESPONDIENTE.
	printf("LA CIUDAD MAS CALIDA DE CORDBA ES: %s , con una temperatura promedio de: %f\n",nombre,mayor_temp);
	//MISMOS PASOS QUE EN EL HEAD_1----------------------------------------------------------------------------------------------------------------------
	suma=0;
	i=0;
	mayor_temp=0;
	temp=head_2;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio>mayor_temp){
				mayor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS CALIDA DE SANTA FE ES: %s , con una temperatura promedio de: %f\n",nombre,mayor_temp);
	suma=0;
	i=0;
	mayor_temp=0;
	temp=head_3;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio>mayor_temp){
				mayor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS CALIDA DE MENDOZA ES: %s , con una temperatura promedio de: %f\n",nombre,mayor_temp);
	//----------------------------------------------------------------------------------------------------------------------
}
void ciudad_mas_fria_provincias(struct ciudad *head_1, struct ciudad *head_2, struct ciudad *head_3){
	//PARA REALIZAR ESTA FUNCION, HICIMOS LO MISMO QUE EN LA FUNCION DE BUSCAR EL PROMEDIO MAS ALTO PERO EN ESTE CASO, BUSCAMOS EL PROMEDIO MAS BAJO-----
	//CALCULAMOS EL PROMEDIO DE TODAS LAS CIUDADES DE CADA PROVINCIA, Y BUSCAMOS EL PROMEDIO MAS BAJO, ESTE PROMEDIO LE CORRESPONDE A LA CIUDAD MAS FRIA.
	struct ciudad *temp=NULL;
	float suma=0.0f,promedio=0.0f,menor_temp=100;//DECLARAMOS PROMEDIO Y BUSQUEDA DEL MENOR TEMP
	char nombre[50];
	int i=0;
	temp=head_1;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);//CALCULA LA SUMA DE 80 TEMPERATURAS
		i++;//CONTADOR
		if(i==80){//CALCULO EL PROMEDIO Y LO GUARDA CUANDO LLEGO A 80 MEDICIONES.
			promedio=suma/80.0;
			if(promedio<menor_temp){//COMPARA EL PROMEDIO
				menor_temp=promedio;//GUARDA EL PROMEDIO
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];//GUARDA SU NOMBRE
				}
			}
			i=0;//REINICIA EL CONTADOR
			suma=0;//REINICIA LA SUMA
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS FRIA DE CORDBA ES: %s , con una temperatura promedio de: %f\n",nombre,menor_temp);
	suma=0;
	menor_temp=100;
	temp=head_2;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio<menor_temp){
				menor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS FRIA DE SANTA FE ES: %s , con una temperatura promedio de: %f\n",nombre,menor_temp);
	suma=0;
	menor_temp=100;
	temp=head_3;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio<menor_temp){
				menor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS FRIA DE MENDOZA ES: %s , con una temperatura promedio de: %f\n",nombre,menor_temp);
}
void dia_mas_frio_provincia(struct ciudad *head_1, struct ciudad *head_2, struct ciudad *head_3){
	//PARA ESTA FUNCION, PRIMERO, BUSCAMOS LA TEMPERATURA MAS BAJA POR CIUDAD. DESPUES BUSCAMOS LA TEMPERTURA MAS BAJA ENTRE LAS
	//MAS BAJAS REGISTRADAS ANTERIORMENTE.(LA MAS CHICA ENTRE LAS MAS CHICAS)
	struct ciudad *temp=NULL;
	float menor_temp=100;
	float menor_temp_ciudad=100;
	int dia=0;
	char nombre[50];
	temp=head_1;
	while(temp!=NULL){
		if(temp->clime.temp<menor_temp){
			menor_temp=temp->clime.temp;//PRIMERO BUSCAMOS LA TEMPERATURA MAS BAJA DE CADA CIUDAD DE LA PROVINCIA(LAS TEMPERATURAS MAS CHICAS POR CIUDAD)
			if(menor_temp<menor_temp_ciudad){
				menor_temp_ciudad=menor_temp;//LUEGO, BUSCAMOS LA TEMPERATURA MAS BAJA ENTRE LAS TEMPERATURAS MAS BAJAS DE TODAS LAS CIUADES(LA CIUDAD QUE TIENE LA MAS CHICA)
			}
		}
		//UNA VEZ ENCONTRADA LA TEMPERATURA MAS CHICA DE TODA LA PROVINCIA.
		if(temp->clime.temp==menor_temp_ciudad){//IGUALAMOS LA TEMPERATURA y COPIAMOS SU CIUDAD Y DIA QUE LE CORRESPONDE
			dia=temp->clime.time.dia;
			for(int j=0;j<50;j++){
				nombre[j]=temp->nombre_ciudad[j];
			}
		}
		temp=temp->next;
	}
	printf("El dia mas frio de Cordoba es el %d, en la ciudad de %s con una temperatura de %f\n",dia,nombre,menor_temp_ciudad);
	//REINICIAMOS LAS VARIABLES Y HICIMOS LO MISMO QUE EN EL HEAD_1.
	menor_temp=100;
	menor_temp_ciudad=100;
	temp=head_2;
	while(temp!=NULL){
		if(temp->clime.temp<menor_temp){
			menor_temp=temp->clime.temp;
			if(menor_temp<menor_temp_ciudad){
				menor_temp_ciudad=menor_temp;
			}
		}
		if(temp->clime.temp==menor_temp_ciudad){
			dia=temp->clime.time.dia;
			for(int j=0;j<50;j++){
				nombre[j]=temp->nombre_ciudad[j];
			}
		}
		temp=temp->next;
	}
	printf("El dia mas frio de Santa Fe es el %d, en la ciudad de %s con una temperatura de %f\n",dia,nombre,menor_temp_ciudad);
	//REINICIAMOS LAS VARIABLES Y HICIMOS LO MISMO QUE EN HEAD_1 Y HEAD_2
	menor_temp=100;
	menor_temp_ciudad=100;
	temp=head_3;
	while(temp!=NULL){
		if(temp->clime.temp<menor_temp){
			menor_temp=temp->clime.temp;
			if(menor_temp<menor_temp_ciudad){
				menor_temp_ciudad=menor_temp;
			}
		}
		if(temp->clime.temp==menor_temp_ciudad){
			dia=temp->clime.time.dia;
			for(int j=0;j<50;j++){
				nombre[j]=temp->nombre_ciudad[j];
			}
		}
		temp=temp->next;
	}
	printf("El dia mas frio de Mendoza es el %d, en la ciudad de %s con una temperatura de %f\n",dia,nombre,menor_temp_ciudad);
}
void dia_mas_calido_ciudad(struct ciudad *sp){
	//PARA PODER ENCONTRAR EL DIA MAS CALIDO DE CADA CIUDAD, REALIZAMOS UNA BUSQUEDA EN TODO EL ARCHIVO DE LA TEMPERATURA MAYOR.
	float mayor_temp=0.0f;
	int j=0;
	int dia=0,i=0,mes=0;
	struct ciudad *temp=NULL;
	temp=sp;
	while(temp!=NULL){
		i++;
		if(temp->clime.temp>mayor_temp){//BUSCAMOS LA TEMPERTAURA MAYOR HASTA QUE EL CONTADOR LLEGUE A 80
			mayor_temp=temp->clime.temp;
			if(temp->clime.temp==mayor_temp){//AL MISMO TIEMPO, COPIAS EL DIA y MES QUE LE CORRESPONDE A ESA TEMPERATURA
				dia=temp->clime.time.dia;
				mes=temp->clime.time.mes;
			}
		}
		if(i==80){//UNA VEZ QUE EL CONTADOR LLEGO A 80, MOSTRAMOS LA CIUDAD QUE LE CORRESPONDE, CON SU DIA, MES Y TEMPERATURA REGISTRADA.
			j++;
			if(j>1 && j<15){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
				printf("El dia mas calido de %s es el: %d del mes %d, con una tempertura de: %f\n",temp->nombre_ciudad,dia,mes,mayor_temp);
			}else if(j>=15 && j<30){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),7);
				printf("El dia mas calido de %s es el: %d del mes %d, con una tempertura de: %f\n",temp->nombre_ciudad,dia,mes,mayor_temp);
			}else if(j>=30 && j<45){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
				printf("El dia mas calido de %s es el: %d del mes %d, con una tempertura de: %f\n",temp->nombre_ciudad,dia,mes,mayor_temp);
			}else if(j>=45 && j<60){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),7);
				printf("El dia mas calido de %s es el: %d del mes %d, con una tempertura de: %f\n",temp->nombre_ciudad,dia,mes,mayor_temp);
			}else if(j>=60 && j<75){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
				printf("El dia mas calido de %s es el: %d del mes %d, con una tempertura de: %f\n",temp->nombre_ciudad,dia,mes,mayor_temp);
			}else if(j>=75 && j<90){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),7);
				printf("El dia mas calido de %s es el: %d del mes %d, con una tempertura de: %f\n",temp->nombre_ciudad,dia,mes,mayor_temp);
			}else if(j>=90 && j<100){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
				printf("El dia mas calido de %s es el: %d del mes %d, con una tempertura de: %f\n",temp->nombre_ciudad,dia,mes,mayor_temp);	
			}
			//DESPUES DE MOSTRAR LA CIUDAD DIA MES Y TEMPERATURA MAS GRANDE.
			//REINICIAMOS EL CONTADOR, Y REPETIMOS EL PROCESO HASTA QUE NOS QUEDEMOS SIN DATOS.
			i=0;
			mayor_temp=0;
			dia=0;
		}
		temp=temp->next;
	}
}
