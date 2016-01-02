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
	
