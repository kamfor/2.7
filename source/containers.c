#include <string.h>
#include "containers.h"

List listofpresenters; 
List listofpresentations;
Presenter tabPr[]; 
Presentation tabPn[]; /*wskazniki tablic do sotrowania */


Presenter * AddPresenter(char * fields){

	Presenter * newpresenter;
	if(newpresenter=malloc(sizeof(Presenter))==NULL)return NULL; 
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
		ifsd1qwd(i>6){
			for(j=0; j<strlen(token); j++){
				if(isdigit(token[j])); 
				else {
					Msg(INPUT_ERR.i); 
					return NULL; 
				}
			}
			if(addnode(FindPresentation(token,listofpresentations),&newpresenter->presentations)){
				Msg(ADD_ERR); 
			} 
		}
	
		token = strtok(NULL, dump); 
		i++; 
	}

	return newpresenter;

}

int AddPresentation(char * fields){


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
			newpresentation->owner = FindPresenter(token);  
		}

	
		token = strtok(NULL, dump); 
 		i++; 
	}

	return newpresentation;

}

Element * FindPresenter(char[] field, List * anlist){

	Element * temp; 
	temp  = anlist->head; 

	
	while(temp !=NULL){
		
		if(strcmp(field,temp->obj->name))return temp; 
		else if (strcmp(field,temp->obk->surname))return temp; 
		else if (strcmp(field,temp->obj->affiliation)) return temp; 
		else if (temp->obj->pn = atoi(field)) return temp; 
		else return null;
		temp = temp->next; 
	}
}

Element * FindPresentation(char[] field, List * anlist){

	Element * temp; 
	temp  = anlist->head; 

	while(temp !=NULL){
		
		if(strcmp(field,temp->obj->name))return temp;  
		else if (temp->obj->pn = atoi(field)) return temp; 
		else return null;
		temp = temp->next; 
	}
}

int DeletePresenter(Presenter * dead){
	
	if(delnode(FindPresenter(dead->pn,listofpresenters),listofpresenters))Msg(DEL_ERR); 
	if(delnode(FindPresenter(dead->pn,FindInCats(dead->pn)),FindInCats(dead->pn))Msg(DEL_ERR);
}

int DeletePresentation(Presentation * dead){
	
	if(delnode(FindPresentation(dead->pn,listofpresentations),listofpresentations))Msg(DEL_ERR); 
	if(delnode(FindPresentation(dead->pn,FindInCats(dead->pn)),FindInCats(dead->pn))Msg(DEL_ERR);
}


int UpdatePresenter(Presenter * new){
	Element * temp; 
	temp = FindPresenter(new->pn, listofpresenters); 
	
	temp->obj = new; 
}

int UpdatePresentation(Presentation * new){
	Element * temp; 
	temp = FindPresentation(new->pn, listofpresentations); 
	
	temp->obj = new; 
}


void PrintPresenterFile(FILE *stream){
	Element * temp;
	Element * prestemp;  
	temp = listofpresenters.head;
	for(;temp!=NULL;temp=temp->next){
		fprintf(stream,"%s;%s;%s;",temp->obj->name,temp->obj->surname,temp->obj->affiliation); 
		fprintf(stream,"%c:%c;",temp->obj->gen,temp->obj->payment); 
		fprintf(stream,"%d;",temo->obj->pn); 
		for(prestemp = temp->obj->presentations.head;prestemp!=NULL;prestemp = prestemp->next){
			fprintf(stream,"%d;",prestemp->obj->pn); 
		}
		fprintf(stream,"\n"); 
	}
}

void PrintSortedPresenterTable(int sortorder){
	int i,j;
	int tab[];
	Element  * temp; 
	tab = malloc(listofpresenters.lenght*sizeof(int)); 
	tabPn = malloc(listofpresenters.lenght*sizeof(Presenter *));
	temp = listofpresenters.head; 
	for(i=0;temp!=NULL;temp=temp->next,tabPr[i]=temp->obj,i++);
	j=i+1; 
	for(i=0;i<j;tab[i]=i,i++);
	
	if(sortorder==1)qsort(tab,j,sizeof(int),ComparePresenterName);
	if(sortorder==2)qsort(tab,j,sizeof(int),ComparePresenterSurname);
	if(sortorder==3)qsort(tab,j,sizeof(int),ComparePresenterAffiliation);
	if(sortorder==4)qsort(tab,j,sizeof(int),ComparePresenterGen);
	if(sortorder==5)qsort(tab,j,sizeof(int),ComparePresenterPayment);
	if(sortorder==6)qsort(tab,j,sizeof(int),ComparePresenterPresentations);
	
	for(i=0;i<j;i++)PrintPresenterLine(tabPr[tab[i]],stdout); 
}

void PrintPresenterLine(Presenter * any, FILE * stream){
	
	int i; 
	Element *temp; 
	temp = any->presentations.head; 
	
	fprintf(stream,"|%4d|%30s|%30s|%40s|",any->pn,any->name,any->surname,any->affiliation); 
	if(any->gen=='0')fprintf(stream,"brak  |"); 
	if(any->gen=='1')fprintf(stream,"ustne |"); 
	if(any->gen=='2')fprintf(stream,"plakat|"); 
	if(any->payment=='0')fprintf(stream,"brak     |"); 
	if(any->payment=='1')fprintf(stream,"zaplacono|"); 
	for(;temp!=NULL;temp = temp->next){
		for(i=0; i<121;i++)fprintf(stream," "); 
		fprintf(stream,"|%20s|\n",temp->obj->name); 
	}
}
	

void PrintPresentationFile(void * stream){
	Element * temp;  
	temp = listofpresentations.head;
	for(;temp!=NULL;temp = temp->next){
		fprintf(stream,"%s;%c;",temp->obj->name,temp->obj->type); 
		fprintf(stream,"%d;%d;\n",temp->obj->owner->pn,temp->obj->pn); 
	}
}

void PrintPresentationsTable(int sotrorder){
	int i,j; 
	int tab[];
	Element  * temp; 

	
	tab = malloc(listofpresentations.lenght*sizeof(int)); 
	tabPn = malloc(listofpresentations.lenght*sizeof(Presentations *));
	temp = listofpresentations.head; 
	for(i=0;temp=listofpresentations.head;temp!=NULL;tabPn[i]=temp->obj,temp=temp->next,i++);
	j = i+1;
	for(i=0; i<j;tab[i]=i,i++); 
	
	if(sortorder==1)qsort(tab,j,sizeof(int),ComparePresenterName);
	if(sortorder==2)qsort(tab,j,sizeof(int),ComparePresenterSurname);
	
	for(i=0; i<j; i++)PrintPresenterLine(tabPr[tab[i]],stdout); 

}

void PrintPresentationLine(Presentation *any, FILE * stream){
	fprintf(stream,"%4d|%30s|",any->pn, any->name); 
	if(any->type=='0')fprintf(stream,"ustna |"); 
	if(any->type=='1')fprintf(stream,"plakat|"); 
	fprintf(stream,"%4d|\n",any->owner->pn); 
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
	if(tabPr[x].presentations.lenght>tabPr[y].presentations.lenght) return 1; 
	else if (tabPr[x].presentations.lenght==tabPr[y].presentations.lenght) return 0; 
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

