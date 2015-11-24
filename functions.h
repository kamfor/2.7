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
void Exit(); 
int StringhiCheck(char*); 
int ComparePresenterName(const void *,const void *); 
#endif
