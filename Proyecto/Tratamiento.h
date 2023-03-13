class Tratamiento
{
private:
	//DECLARAMOS LOS ATRIBUTOS DE LA CLASE,(SON LOS TIPO DE DATOS ALMACENADOS EN EL ARCHIVO.)
	int ciudad_id;
	int provincia_id;
	char nombre_ciudad[50];
	float temperaturas;
	float humedades;
	int hora;
	int minutos;
	int dias;
	int mes;
public:
	//DECLARAMOS LOS METODOS PARA TRABAJAR.
    Tratamiento();//CONSTRUCTOR.
    ~Tratamiento();//DESTRUCTOR.
	void cantMuestras();//FUNCION PARA CONTADORES.
	void promPimientos();//FUNCION DE BUSQUEDA MAYOR PROMEDIO.
};
Tratamiento::Tratamiento()
{
}
Tratamiento::~Tratamiento()
{
}
void Tratamiento::cantMuestras(){
	int contador_cordoba=0,contador_santa_fe=0,contador_mendoza=0;//CONTADORES POR PROVINCIA
	FILE *fp=NULL;
	fp=fopen("./data_set.txt","r");
	if(fp==NULL){
		printf("Imposible abrir el archivo.\n");
		exit(1);
	}
	//REALIZAMOS LECTURA DEL ARCHIVO.
	while(fscanf(fp,"%d %d %s %f %f %d %d %d %d", &ciudad_id,&provincia_id,&nombre_ciudad,&temperaturas,&humedades,&hora,&minutos,&dias,&mes) != EOF){
		if(provincia_id==1){//REALIZAMOS CONTADORES EN TORNO A LA PROVINCIA ID.
			contador_cordoba++;
		}else if(provincia_id==2){
			contador_santa_fe++;
		}else if(provincia_id==3){
			contador_mendoza++;
		}
	}
	fclose(fp);
	printf("CANTIDAD DE TEMPERATURAS REGISTRADAS EN CORDOBA: %d\n",contador_cordoba);
	printf("CANTIDAD DE TEMPERATURAS REGISTRADAS EN SANTA FE: %d\n",contador_santa_fe);
	printf("CANTIDAD DE TEMPERATURAS REGISTRADAS EN MENDOZA: %d\n",contador_mendoza);
}
void Tratamiento::promPimientos(){
	int contador_cordoba=0,contador_santa_fe=0,contador_mendoza=0;//DECLARAMOS CONTADORES POR PROVINCIA
	float promedio_cordoba=0.0f,promedio_santa_fe=0.0f,promedio_mendoza=0.0f,suma_1=0.0f,suma_2=0.0f,suma_3=0.0f;//DECLARAMOS PROMEDIOS POR CADA PROVINCIA
	//Y SUMAS DE TEMPERTAURAS PARA CADA PROVINCIA
	float promedios[3]={0};//DECLARAMOS ARREGLO PARA GUARDAR LOS PROMEDIOS DE CADA PROVINCIA, SON 3
	float mayor_promedio=0.0f;//Para buscar el mayor.
	FILE *fp=NULL;
	fp=fopen("./data_set.txt","r");//ABRIMOS EL ARCHIVO COMO LECTURA
	//COMPROBACION DE QUE EXISTE------------------------------------------------------------------------------------------
	if(fp==NULL){
		printf("Imposible abrir el archivo.\n");
		exit(1);
	}
	//---------------------------------------------------------------------------------------------------------------------
	//LECTURA DEL ARCHIVO.
	//CADA TIPO DE DATO DEL ARCHIVO, LE CORRESPONDE A LOS ATRIBUTOS DE LA CLASE.
	while(fscanf(fp,"%d %d %s %f %f %d %d %d %d", &ciudad_id,&provincia_id,&nombre_ciudad,&temperaturas,&humedades,&hora,&minutos,&dias,&mes) != EOF){
		//PONEMOS LA CONDICION EN FUNCION DE LA ID DE LA PROVINCIA, 1=CORDOBA, 2=SANTE FE, 3=MENDOZA
		if(provincia_id==1){
			contador_cordoba++;//CUENTA LAS TODAS LAS MEDICIONES
			suma_1=suma_1+temperaturas;//CALCULAMOS LA SUMA DE TODAS LAS TEMPERATURAS POR PROVINCIA
		}else if(provincia_id==2){
			contador_santa_fe++;//CUENTA LAS MEDICIONES DE SANTA FE
			suma_2=suma_2+temperaturas;//SUMA TODAS LAS TEMPERTAURAS DE SANTA FE
		}else if(provincia_id==3){
			contador_mendoza++;//CUENTA MEDICIONES DE MENDOZA
			suma_3=suma_3+temperaturas;//SUMA TODAS LAS TEMPERATURAS DE MENDOZA
		}
	}
	fclose(fp);//CERRAMOS EL ARCHIVO.
	//CALCULAMOS PROMEDIOS DE CADA PROVINCIA.
	promedio_cordoba=suma_1/contador_cordoba;
	promedio_santa_fe=suma_2/contador_santa_fe;
	promedio_mendoza=suma_3/contador_mendoza;
	//GUARDAMOS LOS PROMEDIOS EN UN ARREGLO
	promedios[0]=promedio_cordoba;
	promedios[1]=promedio_santa_fe;
	promedios[2]=promedio_mendoza;
	for(int i=0;i<3;i++){//BUSCAMOS EL PROMEDIO MAS GRANDE
		if(promedios[i]>mayor_promedio){
			mayor_promedio=promedios[i];
		}
	}
	//SEGUN LOS PROMEDIOS CALCULADOS, LA TEMPERATURA PROMEDIO MAS ALTA LE CORRESPONDE A LA MAS CERCANA A 23C
	if(mayor_promedio==promedio_cordoba){
		printf("La temperatura promedio mas cercana a 23 es %f de la provincia de Cordoba.\n",mayor_promedio);
	}else if(mayor_promedio==promedio_santa_fe){
		printf("La temperatura promedio mas cercana a 23 es %f de la provincia de Santa Fe\n",mayor_promedio);
	}else if(mayor_promedio==promedio_mendoza){
		printf("La temperatura promedio mas cercana a 23 es de %f de la provincia de Mendoza\n",mayor_promedio);
	}
}
