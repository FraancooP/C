#include <iostream>
#include "my_class.h"

using namespace std;

int main(int argc, char *argv[]) {
	int i=0;
	my_class a[10];
	my_class *p;
	for(i=0; i<10;i++){
		a[i].setData(i);
	}
	p=a;
	for(i=0;i<10;i++){
		(p+i)->printData();
	}
	return 0;
}

