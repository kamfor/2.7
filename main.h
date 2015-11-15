#ifndef main.h
#define main.h 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Presenter{}; 

struct Presentation{
	int pn;
	char name[30];  
	char type[20];
	int *pointer; 
};
	
	

struct Presenter{
	char name[20]; 
	char surname[30]; 
	char affiliation[20]; 
	char gen[10]; 
	char payment[20]; 
	int PresentationCounter; 
	int *prespointer; 
	int pn; 
}; 

struct CatPresenter{
	char name[20]; 
	int *wsktab;

struct CatPresentation{
	char name[20]; 
	int *wsktab;  
};

Presenter *tabPr; 
Presentetion *tabPn; 
CatPresenter *catPr; 
CatPresentation *catPn; 
int PresenterCounter; 
int Presentation Counter; 
int CatPresenterCounter; 
int CatPresentationCounter; 
#endif


