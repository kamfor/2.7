#include <string.h>
#include "functions.h"

void ClearScreen(){
	printf("\033[2J"); 
	printf("\033[0;0f");
}

void AddNewPresenter(){
 
	Presenter temp;   
	int i,number; 
	int j=0;  
	int write=1; 
	
	do{
		printf("Wpisz imie prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==2)strcpy(temp.name, buff); 
		else printf("bledne imie\n"); 

	}while(StringCheck(buff)!=2); 

	do{

		printf("Wpisz nazwisko prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==2)strcpy(temp.surname, buff); 
		else printf("bledne nazwisko\n"); 

	}while(StringCheck(buff)!=2); 	

	do{

		printf("Wpisz afiliacje prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff))strcpy(temp.affiliation, buff); 
		else printf("bledna afiliacje\n");		
	
	}while(StringCheck(buff)==0); 

	do{
		printf("Poadj rodzaj wystapienia 1-brak 2-ustne 3-plakat\n");
		scanf("%s", &buff); 
		if(buff[0]=='1')strcpy(temp.gen,"brak"); 
		else if(buff[0]=='2')strcpy(temp.gen,"ustne"); 
		else if(buff[0]=='3')strcpy(temp.gen,"plakat");  
		else printf("bledny rodzaj wystapienia\n");
	
	}while(StringCheck(buff)!=3); 

	do{
		printf("Wpisz status platnosci(0 - brak 1 - zaplacono)\n");
		scanf("%s", &buff); 
		if(buff[0]=='0')strcpy(temp.payment,"nie zaplacono");
		else if(buff[0]=='1')strcpy(temp.payment,"zaplacono");  
		else printf("bledny status platnosci\n");
		
	}while(!(buff[0]=='1' || buff[0]=='0')); 

	do{
		printf("wpisz numer prezentacji dla prezentera 0 aby zakonczyc\n"); 
		scanf("%s",buff);
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresentationCounter){
				temp.presentation[j]=number;
				j++; 
			}
			else printf("prezentacja nie istnieje\n"); 
			temp.nofpresentations = j; 
		}		
	}while(number!=0); 
	
	for(i=0; i<PresenterCounter; i++){
		if(tabPr[i].visible==0){
			strcpy(tabPr[i].name,temp.name);
			strcpy(tabPr[i].affiliation,temp.affiliation);
			strcpy(tabPr[i].surname,temp.surname);
			strcpy(tabPr[i].gen,temp.gen);
			strcpy(tabPr[i].payment,temp.payment);
			for(j=0; j<20; j++)tabPr[i].presentation[j] = temp.presentation[j];	
			tabPr[i].nofpresentations = temp.nofpresentations;  
			tabPr[i].visible = 1; 
			write = 0; 
			break; 
		}
	}
	if(write){
		strcpy(tabPr[PresenterCounter].name,temp.name);
		strcpy(tabPr[PresenterCounter].affiliation,temp.affiliation);
		strcpy(tabPr[PresenterCounter].surname,temp.surname);
		strcpy(tabPr[PresenterCounter].gen,temp.gen);
		strcpy(tabPr[PresenterCounter].payment,temp.payment);
		for(j=0; j<20; j++)tabPr[PresenterCounter].presentation[j] = temp.presentation[j];	
		tabPr[PresenterCounter].nofpresentations = temp.nofpresentations;  
		tabPr[PresenterCounter].visible = 1; 
		PresenterCounter++; 
	}			
}

void AddNewPresentation(){

	Presentation temp;
	int i, number; 
	int write=1; 

	do{
		printf("Wpisz nazwe prezentacji\n");
		scanf("%s", &buff); 
		if(StringCheck(buff))strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 

	}while(StringCheck(buff)==0); 

	do{
		printf("Wpisz typ prezentacji 1-ustna 2-plakat\n");
		scanf("%s", &buff); 
		if(buff[0]=='1')strcpy(temp.type, "ustna"); 
		else if(buff[0]=='2')strcpy(temp.type, "plakat"); 
		else printf("bledny typ\n"); 

	}while(StringCheck(buff)!=3); 

	do{
		printf("wpisz numer prezentera ktory bedzie prezentowal prezentacje\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresenterCounter&&tabPr[number].visible)temp.owner = number;
			else printf("prezenter o podanym numerze nie istnieje\n");  
		}
		else printf("blad danych\n"); 
	}while(temp.owner!=number);

	for(i=0; i<PresentationCounter; i++){
		if(tabPn[i].visible==0){
			strcpy(tabPn[i].name,temp.name); 
			strcpy(tabPn[i].type,temp.type); 
			tabPn[i].owner = temp.owner; 
			tabPn[i].visible = 1;
			write = 0; 
			break; 
		}
	} 
	if(write){
		strcpy(tabPn[PresentationCounter].name,temp.name); 
		strcpy(tabPn[PresentationCounter].type,temp.type); 
		tabPn[PresentationCounter].owner = temp.owner; 
		tabPn[PresentationCounter].visible = 1;
		PresentationCounter++;
	}
}

void CreateCatPresenter(){
 
	CatPresenter temp; 
	int number; 
	int i; 
	int j=0;
	
	do{
		printf("Podaj nazwe katalogu prezenterow\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff))strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 
	}while(StringCheck(buff)==0);

	do{
		printf("Wpisz numer porzadkowy prezentera ktorego chcesz dodac do katalogu (q aby zakonczyc)\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresenterCounter){
				temp.presenters[j] = number; 
				j++;
			}
			temp.amount = j; 			
		}
	}while(buff[0]=!'q'); 

	strcpy(catPr[CatPresenterCounter].name,temp.name); 
	for(i=0; i<20; i++)catPr[CatPresenterCounter].presenters[i] = temp.presenters[i]; 
	catPr[CatPresenterCounter].amount = temp.amount; 
	CatPresenterCounter++;  

	printf("Dodano %d elementow do katalogu\n",j); 
}

void CreateCatPresentation(){
 
	CatPresentation temp; 
	int number; 
	int i; 
	int j=0; 
	
	do{
		printf("Podaj nazwe katalogu prezentacji\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff))strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 
	}while(StringCheck(buff));
 
	do{
		printf("Wpisz numer porzadkowy prezentacji ktora chcesz dodac do katalogu (q aby zakonczyc)\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==8){
			number = atoi(buff); 
			if(number<=PresentationCounter&&tabPn[number].visible){
				temp.presentations[j] = number; 
				j++;
			}
			temp.amount = j; 			
		}
	}while(buff[0]!='q'); 

	strcpy(catPn[CatPresentationCounter].name,temp.name); 
	for(i=0; i<20; i++)catPn[CatPresentationCounter].presentations[i] = temp.presentations[i]; 
	catPn[CatPresentationCounter].amount = temp.amount; 
	CatPresentationCounter++; 

	printf("Dodano %d elementow do katalogu",j); 

}

void DeletePresenter(){

	int number; 

	do{
		printf("Podaj numer prezentera ktorego chcesz usunac\n"); 
		scanf("%s",&buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresenterCounter){
				if(tabPr[number].visible)tabPr[number].visible = 0; 
				else printf("element zostal juz usuniety\n"); 
			}
			else printf("Prezenter o podanym numerze nie istnieje\n"); 
		}
		else printf("bledny numer\n"); 	
	}while(StringCheck(buff)!=3); 

}

void DeletePresentation(){

	int number; 

	do{
		printf("Podaj numer prezentacji ktora chcesz usunac\n"); 
		scanf("%s",&buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresentationCounter){
				if(tabPn[number].visible)tabPn[number].visible = 0; 
				else printf("element zostal juz usuniety\n"); 
			}
			else printf("Prezentacja o podanym numerze nie istnieje\n"); 
		}
		else printf("bledny numer\n"); 	
	}while(StringCheck(buff)!=3); 


}

