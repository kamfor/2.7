#ifndef FUNCTIONS_H_DEFINED
#define FUNCTIONS_H_DEFINED

#include "main.h"

void ClearScreen(); 
void AddNewPresenter(); 
void AddNewPresentation(); 
void CreateCatPresenter(); 
void CreateCatPresentation(); 
void DeletePresenter(); 
void DeletePresentation(); 
void UpdatePresenter(); 
void UpdatePresentation();
void PrintPresenterTable(int); 
void PrintPresentationTable(int);
void PrintCatPresenter(); 
void PrintCatPresentation();  
void PrintMenu(); 
int Exit(); 
int StringhiCheck(char*); 
int ComparePresenterName(const void *,const void *); 
int ComparePresenterSurname(const void *,const void *); 
int ComparePresenterAffiliation(const void *,const void *); 
int ComparePresenterGen(const void *,const void *); 
int ComparePresenterPayment(const void *,const void *); 
int ComparePresenterPresentations(const void *,const void *); 
int ComparePresentationName(const void *,const void *); 
int ComparePresentationType(const void *,const void *); 

#endif
