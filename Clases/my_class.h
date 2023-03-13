#include <iostream>
using namespace std;

class my_class{
private:
	int data;
public:
	my_class(); //constructor por defecto
	my_class(int); //constructor con datos
	void setData(int);
	void printData(void);
	~my_class(); //destructor
	
};

//DESARROLLO DE LAS FUNCIONES

my_class::my_class(){ //constructor por defecto
	cout<<"Construyendo sin datos"<<endl;
}

my_class::my_class(int d){  //constructor con datos
	data=d;
	cout<<"Construyendo con datos"<<endl;
}

void my_class::setData(int d){
	data=d;
}

void my_class::printData(void){
	cout<<"Data value "<<this->data<<endl; //this es el puntero para acceder directamente a los atributos de esta clase
}

my_class::~my_class(){ //destructor
	cout<<"Destruyendo"<<endl;
}
	
