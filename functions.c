#include <string.h>
#include "functions.h"

void ClearScreen(){
	printf("\033[2J"); 
	printf("\033[0;0f");
}

void AddNewPresenter(){

	int i,number; 
	int j=0;  
	int write=1;  
	Presenter *temp;
	temp = calloc(1,sizeof(Presenter));   

	do{
		printf("Wpisz imie prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==2)strcpy(temp->name, buff); 
		else printf("bledne imie\n"); 

	}while(StringCheck(buff)!=2); 

	do{

		printf("Wpisz nazwisko prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==2)strcpy(temp->surname, buff); 
		else printf("bledne nazwisko\n"); 

	}while(StringCheck(buff)!=2); 	

	do{

		printf("Wpisz afiliacje prezentera\n");
		scanf("%s",&buff); 
		if(StringCheck(buff))strcpy(temp->affiliation, buff); 
		else printf("bledna afiliacje\n");		
	
	}while(StringCheck(buff)==0); 

	do{
		printf("Poadj rodzaj wystapienia (1-brak 2-ustne 3-plakat)\n");
		scanf("%s", &buff); 
		if(buff[0]=='1')strcpy(temp->gen,"brak"); 
		else if(buff[0]=='2')strcpy(temp->gen,"ustne"); 
		else if(buff[0]=='3')strcpy(temp->gen,"plakat");  
		else printf("bledny rodzaj wystapienia\n");
	
	}while(StringCheck(buff)!=3); 

	do{
		printf("Wpisz status platnosci(0 - brak 1 - zaplacono)\n");
		scanf("%s", &buff); 
		if(buff[0]=='0')strcpy(temp->payment,"nie zaplacono");
		else if(buff[0]=='1')strcpy(temp->payment,"zaplacono");  
		else printf("bledny status platnosci\n");
		
	}while(!(buff[0]=='1' || buff[0]=='0')); 

	/*do{
		printf("Wpisz numer prezentacji dla prezentera 0 aby zakonczyc\n"); 
		scanf("%s",buff);
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresentationCounter){
				temp.presentation[j]=number;
				j++; 

			}
			else printf("prezentacja nie istnieje\n"); 
			temp.nofpresentations = j; 
		}		
	}while(number!=0); */

	temp->visible = 1; 
	
	for(i=0; i<PresenterCounter; i++){
		if(tabPr[i].visible==0){
			tabPr[i] = *temp;
			tabPr[i].pn = i;  
			write = 0; 
			break; 
		}
	}
	if(write){
		tabPr[PresenterCounter] = *temp;
		tabPr[PresenterCounter].pn = PresenterCounter;
		printf("Dodano prezentera o numerze id = %d (wpisz 0 aby wrococ do menu) \n", PresenterCounter); 
		PresenterCounter++; 
	}
	else
		printf("Dodano prezentera o numerze id = %d (wpisz 0 aby wrococ do menu) \n", i);
	scanf("%s",&buff); 		
}

void AddNewPresentation(){

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

void CreateCatPresenter(){
 
	CatPresenter temp; 
	int number; 
	int i; 
	int j=0;
	
	do{
		printf("Podaj nazwe katalogu prezenterow\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff))strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 
	}while(StringCheck(buff)==0);

	do{
		printf("Wpisz numer porzadkowy prezentera ktorego chcesz dodac do katalogu (q aby zakonczyc)\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresenterCounter&&tabPr[number].visible){
				temp.presenters[j] = number; 
				j++;
			}
			else printf("Prezenter o podanym numerze nie istnieje\n"); 
			temp.amount = j; 			
		}
	}while(buff[0]!='q'); 

	catPr[CatPresenterCounter] = temp; 
	CatPresenterCounter++;  

	printf("Dodano %d elementow do katalogu (0 aby wrocic do menu)\n",j); 
	scanf("%s",&buff); 
}

void CreateCatPresentation(){
 
	CatPresentation temp; 
	int number; 
	int i; 
	int j=0; 
	
	do{
		printf("Podaj nazwe katalogu prezentacji\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff))strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 
	}while(StringCheck(buff)==0);
 
	do{
		printf("Wpisz numer porzadkowy prezentacji ktora chcesz dodac do katalogu (q aby zakonczyc)\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresentationCounter&&tabPn[number].visible){
				temp.presentations[j] = number; 
				j++;
			}
			else printf("Prezentacja o podanym numerze nie istnieje\n"); 
			temp.amount = j; 			
		}
	}while(buff[0]!='q'); 
	
	catPn[CatPresentationCounter] = temp; 
	CatPresentationCounter++; 

	printf("Dodano %d elementow do katalogu (0 aby wrocic do menu)\n",j); 
	scanf("%s",&buff);
}

void DeletePresenter(){
	int number; 

	do{
		printf("Podaj numer prezentera ktorego chcesz usunac\n"); 
		scanf("%s",&buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresenterCounter){
				if(tabPr[number].visible)tabPr[number].visible = 0; 
				else printf("element zostal juz usuniety\n"); 
			}
			else printf("Prezenter o podanym numerze nie istnieje\n"); 
		}
		else printf("bledny numer\n"); 	
	}while(StringCheck(buff)!=3); 
	printf("Usunieto prezentera o numerze %d ( Wpisz 0 aby wrococ do menu )\n",number);
	scanf("%s",&buff); 

}

void DeletePresentation(){
	int number; 

	do{
		printf("Podaj numer prezentacji ktora chcesz usunac\n"); 
		scanf("%s",&buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresentationCounter){
				if(tabPn[number].visible)tabPn[number].visible = 0; 
				else printf("element zostal juz usuniety\n"); 
			}
			else printf("Prezentacja o podanym numerze nie istnieje\n"); 
		}
		else printf("bledny numer\n"); 	
	}while(StringCheck(buff)!=3); 
	printf("Usunieto prezentacje o numerze %d ( Wpisz 0 aby wrococ do menu )\n",number);
	scanf("%s",&buff); 

}

void UpdatePresenter(){
	int number,j,nu; 
	Presenter *temp;
	temp = calloc(1,sizeof(Presenter));  

	do{
		printf("Podaj numer prezentera ktorego chcesz edytowac\n"); 
		scanf("%s",&buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresenterCounter){
				if(tabPr[number].visible){	
					do{
						printf("Wpisz imie prezentera\n");
						scanf("%s", &buff); 
						if(StringCheck(buff)==2)strcpy(temp->name, buff); 
						else printf("bledne imie\n"); 
					}while(StringCheck(buff)!=2); 

					do{
						printf("Wpisz nazwisko prezentera\n");
						scanf("%s", &buff); 
						if(StringCheck(buff)==2)strcpy(temp->surname, buff); 
						else printf("bledne nazwisko\n"); 
					}while(StringCheck(buff)!=2); 	

					do{
						printf("Wpisz afiliacje prezentera\n");
						scanf("%s", &buff); 
						if(StringCheck(buff))strcpy(temp->affiliation, buff); 
						else printf("bledna afiliacje\n");		
					}while(StringCheck(buff)==0); 

					do{
						printf("Poadj rodzaj wystapienia 1-brak 2-ustne 3-plakat\n");
						scanf("%s", &buff); 
						if(buff[0]=='1')strcpy(temp->gen,"brak"); 
						else if(buff[0]=='2')strcpy(temp->gen,"ustne"); 
						else if(buff[0]=='3')strcpy(temp->gen,"plakat");  
						else printf("bledny rodzaj wystapienia\n");
					}while(StringCheck(buff)!=3); 

					do{
						printf("Wpisz status platnosci(0 - brak 1 - zaplacono)\n");
						scanf("%s", &buff); 
						if(buff[0]=='0')strcpy(temp->payment,"nie zaplacono");
						else if(buff[0]=='1')strcpy(temp->payment,"zaplacono");  
						else printf("bledny status platnosci\n");
					}while(!(buff[0]=='1' || buff[0]=='0')); 

					/*do{
						printf("wpisz numer prezentacji prezentera (0 aby zakonczyc)\n"); 
						scanf("%s",buff);
						if(StringCheck(buff)==3){
							nu = atoi(buff); 
							if(nu<=PresentationCounter){
								temp.presentation[j]=nu;
								j++; 
							}
						else printf("prezentacja nie istnieje\n"); 
						temp.nofpresentations = j; 
						}		
					}while(nu!=0); */
					
					tabPr[number] = *temp; 
					tabPr[number].visible = 1; 
				}
				else printf("element zostal juz usuniety\n"); 
			}
			else printf("Prezenter o podanym numerze nie istnieje\n"); 
		}
		else printf("bledny numer\n"); 	
	}while(StringCheck(buff)!=3);
	printf("Edytowano prezentera o numerze %d ( Wpisz 0 aby wrococ do menu )\n",number);
	scanf("%s",&buff); 
}

