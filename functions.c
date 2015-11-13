void ClearScreen(){
	printf("\033[2J"); 
	printf("\033[0;0f");
}

void AddNewPresenter(){
 
	Presenter temp; 
	char buff[100]; 

	printf("Wpisz imie prezentera\n");
	scanf("%s", &buff); 
	if(StringCheck(bufor)==1)strcpy(temp.name, buff); 
	else printf("bledne imie\n"); 

	printf("Wpisz nazwisko prezentera\n");
	scanf("%s", &buff); 
	if(StringCheck(bufor)==2)strcpy(temp.surname, buff); 
	else printf("bledne nazwisko\n"); 	

	printf("Wpisz afiliacje prezentera\n");
	scanf("%s", &buff); 
	if(StringCheck(bufor)==3)strcpy(temp.afiliation, buff); 
	else printf("bledna afiliacje\n");		
	
}

void AddNewPresentation(){

}

void CreateCatPresenter(){

}

void CreateCatPresentation(){

}

void DeletePresenter(){

}

void DeletePresentetion(){

}

void UpdatePresenter(){

}

void UpdatePresentetion(){

}

void PrintPresenterTable(int sortorder){

}

void PrintPresentationTable(int sortorder){

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

