void ClearScreen(){
	printf("\033[2J"); 
	printf("\033[0;0f");
}

void AddNewPresenter(){
	char *buff; 
	Presenter temp; 

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



