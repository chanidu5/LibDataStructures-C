#ifndef LIST_H
#define LIST_H

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct circularDoubly{
	struct node *tail;
	int size;
};

void addElement(struct circularDoubly *list, int value);
void memoryClean(struct circularDoubly *list);
void init(struct circularDoubly *list);
#endif
