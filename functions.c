void ClearScreen(){
	printf("\033[2J"); 
	printf("\033[0;0f");
}

void AddNewPresenter(){
 
	Presenter temp; 
	char buff[100]; 
	
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

	do(

		printf("Wpisz afiliacje prezentera\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==3)strcpy(temp.afiliation, buff); 
		else printf("bledna afiliacje\n");		
	
	}while(StringCheck(buff)!=3); 

	do{
		printf("\n");
		scanf("%s", &buff); 
		if(StringCheck(buff)==4)strcpy(temp.gen, buff); 
		else printf("bledna afiliacje\n");
	
	}while(StringCheck(buff)!=4); 

	do{

		printf("Wpisz status platnosci(0 - brak 1 - zaplacono)\n");
		scanf("%s", &buff); 
		if(buff[0]=='0')strcopy(temp.payment,"nie zaplacono");
		else if(buff[0]=='1')strcopy(temp.payment,"zaplacono");  
		else printf("bledny status platnosci\n");		
	}while(!(buff[0]=='1' || buff[0]=='0')); 
			
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

