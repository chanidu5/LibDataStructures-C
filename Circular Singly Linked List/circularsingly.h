#ifndef DLIST_H
#define DLIST_H

struct node{
	int data;
	struct node *next;
};

struct circularSingly{

	struct node *tail;
	int size;
};

void init(struct circularSingly *list);
void addElement(struct circularSingly *list, int value);

void addBeginning(struct circularSingly *list, int value);
void print(struct circularSingly *list);
void addPosition(struct circularSingly *list, int value, int position);
void addEnd(struct circularSingly *list, int value);
void deleteBeginning(struct circularSingly *list);
void deleteEnd(struct circularSingly *list);


#endif