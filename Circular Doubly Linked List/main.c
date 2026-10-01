#include<stdio.h>
#include "circularDoubly.h"

int main(){

	struct circularDoubly list;

	init(&list);

	int value1 = 34;
	int value2 = 76;
	int value3 = 814;
	int value4 = 77004;

	addElement(&list, value1);
	memoryClean(&list);
}
