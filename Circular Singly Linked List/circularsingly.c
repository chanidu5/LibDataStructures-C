#include<stdio.h>
#include<stdlib.h>
#include "circularsingly.h"

void init(struct circularSingly *list){

	list -> tail = NULL;
	list -> size = 0;
}

void addElement(struct circularSingly *list, int value){
	
	struct node *newNode = malloc(sizeof(struct node));

	if(newNode == NULL){
		printf("Allocation is Failed \n");
		return;
	}

	newNode -> data = value;	
	if(list -> tail == NULL){
		newNode -> next = newNode;
	}

	else{
		newNode -> next = list -> tail -> next;
		list -> tail -> next = newNode;

	}
	list -> tail = newNode;
	list -> size++;

}

void addEnd(struct circularSingly *list, int value){
	struct node *newNode = malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Allocation is Failed");
	}
	if(list -> tail == NULL){
		addBeginning(list, value);
	}
	newNode -> data = value;
	newNode -> next = list -> tail -> next;
	list -> tail -> next = newNode;

	list -> size++;
}

void print(struct circularSingly *list){
	struct node *current = list -> tail -> next;
	do{
		printf("%d", current -> data );
		current = current -> next;
		printf("\n");
	}while(current != list -> tail-> next);	
	printf("%d", list -> size);
	printf("\n\n");
}

void addBeginning(struct circularSingly *list, int value){
	struct node *newNode = malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Allocation is Failed \n");
		return;
	}
	newNode -> data = value;

	if(list -> tail == NULL){
		newNode -> next = newNode;
		list -> tail = newNode;
	}

	else{
		newNode -> next = list -> tail -> next;
		list -> tail -> next = newNode;
	}
	list -> size++;
}

void addPosition(struct circularSingly *list, int value, int position){

	if(position < 0){
		printf("Invalid Position");
		return;
	}
	else if(position > (list -> size)){
		printf("Position out of bound \n");
		return;
	}

	if(position == 1){
		addBeginning(list, value);
		return;
	}
	else if(position == list -> size){
		addEnd(list, value);
		return;
	}


	struct node *current =  list -> tail -> next;
	for(int i = 1; i < position - 1; i++){
		current = current -> next;
	}
	struct node *newNode = malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Allocation is Failed\n");
		return;
	}
	newNode -> data = value;
	newNode -> next = current -> next;
	current -> next = newNode;
	list -> size++;
	
}

void deleteBeginning(struct circularSingly *list){

	if(list -> tail == NULL){
		return;
	}
	if(list -> tail -> next == list ->  tail){
		free(list -> tail);
		list -> tail = NULL;
	}

	struct node *temp = list -> tail -> next;
	list -> tail -> next = temp  -> next;
	free(temp);
}

void deleteEnd(struct circularSingly *list){

	if(list -> tail == NULL){

		return;	
	}
	if(list -> tail == list -> tail -> next){

		free(list -> tail);
		list -> tail = NULL;

	}
	struct node *current = list -> tail -> next;

	while(current -> next != list -> tail){
		current = current -> next;
	}

	current -> next = list -> tail -> next;
	struct node *temp = list -> tail;
	list -> tail = current;

	free(temp);

}

void deletePosition(struct circularSingly *list, int position){
	
	if(position < 0 || position > list -> size){
		printf("Invalid Position \n");
		return;
	}

	if(list -> tail == NULL){
		return;
	}
	else if(list -> tail -> next == list -> tail){
		free(list -> tail);
		list -> tail = NULL;
		return;
	}

	if(position == 1){
		deleteBeginning(list);
	}
	if(position == list -> size){
		deleteEnd(list);
	}

	struct node *current = list -> tail -> next; 
	for(int i = 1; i < position - 1; i++ ){
		current = current -> next;
	}
	
	struct node *temp = current -> next;
	current -> next = temp -> next;
	free(temp);
}

void freeMemory(struct circularSingly *list){
	struct node *current = list -> tail -> next;
	struct node *head = current;
	do{
		struct node *nextNode = current -> next;
		free(current);
		current = nextNode;
	
	}while(current != head);
	list -> tail = NULL;
	list -> size = 0;
}
