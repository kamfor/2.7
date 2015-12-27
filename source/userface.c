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
	printf("-Wpisz 1 aby dodac prezentera          - wpisz 6 aby dodac katalog prezentacji          -\n"); 
	printf("-Wpisz 2 aby dodac prezentacje         - wpisz 7 aby wyswietlic liste prezenterow       -\n"); 
	printf("-Wpisz 3 aby usunac prezentera         - wpisz 8 aby wyswietlic liste prezentacji       -\n"); 
	printf("-Wpisz 4 aby usunac prezentacje        - wpisz 9 aby wyswietlic liste katal. prezenterow-\n"); 
	printf("-Wpisz 5 aby dodac katalog prezenterow - wpisz 10 aby wyswietic liste katal. prezentacji-\n");
	printf("-Wpisz 11 aby edytowac prezentera      - wpisz 12 aby edytowac prezentacje              -\n");
	printf("---------------------------------------- wpisz 0 aby zakonczyc                          -\n");
	printf("-----------------------------------------------------------------------------------------\n");
}

int Exit(){
	/*do{
		char buff[10];
		printf("Czy na pewno chcesz zakonczyc (Wpisz TAK lub NIE)\n"); 
		scanf("%s",&buff); 
		if(strcmp(buff,"NIE"))break; 
		
	}while(strcmp(buff,"TAK"));*/

	free(tabPr); 
	free(tabPn); 
	free(catPr); 
	free(catPn); 
	
	return 0; 
}

string * ReadFromStd(){

/*
scanf line and group line ( number, name, surname, etc.)
*/
}

void Msg(
