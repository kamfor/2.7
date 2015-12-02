#ifndef LIST_H
#define LIST_H

#include <stdlib>
#include <cstring>

typedef struct Element{
	struct element *prev;
	struct element *next; 
	void *obj; 
} Element;	

typedef struct List{
	element head; 
	element tail;
	int lenght; 
} List; 
	

int addnode(void *, List *); 
int delnode(Element *,List *); 
int dellist(List *); 

Element findit(List *, void *); 
#endif
