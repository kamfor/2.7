#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int pn;
	char name[30];  
	char type[20];
	int owner; 
	int visible; 
}Presentation;
	
typedef struct {
	int pn; 
	char name[20]; 
	char surname[30]; 
	char affiliation[20]; 
	char gen[10]; 
	char payment[20];
	int presentation[20]; 
	int nofpresentations; 
	int visible; 
}Presenter; 

typedef struct {
	char name[20]; 
	int presenters[20];
	int amount;  
}CatPresenter; 

typedef struct {
	char name[20]; 
	int presentations[20];
	int amount;   
}CatPresentation;

Presenter *tabPr; 
Presentation *tabPn; 
CatPresenter *catPr; 
CatPresentation *catPn; 
int PresenterCounter; 
int PresentationCounter; 
int CatPresenterCounter; 
int CatPresentationCounter; 

#endif


