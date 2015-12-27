//file handling functions

FILE * fileraw; 
FILE * filebin; 

int CreateBin(){

	
	return 0; 
}

int CreateRaw() {

	return 0; 

}

int OpenBin(){
	
	filebin = fopen("database.bin","b"); 
	if(filebin == NULL){ 
		Msg(FILE_OPEN_ERR);
		Msg(CREATE_FILE_PROMPT); 
		if(ReadFromStd == 1) {
			if(CreateBin()) Msg(CREATE_FILE_SUCCES); 
			else Msg(CREATE_FILE_ERR);
		}
		else return 1; 
	else{
		Msg(FILE_OPEN_SUCCES);
	}
	 
	return 0; 

}

int OpenRaw(){

	return 0; 

}

int SaveBin(){

	return 0; 

}

int SaveRaw(){

	return 0; 

}

int LoadBin(){

	return 0; 

}

int LOadRaw(){

	return 0; 

}



