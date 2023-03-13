#include <iostream>
#include "my_class.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	my_class a;
	my_class *p;
	a.setData(1234);
	a.printData();
	p=&a;
	p->printData();
	p->setData(12);
	p->printData();
	
	return 0;
}

