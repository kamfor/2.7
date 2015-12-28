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

int PrintCat(Cat tmp){

	Element temp; 
	temp = tmp->listofelements->head; 
	
	while(temp!="NULL"){
	/*print pretty table of elements from cat by name */
		temp = temp->next; 
	}
}

int AddToCat(void * element, Cat * catalogue){

	if(addnode(element, catalogue->listofelements))return 1; 
	
	return 0; 
}


	
	
