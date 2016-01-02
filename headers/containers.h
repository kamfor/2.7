#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include <ctype.h>
#include "headers/list.h"

typedef struct Presenter{}; 

typedef struct {
	char name[64]; 
	char type;/*0-ustna 1-plakat*/
	int pn; 
	Presenter * owner;
}Presentation;
	
typedef struct { 
	char name[64]; 
	char surname[64]; 
	char affiliation[128]; 
	char gen; /*0-brak 1-ustne 2-plakat*/
	char payment; /*0-brak 1-zaplacono*/
	int pn;  
	List  presentations;
}Presenter; 

Presenter * AddPresenter(char *); 
Presentation *  AddPresentation(char *);
Element * FindPresenter(char[]); 
Element * FindPresentation(char[]); 
int DeletePresenter(Presenter *); 
int DeletePresentation(Presentation *); 
int UpdatePresenter(Presenter *); 
int UpdatePresentation(Presentation *); 
int PrintPresenterTable(void *); 
int PrintPresentationTable(void *); 
int Compare(); /*find best result*/ 


#endif
