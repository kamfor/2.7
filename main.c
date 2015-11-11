/* wspomaganie organizacji konferencji*/
#include<stdio.h>
#include<string.h> 

void ClearScreen(){
	printf("\033[2J");
	printf("\033[0;0f"); 
}

 
int main(){
	
	ClearScreen(); 

	int zmienn; 

	printf("---------------------------------------------------------------------------------\n");
	printf("-----------------------WSPOMAGANIE ORGANIZACJI KONFERENCJI-----------------------\n");
	printf("---------------------------------------------------------------------------------\n");

	scanf("%d",&zmienn); 
	ClearScreen(); 

	printf("---------------------------------------------------------------------------------\n");
	printf("-----------------------WSPOMAGANIE ORGANIZACJI KONFERENCJI-----------------------\n");
	printf("---------------------------------------------------------------------------------\n");


	return 0; 
}
