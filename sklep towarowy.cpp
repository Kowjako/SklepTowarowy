#include<stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;
int rozmiar = 0;
struct towar
{
	char nazwa[20];
	float cena;
	int ilosc;
};
towar * tab  = NULL;
towar* utworz() {
	if(tab!=NULL) free(tab);
	cout<<"podaj rozmiar"<<endl;
	cin>>rozmiar;
	towar * buf = (towar*)calloc(rozmiar, sizeof(towar));
	cout<<"Podaj dane do bazy\n";
	for(int i=0; i<rozmiar; i++)
	{
		cout<<"Podaj nazwe: ";
	   	cin>>buf[i].nazwa;
	   	cout<<"Podaj cene: ";
		cin>>buf[i].cena;
		cout<<"Podaj ilosc: ";
		cin>>buf[i].ilosc;
	}

	return buf;
}
void wypisz()
{
	if(tab==NULL) cout<<"Brak tablicy"; else
	cout<<":               nazwa:    cena: ilosc:\n";
	for(int i=0; i<rozmiar; i++)
	{
		for(int j=0; j<38; j++)
		   	{
		 	     	printf("=");
	   	   	}
	   	   	printf("\n");
		printf(":%20s:%8.2f:%6d:\n", tab[i].nazwa, tab[i].cena, tab[i].ilosc);
	}
	system("PAUSE");
}
void dodaj()
{
	tab =(towar*) realloc(tab, (rozmiar+1)*sizeof(towar) );
	rozmiar++;
	cout<<"Podaj Towar"<<endl;
	cout<<"Podaj nazwe: ";
	cin>>tab[rozmiar-1].nazwa;
	cout<<"Podaj cene: ";
	cin>>tab[rozmiar-1].cena;
	cout<<"Podaj ilosc: ";
	cin>>tab[rozmiar-1].ilosc;
	system("PAUSE");
}
towar* usun(int pozycja)
{
	towar* buf=(towar*)realloc(tab, sizeof(towar)*(rozmiar-1));

	for(int i=pozycja; i<rozmiar; i++)
	{
		buf[i]=tab[i+1];
	}
	rozmiar--;
	if(rozmiar==0)
	{
		tab=NULL;
	}
	return buf;
	system("PAUSE");
}
void usuwanie()
{
	if(tab==NULL)
	{
		cout<<"Nie utworzono tablicy"<<endl;
	}
	free(tab);
	rozmiar = 0;
	tab=NULL;
	system("PAUSE");
}
void tworzenie_tablicy()
{
		tab = utworz();
		system("PAUSE");
}
int main()
{
	int numer;
	do
	{
	printf("Aktualny rozmiar: %d\n", rozmiar);
	printf("Aktualny adres tablicy dynamicznej %ld\n",&tab);
	printf("MENU:\n");
	printf("0. Koniec programu\n");
	printf("1. Tworzenie tablicy\n" );
	printf("2. Dodawanie nowego elementu\n");
	printf("3. Wypisywanie tablicy\n");
	printf("4. Usuwanie z pozycji\n");
	printf("5. Usuwanie calej tablicy\n");
	scanf("%d", &numer);
	switch(numer)
	{
		case 1:
			tworzenie_tablicy();
			break;
		case 2:
			dodaj ();
			break;
		case 3:
			wypisz();
			break;
		case 4:
			int pozycja;
			cout<<"Podaj pozycje\n";
			cin>>pozycja;
			usun(pozycja);
			break;
		case 5:
			usuwanie();
			break;
		default:
			break;
	}
	}
	while(numer!=0);
	return 0;
}
