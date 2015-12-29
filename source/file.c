//file handling functions

FILE * fileraw; 
FILE * filebin; 

int CreateBin(){

	if(filebin = fopen("database.bin","ba")==NULL) return 1;  
	return 0; 
}

int CreateRaw() {

	if(fileRaw = fopen("database.txt","wa")==NULL) return 1;  
	return 0; 
}

int OpenBin(){
	
	filebin = fopen("database.bin","b"); 
	if(filebin == NULL){ 
		Msg(FILE_OPEN_ERR);
		Msg(CREATE_FILE_PROMPT); 
		if(ReadFromStd() == 1) {
			if(CreateBin())  Msg(CREATE_FILE_ERR);
			Msg(CREATE_FILE_SUCCES); 
		}
		else return 1; 
	else{
		Msg(FILE_OPEN_SUCCES);
	}
	 
	return 0; 

}

int OpenRaw(){

	fileraw = fopen("database.txt","r+"); 
	if(fileraw == NULL){ 
		Msg(FILE_OPEN_ERR);
		Msg(CREATE_FILE_PROMPT); 
		if(ReadFromStd() == 1) {
			if(CreateRaw()) Msg(CREATE_FILE_SUCCES); 
			else Msg(CREATE_FILE_ERR);
		}
		else return 1; 
	else{
		Msg(FILE_OPEN_SUCCES);
	}
	 
	return 0;

}

int SaveBin(){

	/*clean file and save items from lists presenters presentations and catalogues*/
	/*dump all program data into table first line will be passwd key*/

	return 0; 

}

int SaveRaw(){
	
	PrintFileHeader(); 
	PrintPresenterHeader(); 
	PrintPresenterTable(fileraw); 
	PrintPresentationHeader(); 
	PrintPresentationTable(fileraw);
	PrintCatHeader(); 
	PrintCatTable(fileraw); 
	return 0; 
}

int LoadBin(){
	/*readline and group by first char*/

	return 0;
}

int LoadRaw(){
	int control=0; /*0-Presenter 1-Presentation 2-Catalogues*/
	
	/*readline and group by first char*/

	return 0; 
}

int CheckPasswd(char * pass, char * rpass){
 
	/*create hash from pass*/
	if(strcmp(pass,rpass)) return 0; 
	return 1; 
}

