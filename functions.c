#include "functions.h"

void ClearScreen(){
	printf("\033[2J"); 
	printf("\033[0;0f");
}

void AddNewPresenter(){
 
	Presenter temp;  
	char buff[100]; 
	int i,number; 
	int j=0;  
	
	do{
		printf("Wpisz imie prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==1)strcpy(temp.name, buff); 
		else printf("bledne imie\n"); 

	}while(StringCheck(buff)!=1); 

	do{

		printf("Wpisz nazwisko prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==2)strcpy(temp.surname, buff); 
		else printf("bledne nazwisko\n"); 

	}while(StringCheck(buff)!=2); 	

	do{

		printf("Wpisz afiliacje prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==3)strcpy(temp.afiliation, buff); 
		else printf("bledna afiliacje\n");		
	
	}while(StringCheck(buff)!=3); 

	do{
		printf("Poadj rodzaj wystapienia 1-brak 2-ustne 3-plakat\n");
		scanf("%s", &buff); 
		if(buff[0]=='1')strcopy(temp.gen,"brak"); 
		else if(buff[0]=='2')strcopy(temp.gen,"ustne"); 
		else if(buff[0]=='3')strcopy(temp.gen,"plakat");  
		else printf("bledny rodzaj wystapienia\n");
	
	}while(StringCheck(buff)!=4); 

	do{
		printf("Wpisz status platnosci(0 - brak 1 - zaplacono)\n");
		scanf("%s", &buff); 
		if(buff[0]=='0')strcopy(temp.payment,"nie zaplacono");
		else if(buff[0]=='1')strcopy(temp.payment,"zaplacono");  
		else printf("bledny status platnosci\n");
		
	}while(!(buff[0]=='1' || buff[0]=='0')); 

	do{
		printf("wpisz numer prezentacji dla prezentera 0 aby zakonczyc\n"); 
		scanf("%s",buff);
		if(StringCheck(buff)==8){
			number =atoi(buff); 
			if(number<=PresentationCounter){
				temp.presentation[j]=number;
				j++; 
			}
			temp.nofpresentations = j; 
		}		
	}while(number!=0); 

	tabPr[PresenterCounter].name = temp.name; 
	tabPr[PresenterCounter].surname = temp.surname; 
	tabPr[PresenterCounter].affiliation = temp.affiliation; 
	tabPr[PresenterCounter].gen = temp.gen; 
	tabPr[PresenterCounter].payment = temp.payment; 
	tabPr[PresenterCounter].presentation = temp.prespointer; 
	tabPr[presenterCounter].nofpresentations = temp.nofpresentations;  
	tabPr[PresenterCounter].visible = 1; 

	PresenterCounter++; 			
}

void AddNewPresentation(){

	Presentation temp;
	char buff[100]; 
	int i, number; 

	do{
		printf("Wpisz nazwe prezentacji\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==6)strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 

	}while(StringCheck(buff)!=6); 

	do{
		printf("Wpisz typ prezentacji 1-ustna 2-plakat\n");
		scanf("%s", &buff); 
		if(buff[0]=='1')strcpy(temp.type, "ustna"); 
		else if(buff[0]=='2')strcopy(temp.type, "plakat"); 
		else printf("bledny typ\n"); 

	}while(StringCheck(buff)!=4); 

	do{
		printf("wpisz numer prezentera ktory bedzie prezentowal prezentacje\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==8){
			number  = atoi(buff); 
			if(number<=PresenterCounter)temp.owner = number;
			else printf("prezenter o podanym numerze nie istnieje\n");  
		}
		else(printf("blad danych\n"); 
	}while(StringCheck(buff)!=8);


	tabPn[PresentationCounter].name = temp.name; 
	tabPn[PresentationCounter].type = temp.type; 
	tabPn[PresentationCounter].owner = tepm.owner; 
	

	PresentationCounter++;
}

void CreateCatPresenter(){

	char buff[100]; 
	CatPresenter temp; 
	int number; 
	int i; 
	int j=0;
	
	do{
		printf("Podaj nazwe katalogu prezenterow\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==7)strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 
	}while(StringCheck(buff)!=7);

	do{
		printf("Wpisz numer porzadkowy prezentera ktorego chcesz dodac do katalogu (q aby zakonczyc)\n"); 
		scanf("%s", &buff); 
		if(stringcheck(buff)==8){
			number = atoi(buff); 
			if(number<=PresenterCounter){
				temp.presenters[j] = number; 
				j++;
			}
			temp.amount = j; 			
		}
	}while(buff[0]=!''q'); 

	CatPresenter[CatPresenterCounter].name = temp.name; 
	CatPresenter[CatPresenterCounter].preesnters = temp.presenters; 
	CatPresenter[CatPresenterCounter].amount = temp.amount;  


	printf("Dodano %d elementow do katalogu",j); 

}

void CreateCatPresentation(){

	char buff[100]; 
	CatPresentation temp; 
	int number; 
	int i; 
	int j=0; 
	
	do{
		printf("Podaj nazwe katalogu prezentacji\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==7)strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 
	}while(StringCheck(buff)!=7);
 
	do{
		printf("Wpisz numer porzadkowy prezentacji ktora chcesz dodac do katalogu (q aby zakonczyc)\n"); 
		scanf("%s", &buff); 
		if(stringCheck(buff)==8){
			number = atoi(buff); 
			if(number<=PresntationCounter){
				temp.presentations[j] = number; 
				j++;
			}
			temp.amount = j; 			
		}
	}while(number!=0); 

	CatPresentations[CatPresentationsCounter].name = temp.name; 
	CatPrentations[CatPresentationsCounter].presentations = temp.presentations; 
	CatPrestations[CatPresentationsCounter].amount = j; 

	printf("Dodano %d elementow do katalogu",j); 

}

void DeletePresenter(){

	char buff[10];
	int number; 

	do{
		printf("Podaj numer prezentera ktorego chcesz usunac\n"); 
		scanf("%s",&buff); 
		if(StringCheck(buff)==4){
			number = atoi(buff); 
			if(number<=PresenterCounter){
				if(tabPr[number].visible)tabPr[number].visible = 0; 
				else printf("element zostal juz usuniety\n"); 
			}
			else printf("Prezenter o podanym numerze nie istnieje\n"); 
		}
		else printf("bledny numer\n"); 	
	}while(StringCheck(buff)!=4); 

}

void DeletePresentetion(){

	char buff[10];
	int number; 

	do{
		printf("Podaj numer prezentacji ktora chcesz usunac\n"); 
		scanf("%s",&buff); 
		if(StringCheck(buff)==4){
			number = atoi(buff); 
			if(number<=PresentationCounter){
				if(tabPn[number].visible)tabPn[number].visible = 0; 
				else printf("element zostal juz usuniety\n"); 
			}
			else printf("Prezentacja o podanym numerze nie istnieje\n"); 
		}
		else printf("bledny numer\n"); 	
	}while(StringCheck(buff)!=4); 


}

void UpdatePresenter(){

}

void UpdatePresentetion(){

}

void Sorttable(int sortorder){

}

void PrintPresenterTable(){

}

void PrintPresentationTable(){

}

void PrintMenu(){

}

void Exit(){

}

int StringCheck(char *bufor){

	int i;
	int result=0; 
	if(bufor[0]>24&&bufor[0]<49)result=1; 
	else if(bufor[0]>40&&bufor[0]<49)result=2; 
	else return 0;    
	for(i=1; i<strlen(bufor), i++){
		
		if(bufor[1]>24&&bufor[i]>49)return 0; 
	}
}

