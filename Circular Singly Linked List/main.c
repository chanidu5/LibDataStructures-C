#include<stdio.h>
#include "circularsingly.h"

int main(){

	struct circularSingly list;
	init(&list);
	int value4 = 90002;
	int value1 = 23;
	addElement(&list, value1);
	int value2 = 123;
	addElement(&list, value2);
	int value3 = 4423;
	addElement(&list, value3);
	print(&list);

	addBeginning(&list, value4);
	print(&list);
	
	//addEnd(&list, value1);
	addPosition(&list, value4, 3);
	print(&list);

	deleteBeginning(&list);
	print(&list);

	deleteEnd(&list);
	print(&list);
	return 0;
}
