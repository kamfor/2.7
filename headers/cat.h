#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

#include "list.h"

typedef struct Cat{
	char name[64];
	char type[32];
	List listofelements; 
}; 

int CreateCat(char[], char[]); 
int PrintCat(Cat); 
int AddToCat(void *, Cat *); 

#endif


