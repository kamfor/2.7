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
	List presentations;
}Presenter; 

Presenter * AddPresenter(char *); 
Presentation *  AddPresentation(char *);
Element * FindPresenter(char[]); 
Element * FindPresentation(char[]); 
int DeletePresenter(Presenter *); 
int DeletePresentation(Presentation *); 
int UpdatePresenter(Presenter *); 
int UpdatePresentation(Presentation *); 
void PrintPresenterFile(FILE *);
void PrintSortedPresenterTable(int);
void PrintPresenterLine(Presenter *,FILE *);   
void PrintPresentationFile(FILE *);
void PrintSortedPresentationTable(int);
void PrintPresentationLine(Presentation *,FILE *);   
/*compare function*/ 
int ComparePresenterName(const void *, const void *); 
int ComparePresenterSurname(const void *, const void *); 
int ComparePresenterAffiliation(const void *, const void *); 
int ComparePresenterGen(const void *, const void *); 
int ComparePresenterPayment(const void *, const void *);
int ComparePresenterPresentations(const void *, const void *);  
int ComparePresentationName(const void *, const void *); 
int ComparePresentationType(const void *, const void *); 
#endif
