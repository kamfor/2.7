#include "headers/cat.h"

int CreateCat(char[] name, char[] type){

	Cat temp; 
	strcpy(temp.name, name); 
	strcpy(temp.type, type); 
	
	//add to list 
}

int PrintCat(Cat tmp){

	Element temp; 
	temp = tmp->lostofelements->head; 
	
	while(temp!="NULL"){
	/*print pretty table of elements from cat by name */
		temp = temp->next; 
	}
}

int AddToCat(void * element, Cat * catalogue){

	if(addnode(element, catalogue->listofelements))Msg(OK); 
	else Msg(ERR); 

}


	
	