void UpdatePresentation(){
	Presentation temp;
	int i,j, number,nu; 

	do{
		printf("Podaj numer prezentacji ktora chcesz edytowac\n"); 
		scanf("%s",&buff); 
		if(StringCheck(buff)==3){
			number = atoi(buff); 
			if(number<=PresentationCounter){
				if(tabPn[number].visible){
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
						printf("wpisz numer prezentera ktory zaprezentuje prezentacje\n");
						scanf("%s", &buff); 
						if(StringCheck(buff)==3){
							nu = atoi(buff); 
							if(nu<=PresenterCounter&&tabPr[nu].visible){
							temp.owner = nu;
							tabPr[nu].presentation[tabPr[nu].nofpresentations]=nu; 
							tabPr[nu].nofpresentations++; 
							}
							else printf("prezenter o podanym numerze nie istnieje\n");  
						}
						else printf("blad danych\n"); 
					}while(temp.owner!=nu);

					tabPn[number] = temp;
					tabPn[number].visible = 1;
				}				
				else printf("element zostal juz usuniety\n"); 
			}
			else printf("Prezentacja o podanym numerze nie istnieje\n"); 
		}
		else printf("bledny numer\n"); 	
	}while(StringCheck(buff)!=3); 
	printf("Edytowano prezentacje o numerze %d ( Wpisz 0 aby wrococ do menu )\n",number);
	scanf("%s",&buff); 
}

