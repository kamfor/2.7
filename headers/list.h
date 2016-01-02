#ifndef LIST_H
#define LIST_H

#include <stdlib>
#include <cstring> 

typedef struct Element{
	struct Element *prev;
	struct Element *next; 
	void * obj; 
} Element;	

typedef struct List{
	Element * head; 
	Element * tail;
	int lenght; 
} List; 
	

int addnode(void *, List *); 
int delnode(Element *,List *); 
int dellist(List *); 
#endif
