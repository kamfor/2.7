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
	char line[1024]; 
	rewind(fileraw); 
	while(!feof(fileraw)){
		fgets(line,1024,fileraw);	
		fwrite((void*)line,sizeof(line),1,filebin); 
	}

	return 0; 

}

int SaveRaw(){
	
	PrintFileHeader(); 
	PrintPresenterHeader(fileraw); 
	PrintPresenterTable(fileraw); 
	PrintPresentationHeader(fileraw); 
	PrintPresentationTable(fileraw);
	PrintCatHeader(fileraw); 
	PrintCatTable(fileraw); 
	return 0; 
}

int LoadBin(){

	char line[1024];
	int control=0;
	for(;!feof(filebin);){
		fread((void *)line,sizeof(line),1,filebin);
		if(line[0]=='1'){control= 1;fread((void *)line,sizeof(line),1,filebin);}
		if(line[0]=='2'){control= 2;fread((void *)line,sizeof(line),1,filebin);}
		if(line[0]=='3'){control= 3;fread((void *)line,sizeof(line),1,filebin);}
		switch control{
			case 1:
			if(addnode(AddPresenter(line),&listofpresenters))return 1; 
			break;
			case 2:
			if(addnode(AddPresentation(line),&listofpresentations))return 1; 
			break; 
			case 3:
			if(addnode(AddCat(line),&listofcatalogues))return 1; 
			break
		}
		fread((void *)line,sizeof(line),1,filebin);
	}
	return 0;
}

int LoadRaw(){
	int control=0; /*0-Presenter 1-Presentation 2-Catalogues*/
	char line[1024];

	for(;!feof(fileraw);){
		fgets(line,1024,fileraw);
		if(line[0]=='1'){control= 1;fgets(line,1024,fileraw);}
		if(line[0]=='2'){control= 2;fgets(line,1024,fileraw);}
		if(line[0]=='3'){control= 3;fgets(line,1024,fileraw);}
		switch control{
			case 1:
			if(addnode(AddPresenter(line),&listofpresenters))return 1; 
			break;
			case 2:
			if(addnode(AddPresentation(line),&listofpresentations))return 1; 
			break; 
			case 3:
			if(addnode(AddCat(line),&listofcatalogues))return 1; 
			break
		}
		fgets(line,1024,fileraw);
	}


	return 0; 
}

int CheckPasswd(char * pass, char * rpass){
 
	/*create hash from pass*/
	if(strcmp(pass,rpass)) return 0; 
	return 1; 
}

