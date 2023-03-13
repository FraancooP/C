#include <iostream>
#include "my_class.h"

using namespace std;

int main(int argc, char *argv[]) {

	my_class a(10);
	a.printData();
	a.setData(12);
	a.printData();

	return 0;
}

