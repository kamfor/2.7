#include <string.h>
#include "userface.h"

void ClearScreen(){
	printf("\033[2J"); 
	printf("\033[0;0f");
}

void PrintMenu(){
	ClearScreen(); 
	printf("-----------------------------------------------------------------------------------------\n");
	printf("--------------------------WSPOMAGANIE ORGANIZACJI KONFERENCJI----------------------------\n");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("-Wpisz 1 aby dodac prezentera          - wpisz 9 aby wyswietlic liste prezenterow       -\n"); 
	printf("-Wpisz 2 aby dodac prezentacje         - wpisz 10 aby wyswietlic liste prezentacji      -\n"); 
	printf("-Wpisz 3 aby usunac prezentera         - wpisz 11 aby wyswietlic liste kat. prezentacji -\n"); 
	printf("-Wpisz 4 aby usunac prezentacje        - wpisz 12 aby wyswietlic liste kat.prezenterow  -\n"); 
	printf("-Wpisz 5 aby dodac katalog prezenterow - wpisz 13 aby edytowac haslo dostepu            -\n");
	printf("-Wpisz 6 aby dodac katalog prezentacji - wpisz 14 aby wyszukac prezentera               -\n");
	printf("-Wpisz 7 aby edytowac prezentacje      - wpisz 15 aby wyszukac prezentacje              -\n");
	printf("-Wpisz 8 aby edytowac prezentera       - wpisz 0 aby zakonczyc                          -\n");
	printf("-----------------------------------------------------------------------------------------\n");
}

int Exit(){

	int i;
	Element * temp; 
	temp = ListOfPresenters->head; 
	while(temp!=NULL){
	
		if(delnode(temp,&ListOfPresenters))return 1;  	
	}
	if(dellist(&ListOfPresenters))return 1; 
	temp = ListOfPresentations; 
	while(temp!=NULL){
	
		if(delnode(temp,&ListOfPresentations))return 1;  	
	}
	if(dellist(&ListOfPresentations))return 1; 

	return 0; 	
}

int ReadFromStd(){
	char line[256]; 
	scanf("%s", line); 
	if(atoi(line)>=0&&atoi(line)<16)return atoi(line); 
}

void Msg(msgtype message, int position){
	
	switch(mwssage){

	case WELCOME:
	printf("WITAMY W PROGRAMIE\n"); 
	}
}
