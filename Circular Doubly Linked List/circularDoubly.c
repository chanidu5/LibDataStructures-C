#include<stdio.h>
#include<stdlib.h>
#include "circularDoubly.h"

void init(struct circularDoubly *list){
	list -> tail = NULL;
	list -> size = 0;
}


void addElement(struct circularDoubly *list, int value){
	
    	struct node *newNode = malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Allocation is failed \n");
	}

	newNode -> data = value;

	if(list -> tail == NULL){
		newNode -> next = newNode;
		newNode -> prev = newNode;
	}
	else{
		newNode -> prev = list -> tail;
		newNode -> next = list -> tail -> next;
		list -> tail -> next -> prev = newNode;
		list -> tail -> next = newNode;
	}
	list -> tail = newNode;

	list -> size++;
}

void memoryClean(struct circularDoubly *list){
	struct node *current = list -> tail -> next;
	struct node *temp;
	struct node *head = list -> tail -> next;
    	do{
	    	temp = current;
	    	free(current);
		current = temp -> next;
    	}while(current != head);

	list -> tail = NULL;
	list -> size = 0;

	
}

