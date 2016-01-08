/* wspomaganie organizacji konferencji*/
#include<stdio.h>
#include<string.h> 
#include "main.h"
#include "functions.h"

 
int main(){

	Initialize(); 
	while(StartInteraction()); 
	exit(); 
	
	
	while(control){ 

		
		do{
			Msg(CONTROL_PROMPT); 

		}while(control=ReadFromStd())
		

		switch(control){
		case 0:
			if(Exit())return 0; 
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
	
		break; 
		case 8: 
		
		break; 
		case 9:
		
		break; 
		case 10: 
		
		break; 
		case 11:
		
		break; 
		case 12:
		
		break; 		
		default:
			Msg(CONTROL_PROMPT); 
		
		}




 	}
		
	return 0; 
}
