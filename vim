#ifndef main.h
#define main.h 

struct Presenter{}; 

struct Presentation{
	int pn; 
	char type[20];
	Presenter *pointer; 
};
	
	

struct Presenter {
	char name[20]; 
	char surname[30]; 
	char affiliation[20]; 
	char gen[10]; 
	char payment[20]; 
	Presentation  **prespointer; 
	int pn; 
}; 

#endif

