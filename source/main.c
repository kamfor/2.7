/* wspomaganie organizacji konferencji*/
#include<stdio.h>
#include<string.h> 
#include "main.h"
#include "functions.h"

 
int main(){

	int control=1; 
	int i; 
	int sortorder = 1; 
	int actmem[] = {20,20,10,10};
	void *tmp; 
	tabPr = calloc(actmem[0], sizeof(Presenter)); 
	tabPn = calloc(actmem[1], sizeof(Presentation)); 
	catPr = calloc(actmem[2], sizeof(CatPresenter)); 
	catPn = calloc(actmem[3], sizeof(CatPresentation)); 


	ClearScreen(); 
	
	while(control){ 

		PrintMenu(); 
		
		do{
			scanf("%s",&buff);
			if(StringCheck(buff)==3)control = atoi(buff);
			else printf("blad wejscia\n");
		}while(StringCheck(buff)!=3);

		switch(control){
		case 0:
			if(Exit())return 0; 
		break; 	
		case 1:
			ClearScreen(); 
			AddNewPresenter();
		break;
		case 2:
			ClearScreen(); 
			AddNewPresentation(); 
		break; 
		case 3:
			ClearScreen(); 
			DeletePresenter();
		break; 
		case 4: 
			ClearScreen();
			DeletePresentation(); 
		break; 
		case 5:
			ClearScreen();
			CreateCatPresenter();
		break; 
		case 6: 
			ClearScreen();
			CreateCatPresentation(); 
		break;
		case 7:	
			sortorder=1;
			while(sortorder){
				printf("wpisz porzadek sortowania\n");
				printf("1 wg imienia; 2 wg nazwiska; 3 wg afiliacji; 4 wg typu wystapienia; \n");
				printf("5 wg platnosci; 6 wg ilosci prezentacji; 7 wg nr identyfikacyjnego\n");
				printf("Wpisz 0 aby zakonczyc\n"); 
				do{
					scanf("%s",&buff);
					if(StringCheck(buff)==3)sortorder = atoi(buff);
					else printf("niepoprawny porzadek sortowania\n");
				}while(StringCheck(buff)!=3);
				ClearScreen();  
				PrintPresenterTable(sortorder); 
			} 
		break; 
		case 8: 
			sortorder=1;
			while(sortorder){
				printf("wpisz porzadek sortowania\n");
				printf("1 wg nazwy; 2 wg typu\n");
				printf("Wpisz 0 aby zakonczyc\n");
				do{
					scanf("%s",&buff);
					if(StringCheck(buff)==3)sortorder = atoi(buff);
					else printf("niepoprawny porzadek sortowania\n");
				}while(StringCheck(buff)!=3); 
				ClearScreen(); 
				PrintPresentationTable(sortorder);
			}
		break; 
		case 9:
			ClearScreen();
			printf("Katalogi prezenterow\n");
			PrintCatPresenter();  
		break; 
		case 10: 
			ClearScreen();
			printf("Katalogi prezentacji\n"); 
			PrintCatPresentation(); 
		break; 
		case 11:
			ClearScreen(); 
			UpdatePresenter(); 
		break; 
		case 12:
			ClearScreen(); 
			UpdatePresentation(); 
		break; 		
		default:
			printf("podaj wartosc\n"); 
		
		}


		if(PresenterCounter==actmem[0]){
			actmem[0]*=2; 
			if((tmp = realloc(tabPr, sizeof(Presenter) * actmem[0])) == NULL ){
				printf("przykro mi nie udalo sie zaalokowac pamieci\n"); 
				break; 
			}
			else tabPr = tmp;
			for(i=0; i<actmem[0];i++){/*wyzerowanie pamieci zwybranych zmiennych adresowych */
				tabPr[i].nofpresentations = 0; 
				tabPr[i].visible = 0; 
			} 

 
		}
		if(PresentationCounter==actmem[1]){
			actmem[1]*=2; 
			if((tmp = realloc(tabPn, sizeof(Presentation) * actmem[1])) == NULL ){
				printf("przykro mi nie udalo sie zaalokowac pamieci\n"); 
				break;
			}
			else tabPn = tmp; 
			for(i=0; i<actmem[1];i++){
				tabPn[i].visible=0; 
			}
		}
		if(CatPresenterCounter==actmem[2]){
			actmem[2]*=2; 
			if((tmp = realloc(catPr, sizeof(CatPresenter) * actmem[2])) == NULL ){
				printf("przykro mi nie udalo sie zaalokowac pamieci\n");
				break; 
			}
			else catPr = tmp; 
		}
		if(CatPresentationCounter==actmem[3]){
			actmem[3]*=2; 
			if((tmp = realloc(catPn, sizeof(CatPresentation) * actmem[3])) == NULL ){
				printf("przykro mi nie udalo sie zaalokowac pamieci\n"); 
				break; 
			}
			else catPn = tmp; 
		}



 	}
		
	return 0; 
}
