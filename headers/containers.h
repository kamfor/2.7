#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Presenter{}; 

typedef struct {
	int pn;
	char name[64];  
	char type[128];
	Presenter * owner;
	List listofcat;  
}Presentation;
	
typedef struct {
	int pn; 
	char name[64]; 
	char surname[64]; 
	char affiliation[128]; 
	char gen[64]; 
	char payment[32];
	List listofpresentations;
	List listofcat; 
}Presenter; 

typedef struct {
	char name[64]; 
	char type[32]; 
	List listofelements; 
}Cat;
// functions of containers from functions.h 
#endif
