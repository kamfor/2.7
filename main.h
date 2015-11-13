#ifndef main.h
#define main.h 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Presenter{}; 

struct Presentation{
	int pn; 
	char type[20];
	Presenter *pointer; 
};
	
	

struct Presenter {
	char name[20]; 
	char surname[30]; 
	char affiliation[20]; 
	char gen[10]; 
	char payment[20]; 
	Presentation  **prespointer; 
	int pn; 
}; 

Presenter *tabPr; 
Presentetion *tabPn; 

#endif


