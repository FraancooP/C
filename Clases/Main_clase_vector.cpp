#include <iostream>
#include "my_class.h"

using namespace std;

int main(int argc, char *argv[]) {
	int i=0;
	my_class a[10];
	for(i=0; i<10;i++){
		a[i].setData(i);
	}
	
	for(i=0; i<10;i++){
		a[i].printData();
	}
	return 0;
}