void PrintPresenterTable(int sortorder){
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

void PrintPresentationTable(int sortorder){
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

void PrintMenu(){
	ClearScreen(); 
	printf("-----------------------------------------------------------------------------------------\n");
	printf("--------------------------WSPOMAGANIE ORGANIZACJI KONFERENCJI----------------------------\n");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("-Wpisz 1 aby dodac prezentera          - wpisz 6 aby dodac katalog prezentacji          -\n"); 
	printf("-Wpisz 2 aby dodac prezentacje         - wpisz 7 aby wyswietlic liste prezenterow       -\n"); 
	printf("-Wpisz 3 aby usunac prezentera         - wpisz 8 aby wyswietlic liste prezentacji       -\n"); 
	printf("-Wpisz 4 aby usunac prezentacje        - wpisz 9 aby wyswietlic liste katal. prezenterow-\n"); 
	printf("-Wpisz 5 aby dodac katalog prezenterow - wpisz 10 aby wyswietic liste katal. prezentacji-\n");
	printf("-Wpisz 11 aby edytowac prezentera      - wpisz 12 aby edytowac prezentacje              -\n");
	printf("---------------------------------------- wpisz 0 aby zakonczyc                          -\n");
	printf("-----------------------------------------------------------------------------------------\n");
}

void PrintCatPresenter(){
	int i,j; 
	printf("|     nazwa     | numery prezenterow |\n");
	for(i=0; i<CatPresenterCounter; i++){
		printf("|------------------------------------|\n");
		printf("|%15s|%20d|\n",catPr[i].name,catPr[i].presenters[0]);
		for(j=1; j<catPr[i].amount; j++){
		printf("|               |%20d|\n",catPr[i].presenters[j]); 
		}
	}
	printf("|------------------------------------|\n");
	printf("Wpisz 0 aby wrococ do menu\n"); 
	scanf("%s",&buff); 
}

void PrintCatPresentation(){
	int i,j; 
	printf("|     nazwa     | numery prezentacji |\n");
	for(i=0; i<CatPresentationCounter; i++){
		printf("|------------------------------------|\n");
		printf("|%15s|%20d|\n",catPn[i].name,catPn[i].presentations[0]);
		for(j=1; j<catPn[i].amount; j++){
		printf("|               |%20d|\n",catPn[i].presentations[j]); 
		}
	}
	printf("|------------------------------------|\n");
	printf("Wpisz 0 aby wrocic do menu\n");
	scanf("%s",&buff); 
}

int Exit(){
	/*do{
		char buff[10];
		printf("Czy na pewno chcesz zakonczyc (Wpisz TAK lub NIE)\n"); 
		scanf("%s",&buff); 
		if(strcmp(buff,"NIE"))break; 
		
	}while(strcmp(buff,"TAK"));*/

	free(tabPr); 
	free(tabPn); 
	free(catPr); 
	free(catPn); 
	
	return 0; 
}

int StringCheck(char *bufor){/* funkcja sprawdzajaca jakie znaki wystepuja w ciagu */

	int i;
	int result=0; 

	for(i=0; i<strlen(bufor)-1; i++){ 
		if((bufor[i]<91&&bufor[i]>64)||(bufor[i]<123&&bufor[i]>96)||(bufor[i]<58&&bufor[i]>47))result=1; 
		else return 0; /*liczby i alfanumeryczne*/
	} 
	if(bufor[0]<91&&bufor[0]>64)result=2; /*wielka litera*/
	if(bufor[0]<58&&bufor[0]>47)result=3; /*liczba*/

	return result; 

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

