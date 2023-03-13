#include <iostream>
#include "my_class.h"
using namespace std;

void function(my_class);

int main(int argc, char *argv[]) {
	my_class a(10);
	a.printData();
	function(a);
	a.printData();
	return 0;
}

void function (my_class obj){
	cout<<"En la funcion"<<endl;
	obj.printData();
	obj.setData(13);
	obj.printData();
}
