/*Determinar la suma de los primeros "n" números naturales.
Por ejemplo: Ingresa 3. Entonces debería mostrar 1+2+3=6.*/
#include <iostream>
using namespace std;
int calcular_suma(int);
int main(int argc, char *argv[]) {
	int num=0;
	cout<<"Ingrese que numero desea sumar: "<<endl;
	cin>>num;
	for(int i=1;i<num+1;i++){
		cout<<i;
		if(i<num)
			cout<<" + ";
	}
	cout<<" = "<<calcular_suma(num);
	return 0;
}
int calcular_suma(int num){
	if(num==0){ //caso base
		return 0;
	}else if(num==1){ //caso base
		return 1;
	}else{ //caso recursivo
		return num+calcular_suma(num-1);
	}
}
