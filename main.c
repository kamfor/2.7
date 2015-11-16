/* wspomaganie organizacji konferencji*/
#include<stdio.h>
#include<string.h> 
#include "main.h"
#include "functions.h"

 
int main(){

	int control=1; 
	
	while(control){ 
	
		ClearScreen();

		printf("---------------------------------------------------------------------------------\n");
		printf("-----------------------WSPOMAGANIE ORGANIZACJI KONFERENCJI-----------------------\n");
		printf("---------------------------------------------------------------------------------\n");

		PrintMenu(); 
		
		scanf("%d",&control);

		switch(control){
		
		case 1:
		
			AddNewPresenter(); 

		break; 
		
		default:
			
			printf("podaj wartosc\n"); 

		
		}
 	}
		
	return 0; 
}
