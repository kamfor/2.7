#include <string.h>
#include "containers.h"


int AddPresenter(){

msg(name);
read
msg(surname);
read;
msg(affiliation); 
read
msg(gen); 
read
msg(payment)
read
msg(succes)
info return


}

int AddPresentation(){

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
		printf("Wpisz numer prezentera ktory bedzie prezentowal prezentacje\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresenterCounter&&tabPr[number].visible){
				temp.owner = number;
			}
			else printf("Prezenter o podanym numerze nie istnieje\n");  
		}
		else printf("blad danych\n"); 
	}while(temp.owner!=number);

	for(i=0; i<PresentationCounter; i++){
		if(tabPn[i].visible==0){
			tabPn[i] = temp;
			tabPn[i].visible = 1;
			tabPn[i].pn = i; 
			write = 0; 
			tabPr[number].presentation[tabPr[number].nofpresentations]=i; 
			tabPr[number].nofpresentations++; 

			break; 
		}
	} 
	if(write){
		tabPn[PresentationCounter] = temp; 
		tabPn[PresentationCounter].visible = 1;
		tabPn[PresentationCounter].pn = PresentationCounter;
		tabPr[number].presentation[tabPr[number].nofpresentations]=PresentationCounter; 
		tabPr[number].nofpresentations++; 
		printf("Dodano prezentacje o numerze %d (wpisz zero aby wrococ do menu)\n",PresentationCounter);
		PresentationCounter++;
	}
	else
		printf("Dodano prezentacje o numerze %d (wpisz 0 aby wrocic do menu)\n",i); 
	scanf("%s",&buff); 
}

Presenter * FindPresenter(char[] field){
/* searching for field in any record*/ 

}


Presentation * FindPresentation(char[] field){
/* searching for field in any record*/ 

}

int DeletePresenter(Presenter * dead){
/*clean all memory and all dependences refered to dead*/
}

int DeletePresentation(Presentation * dead){
/*clean all memory and all dependences refered to dead*/
}

int UpdatePresenter(Presenter * new){
/* backup, remove, assign id from old :)*/
}

int UpdatePresentation(Presentation * new){
/* backup, remove, assign id from old :)*/
}





int PrintPresenterTable(int sortorder){
	int i,j; 
	int *tab = malloc(PresenterCounter *sizeof(int)); 
	
	for(i=0; i<PresenterCounter; i++)tab[i]=i;
	
	if(sortorder==1)qsort(tab,PresenterCounter,sizeof(int),ComparePresenterName);
	if(sortorder==2)qsort(tab,PresenterCounter,sizeof(int),ComparePresenterSurname);
	if(sortorder==3)qsort(tab,PresenterCounter,sizeof(int),ComparePresenterAffiliation); 
	if(sortorder==4)qsort(tab,PresenterCounter,sizeof(int),ComparePresenterGen); 
	if(sortorder==5)qsort(tab,PresenterCounter,sizeof(int),ComparePresenterPayment);
	if(sortorder==6)qsort(tab,PresenterCounter,sizeof(int),ComparePresenterPresentations);


	printf("| id |    imie    |  nazwisko  | afiliacja |typ wystapienia|status platnosci|numery prezentacji|\n");
	for(i=0; i<PresenterCounter; i++){
	if(tabPr[tab[i]].visible){
	printf("|----------------------------------------------------------------------------------------------|\n");
	printf("|%4d|%12s|%12s|%11s|",tabPr[tab[i]].pn,tabPr[tab[i]].name,tabPr[tab[i]].surname,tabPr[tab[i]].affiliation);
	printf("%15s|%16s|",tabPr[tab[i]].gen,tabPr[tab[i]].payment,tabPr[tab[i]].nofpresentations); 
	for(j=0; j<17; j++){if(j<1)printf("%d,",tabPr[tab[i]].presentation[j]);
				 else { if(tabPr[tab[i]].presentation[j]==0)printf(" "); 
					else printf("%d,",tabPr[tab[i]].presentation[j]);}}printf("\n");
	}
	}
	printf("|----------------------------------------------------------------------------------------------|\n");
		
}

int PrintPresentationTable(int sortorder){
	int i,j; 
	int *tab = malloc(PresentationCounter *sizeof(int)); 

	for(i=0; i<PresentationCounter; i++)tab[i]=i;
	if(sortorder==1)qsort(tab,PresentationCounter,sizeof(int),ComparePresentationName);
	if(sortorder==2)qsort(tab,PresentationCounter,sizeof(int),ComparePresentationType);	

	printf("| id |      nazwa       |   typ    |id  prezentujacego |\n");
	for(i=0; i<PresentationCounter; i++){
		if(tabPn[i].visible){
			printf("|------------------------------------------------------|\n");
			printf("|%4d|%18s|%10s|%19d|\n",tabPn[tab[i]].pn,tabPn[tab[i]].name,tabPn[tab[i]].type,tabPn[tab[i]].owner);
		}
	}
	printf("|------------------------------------------------------|\n");
}

int ComparePresenterName (const void * a, const void * b){

	int x = *(int*)a;
	int y = *(int*)b;
	return strcmp(tabPr[x].name,tabPr[y].name); 
}

int ComparePresenterSurname (const void * a, const void * b){

	int x = *(int*)a;
	int y = *(int*)b;
	return strcmp(tabPr[x].surname,tabPr[y].surname); 
}

int ComparePresenterAffiliation (const void * a, const void * b){

	int x = *(int*)a;
	int y = *(int*)b;
	return strcmp(tabPr[x].affiliation,tabPr[y].affiliation); 
}

int ComparePresenterGen (const void * a, const void * b){

	int x = *(int*)a;
	int y = *(int*)b;
	return strcmp(tabPr[x].gen,tabPr[y].gen); 
}

int ComparePresenterPayment (const void * a, const void * b){

	int x = *(int*)a;
	int y = *(int*)b;
	return strcmp(tabPr[x].payment,tabPr[y].payment); 	 
}

int ComparePresenterPresentations (const void * a, const void * b){

	int x = *(int*)a;
	int y = *(int*)b;
	if(tabPr[x].nofpresentations>tabPr[y].nofpresentations) return 1; 
	else if (tabPr[x].nofpresentations==tabPr[y].nofpresentations) return 0; 
	else return 0; 
}

int ComparePresentationName (const void * a, const void * b){

	int x = *(int*)a;
	int y = *(int*)b;
	return strcmp(tabPn[x].name,tabPn[y].name); 
}

int ComparePresentationType (const void * a, const void * b){

	int x = *(int*)a;
	int y = *(int*)b;
	return strcmp(tabPn[x].type,tabPn[y].type); 
}

