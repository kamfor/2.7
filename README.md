# 2.7
##Wspomaganie organizacji konferencji
Program pozwala na dodawanie i edycje danych o prezenterach i prezentacjach. Dane przechowywane sa w tablicach struktur o nastepujacej budowie:
>Prezenter<
```C
typedef struct {
	int pn; // liczba porzadkowa
	char name[]; //imie
	char surname[]; //nazwisko
	char affiliation[]; //afiliacja
	char gen[]; //rodzaj wystapienia
	char payment[]; //rodzaj platnosci
	int presentation[]; //tablica identyfikatorow prezentacji
	int nofpresentations; //liczba prezentacji
	int visible; //zmienna odpowiadajaca za widocznosc 
}Presenter; 
```
#Funkcje 
Program bazuje na instrukcji switch ktora uruchamia poszczegolne funkcje odpowiedzialne za mainpulacje danymi sa to:
```C
void ClearScreen(); // czyszczenie konsoli
void AddNewPresenter(); 
void AddNewPresentation(); 
void CreateCatPresenter(); 
void CreateCatPresentation(); 
void DeletePresenter(); 
void DeletePresentation(); 
void UpdatePresenter(); 
void UpdatePresentation();
void PrintPresenterTable(int); 
void PrintPresentationTable(int);
void PrintCatPresenter(); 
void PrintCatPresentation();  
void PrintMenu(); 
int Exit(); 
int StringhiCheck(char*); 
int ComparePresenterName(const void *,const void *); 
int ComparePresenterSurname(const void *,const void *); 
int ComparePresenterAffiliation(const void *,const void *); 
int ComparePresenterGen(const void *,const void *); 
int ComparePresenterPayment(const void *,const void *); 
int ComparePresenterPresentations(const void *,const void *); 
int ComparePresentationName(const void *,const void *); 
int ComparePresentationType(const void *,const void *); 
```
