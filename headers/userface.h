#ifndef USERFACE_H_DEFINED
#define USERFACE_H_DEFINED

#include "main.h"

typedef enum msgtype {
	WELCOME,
	CLEAR, 
	MAINMENU,
	FILE_OPEN_ERR,
	FILE_OPEN_SUCCES,
	FILE_READ_ERR, 
	CREATE_FILE_PROMPT,
	CREATE_FILE_SUCCES,
	CREATE_FILE_ERR,
	PRESENTER_ADD,
	PRESENTER_ADD_SUCCES,
	PRESENTER_NEXIST, 
	PRESNTATION_ADD,
	PRESENTATION_ADD_SUCCES,
	PRESENTATION_NEXIST,
	INPUT_ERR, 
	
	
};

int Exit(); 
int ReadFromStd();
void Msg(msgtype, int); 
void PrintFileHeader(); 
void PrintPresenterHeader(void *); 
void PrintPresentationHeader(void *);
void PrintCatHeader(void *);
#endif
