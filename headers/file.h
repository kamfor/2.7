#ifndef FILE_H_DRFINED
#define FILE_H_DEFINED

#include <stdio.h>
#include <stdlib.h>
#include "containers.h"



int CreateBin(); 
int CreateRaw(); 
int OpenBin(); 
int OpenRaw(); 
int SaveBin(); 
int SaveRaw(); 
int LoadBin(); 
int LoadRaw(); 
int CheckPasswd(char *); 
void PrintFileHeader(); 
void PrintPresenterHeader(); 
void PrintPresentationHeader(); 
void PrintCatHeader(); 

#endif
