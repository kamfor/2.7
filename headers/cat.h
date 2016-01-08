#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

#include "list.h"

typedef struct Cat{
	char name[64];
	char type[32];
	List listofelements; 
}; 

void PrintCatHeader(FILE *); 
int PrintCat(Cat, FILE*pn); 
int AddToCat(void *, Cat *); 
void PrintCatTable(FILE *); 
List * FindInCats(char[] id); 
Cat * AddCat(char[]); 
#endif


