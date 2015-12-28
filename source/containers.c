#include <string.h>
#include "containers.h"


Presenter * AddPresenter(char * fields){

	Presenter * newpresenter;
	if(newpresenter=malloc(sizeof(Presenter))==NULL)return NULL; 
	char dump[] = ","; 
	char * token; 
	char stemp[256]; 
	int i=1; 
	int j; 
	int nofpresentations=0;

	strcpy(fields,stemp); 
	token = strtok(stemp,dump); 
	while(token != NULL){
		if(i==1){
			for(j=0; j<strlen(token); j++){
				if(isalpha(token[j])); 
				else {
					Msg(INPUT_ERR.i); 
					return NULL; 
				}
			}
			strcpy(token,nwepresenter->name); 
		}
		if(i==2){
			for(j=0; j<strlen(token); j++){
				if(isalpha(token[j])); 
				else {
					Msg(INPUT_ERR.i); 
					return NULL; 
				}
			}
			strcpy(token,newpresenter->surname); 
		}
		if(i==3){
			for(j=0; j<strlen(token); j++){
				if(isalpha(token[j])); 
				else {
					Msg(INPUT_ERR.i); 
					return NULL; 
				}
			}
			strcpy(token,newpresenter->affiliation); 
		}
		if(i==4){
			if(token[0]=='0'||token[0]=='1'||token[0]=='2'){
				newpresenter->gen = token[0]; 
			}
		else {
				Msg(INPUT_ERR,i); 
				return NULL; 
			}
		}
		if(i==5){
			if(token[0]=='0'||token[0]=='1'){
				newpresenter->payment = token[0]; 
			}
			else {
				Msg(INPUT_ERR,i); 
				return NULL; 
			}
			}
		if(i==6){
			for(j=0; j<strlen(token); j++){
				if(isdigit(token[j])); 
				else {
					Msg(INPUT_ERR.i); 
					return NULL; 
				}
			}
			newpresenter->pn  = atoi(token); 
		}
		if(i>6){
			for(j=0; j<strlen(token); j++){
				if(isdigit(token[j])); 
				else {
					Msg(INPUT_ERR.i); 
					return NULL; 
				}
			}
			newpresenter->presentations[nofpresentations]  = atoi(token); 
			nofpresentations++; 
		}
	
		token = strtok(NULL, dump); 
		i++; 
	}

	return newpresenter;

}

int AddPresentation(){


	Presentation * newpresentation;
	if(newpresentation=malloc(sizeof(Presentation))==NULL)return NULL; 
	char dump[] = ","; 
	char * token; 
	char stemp[256]; 
	int i=1; 
	int j; 

	strcpy(fields,stemp); 
	token = strtok(stemp,dump); 
	while(token != NULL){
		if(i==1){
			for(j=0; j<strlen(token); j++){
				if(isalpha(token[j])); 
				else {
					Msg(INPUT_ERR.i); 
					return NULL; 
				}
			}
			strcpy(token,nwepresentation->name); 
		}
		if(i==2){
			if(token[0]=='0'||token[0]=='1'){
				newpresentation->type = token[0]; 
			}
			else {
				Msg(INPUT_ERR,i); 
				return NULL; 
			}
		}
		if(i==3){
			for(j=0; j<strlen(token); j++){
				if(isdigit(token[j])); 
				else {
					Msg(INPUT_ERR.i); 
					return NULL; 
				}
			}
			newpresentation->pn  = atoi(token); 
		}
		if(i==4){
			for(j=0; j<strlen(token); j++){
				if(isdigit(token[j])); 
				else {
					Msg(INPUT_ERR.i); 
					return NULL; 
				}
			}
			newpresentation->owner  = atoi(token); 
		}

	
		token = strtok(NULL, dump); 
		i++; 
	}

	return newpresentation;

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

