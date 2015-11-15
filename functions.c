void ClearScreen(){
	printf("\033[2J"); 
	printf("\033[0;0f");
}

void AddNewPresenter(){
 
	Presenter temp = (Presenter*) malloc(sizeof(Presenter)); 
	char buff[100]; 
	int i;
	int j=0;  
	
	do{
		printf("Wpisz imie prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==1)strcpy(temp.name, buff); 
		else printf("bledne imie\n"); 

	}while(StringCheck(buff)!=1); 

	do{

		printf("Wpisz nazwisko prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==2)strcpy(temp.surname, buff); 
		else printf("bledne nazwisko\n"); 

	}while(StringCheck(buff)!=2); 	

	do{

		printf("Wpisz afiliacje prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==3)strcpy(temp.afiliation, buff); 
		else printf("bledna afiliacje\n");		
	
	}while(StringCheck(buff)!=3); 

	do{
		printf("Poadj rodzaj wystapienia 1-brak 2-ustne 3-plakat\n");
		scanf("%s", &buff); 
		if(buff[0]=='1')strcopy(temp.gen,"brak"); 
		else if(buff[0]=='2')strcopy(temp.gen,"ustne"); 
		else if(buff[0]=='3')strcopy(temp.gen,"plakat");  
		else printf("bledny rodzaj wystapienia\n");
	
	}while(StringCheck(buff)!=4); 

	do{
		printf("Wpisz status platnosci(0 - brak 1 - zaplacono)\n");
		scanf("%s", &buff); 
		if(buff[0]=='0')strcopy(temp.payment,"nie zaplacono");
		else if(buff[0]=='1')strcopy(temp.payment,"zaplacono");  
		else printf("bledny status platnosci\n");
		
	}while(!(buff[0]=='1' || buff[0]=='0')); 

	do{
		printf("wpisz numer prezentacji dla prezentera 0 aby zakonczyc\n"); 
		scanf("%s",buff);
		if(StringCheck(buff)==8){
			number = buff[0]; 
			if(number<=PresentationCounter){
				temp->prespointer[j]=number;
				j++; 
			}
		}
			
	}while(number!=0); 

	PresenterCounter++; 
	
	tabPr[PresenterCounter].name = temp.name; 
	tabPr[PresenterCounter].surname = temp.surname; 
	tabPr[PresenterCounter].affiliation = temp.affiliation; 
	tabPr[PresenterCounter].gen = temp.gen; 
	tabPr[PresenterCounter].payment = temp.payment; 
	tabPr[PresenterCounter].prespointer = temp.prespointer; 	
			
}

void AddNewPresentation(){

	Presentation temp; 
	char buff[100]; 

	do{
		printf("Wpisz nazwe prezentacji\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==6)strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 

	}while(StringCheck(buff)!=6); 

	do{
		printf("Wpisz typ prezentacji\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==7)strcpy(temp.type, buff); 
		else printf("bledny typ\n"); 

	}while(StringCheck(buff)!=7); 	

}

void CreateCatPresenter(){

	char buff[100]; 
	CatPresenter temp = (CatPresenter*)malloc(sizeof(CatPresenter)); 
	int number; 
	int i; 
	int j=0; 
	temp->wsktab = (int*) malloc(100 * sizeof(int)); 
	
	do{
		printf("Podaj nazwe katalogu prezenterow\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==7)strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 
	}while(StringCheck(buff)!=7);
 
	free(buff); 

	do{
		printf("Wpisz numer porzadkowy prezentera ktorego chcesz dodac do bazy (0 aby zakonczyc)\n"); 
		scanf("%s", &buff); 
		if(stringcheck(buff)==8){
			number = buff[0]; 
			for(i=0; i<sizeof(tabPr);i++){
				if(tabPr[i].pn==number){
					temp->wsktab[j] = number; 
					j++;
				}		
			}	
		}
	}while(number!=0); 

	

	printf("Dodano %d elementow do katalogu",j); 

}

void CreateCatPresentation(){

	char buff[100]; 
	CatPresentation temp = (CatPresentation*)malloc(sizeof(CatPresentation)); 
	int number; 
	int i; 
	int j=0; 
	temp->wsktab = (int*) malloc(100 * sizeof(int)); 
	
	do{
		printf("Podaj nazwe katalogu prezentacji\n"); 
		scanf("%s", &buff); 
		if(StringCheck(buff)==7)strcpy(temp.name, buff); 
		else printf("bledna nazwa\n"); 
	}while(StringCheck(buff)!=7);
 
	free(buff); 

	do{
		printf("Wpisz numer porzadkowy prezentacji ktora chcesz dodac do bazy (0 aby zakonczyc)\n"); 
		scanf("%s", &buff); 
		if(stringcheck(buff)==8){
			number = buff[0]; 
			for(i=0; i<sizeof(tabPr);i++){
				if(tabPn[i].pn==number){
					temp->wsktab[j] = number; 
					j++;
				}		
			}	
		}
	}while(number!=0); 

	printf("Dodano %d elementow do katalogu",j); 


}

void DeletePresenter(){

}

void DeletePresentetion(){

}

void UpdatePresenter(){

}

void UpdatePresentetion(){

}

void Sorttable(int sortorder){

}

void PrintPresenterTable(){

}

void PrintPresentationTable(){

}

void PrintMenu(){

}

void Exit(){

}

int StringCheck(char *bufor){

	int i;
	int result=0; 
	if(bufor[0]>24&&bufor[0]<49)result=1; 
	else if(bufor[0]>40&&bufor[0]<49)result=2; 
	else return 0;    
	for(i=1; i<strlen(bufor), i++){
		
		if(bufor[1]>24&&bufor[i]>49)return 0; 
	}
}

