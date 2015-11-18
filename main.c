/* wspomaganie organizacji konferencji*/
#include<stdio.h>
#include<string.h> 
#include "main.h"
#include "functions.h"

 
int main(){

	int control=1; 
	int sortorder = 1; 
	int actmem[] = {20,20,10,10};
	void *tmp; 
	tabPr = malloc(sizeof(Presenter) * actmem[0]); 
	tabPn = malloc(sizeof(Presentation) * actmem[1]); 
	catPr = malloc(sizeof(CatPresenter) * actmem[2]); 
	catPn = malloc(sizeof(CatPresentation) * actmem[3]);  

	ClearScreen(); 
	
	while(control){ 

		PrintMenu(); 
		
		scanf("%d",&control);

		switch(control){
		case 0:
			Exit();
			return 0; 
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
				scanf("%d", &sortorder);
				ClearScreen();  
				PrintPresenterTable(sortorder); 
			} 
		break; 
		case 8: 
			sortorder=1;
			while(sortorder){
				printf("wpisz porzadek sortowania\n");
				printf("1 wg nazwy; 2 wg typu\n");
				scanf("%d", &sortorder); 
				ClearScreen(); 
				PrintPresenterTable(sortorder);
			}
		break; 
		case 9:
			ClearScreen();
			printf("Katalogi prezenterow\n"); 
		break; 
		case 10: 
			ClearScreen();
			printf("Katalogi prezentacji\n"); 
		break; 		
		default:
			printf("podaj wartosc\n"); 
		
		}


		if(PresenterCounter==actmem[0]){
			actmem[0]*=2; 
			if((tmp = realloc(tabPr, sizeof(Presenter) * actmem[0])) == NULL ){
				printf("przykro mi nie udalo sie zaalokowac pamieci\n"); 
			}
			else tabPr = tmp; 
		}
		if(PresentationCounter==actmem[1]){
			actmem[1]*=2; 
			if((tmp = realloc(tabPn, sizeof(Presentation) * actmem[1])) == NULL ){
				printf("przykro mi nie udalo sie zaalokowac pamieci\n"); 
			}
			else tabPn = tmp; 
		}
		if(CatPresenterCounter==actmem[2]){
			actmem[2]*=2; 
			if((tmp = realloc(catPr, sizeof(CatPresenter) * actmem[2])) == NULL ){
				printf("przykro mi nie udalo sie zaalokowac pamieci\n"); 
			}
			else catPr = tmp; 
		}
		if(CatPresentationCounter==actmem[3]){
			actmem[3]*=2; 
			if((tmp = realloc(catPn, sizeof(CatPresentation) * actmem[3])) == NULL ){
				printf("przykro mi nie udalo sie zaalokowac pamieci\n"); 
			}
			else catPn = tmp; 
		}



 	}
		
	return 0; 
}