void UpdatePresenter(){

}

void UpdatePresentetion(){

}

void PrintPresenterTable(int sortorder){
	int i,j; 

	printf("| id |    imie    |  nazwisko  | afiliacja |typ wystapienia|status platnosci|numery prezentacji|\n");
	for(i=0; i<PresenterCounter; i++){
	if(tabPr[i].visible){
	printf("-----------------------------------------------------------------------------------------------|\n");
	printf("|%4d|%12s|%12s|%11s|",tabPr[i].pn,tabPr[i].name,tabPr[i].surname,tabPr[i].affiliation);
	printf("%15s|%16s|%18d|\n",tabPr[i].gen,tabPr[i].payment,tabPr[i].nofpresentations); 
	}
	}
	printf("|----------------------------------------------------------------------------------------------|\n");
		
}

void PrintPresentationTable(int sortorder){

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
	printf("-----------------------------------------------------------------------------------------\n");
}

void PrintCatPresenter(){

}

void PrintCatPresentation(){

}

void Exit(){
	free(tabPr); 
	free(tabPn); 
	free(catPr); 
	free(catPn); 
}

int StringCheck(char *bufor){

	int i;
	int result=0; 

	for(i=0; i<strlen(bufor)-1; i++){ 
		if((bufor[i]<91&&bufor[i]>64)||(bufor[i]<123&&bufor[i]>96)||(bufor[i]<58&&bufor[i]>47))result=1; 
		else return 0; 
	} 
	if(bufor[0]<91&&bufor[0]>64)result=2; 
	if(bufor[0]<58&&bufor[0]>47)result=3; 

	return result; 

}

