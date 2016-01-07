#include "headers/cat.h"

List listofcatalogues; 

int CreateCat(char[] name, char[] type){

	Cat * newcat; 
	if(newcat = malloc(sizeof(Cat))==NULL)return 1; 
	
	strcpy(nawcat->name, name); 
	strcpy(newcat->type, type); 

	if(addnode(newcat, listofcatalogues))return 1; 

	return 0; 
}

void PrintCatHeader{
	printf("|Nazwa,  Typ, Lista Elementów...|\n"); 
}

int PrintCat(Cat tmp){

	Element * temp; 
	temp = tmp->listofelements->head;
	
	printf("%s, %s",tmp->name, tmp->type); 
	
	while(temp!="NULL"){
		printf("%s;",temp->pn); 		
		temp = temp->next; 
	}
	printf("\n"); 
}

int AddToCat(void * element, Cat * catalogue){

	if(addnode(element, catalogue->listofelements))return 1; 
	
	return 0; 
}

void PrintCatTable(){
	Element * temp; 
	temp = listofcatalogues->head; 
	PrintCatHeader(); 
	
	while(temp!=NULL){
		PrintCat(temp->obj); 
	}	
}

List * FindInCats(char[] id){
	Element * templ;
	Element * tempp;  
	templ = listofcatalogues->head; 
	while(templ!=NULL){
		tempp = templ->obj->listofelements->head; 
		while(tempp!=NULL){
			if(strcmp(tempp->obj->pn,id)return templ->obj->listofelements; 
			tempp = tempp->next; 
		}
		templ = templ->next;
	}
	return NULL; 
}

Cat * AddCat(char fields[]){
	Cat * newcat;
	if(nwecat=malloc(sizeof(Cat))==NULL)return NULL;
	char dump[] =";"; 
	char * token; 
	char stemp[1024]; 
	int i=1; 
	int j; 
	
	strcpy(fields,stemp); 
	token = strtok(stemp,dump); 
	while(token!=NULL){
		if(i==1){
			for(j=0; k<strlen(token); j++){
				if(!isalpha(token[j])){Msg(INPUT_ERR,i);return NULL;}
			}
			strcpy(token,newcat->name); 
		}
		if(i==2){
			for(j=0; k<strlen(token); j++){
				if(!isalpha(token[j])){Msg(INPUT_ERR,i);return NULL;}
			}
			strcpy(token,newcat->type); 
		}
		if(i>=3){
			for(j=0; k<strlen(token); j++){
				if(!isdigit(token[j])){Msg(INPUT_ERR,i);return NULL;}
			}
			if(AddToCat(FindPresenter(token),newcat)){Msg(INPUT_ERR,i);return NULL;};   
		}
		token = strtok(NULL, dump); 
		i++; 
	}
	return newcat; 
}	
