#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "list.h"

typedef struct Presenter{}; 

typedef struct {
	char pn[16];
	char name[64];  
	char type[128];
	Presenter * owner;
	List listofcat;  
}Presentation;
	
typedef struct {
	char pn[16]; 
	char name[64]; 
	char surname[64]; 
	char affiliation[128]; 
	char gen[64]; 
	char payment[32];
	List listofpresentations;
	List listofcat; 
}Presenter; 

int AddPresenter(); 
int AddPresentation();
Presenter * FindPresenter(char[]); 
Presentation * FindPresentation(char[]); 
int DeletePresenter(Presenter *); 
int DeletePresentation(Presentation *); 
int UpdatePresenter(Presenter *); 
int UpdatePresentation(Presentation *); 
int PrintPresenterTable(int); 
int PrintPresentationTable(int); 


#endif
