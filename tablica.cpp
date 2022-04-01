#include "tablica.h"

using namespace std;
//konstruktor
Table::Table()
{
    tab = nullptr;
    cnt = 0;
}
//usuniecie z pamieci
void Table::clearTable()
{
    if( cnt == 0 ) //czy nie jest pusta
         return;

    delete[] tab;
    tab = nullptr;
    cnt = 0;      //zerowanie liczby elementow
}
//wyswietlenie elementow tablicy
void Table::showTable()
{
    if(cnt == 0)
        cout << "Tablica jest pusta ";
    else
    {
       for(int i = 0; i<cnt; i++)
        {
            cout << tab[i] << " ";
        }
    }

    cout << endl;
}
//wyswietlenie elementu
void Table::showElement(int i)
{
    cout << tab[i] << endl;
}
//wyszukanie wartosci
void Table::searchValue(int value)
{
    int i = 0;

    while ( i < cnt && tab[i] != value ) i++; //przesuwamy sie po tablicy az znajdziemy wartosc

    if( i == cnt )
    {
        cout << "Nie ma takiej liczby w tablicy" << endl;
    }
    else
    {
        cout << "Liczba " << tab[i] << " znaleziona na indeksie "<< i << "." << endl;
    }
}
//dodanie na wybrany index
void Table::addOnIndex( int value, int index )
{
    int * NewTab = new int[ cnt + 1 ]; //nowa tablica wieksza o 1

    if(index > cnt) //jesli podany indeks jest wiekszy od rozmiaru tablicy, dodaj na koniec
    {
        for(int i = 0; i<cnt; i++)
            NewTab[ i ] = tab[ i ];
        NewTab[cnt] = value;
    }

    else if(index<0) //sprawdzenie czy uzytkownik nie podal ujemnego indeksu
    {
        return;
    }
    else
    {
        for( int i = 0; i < index; ++i ) // kopiuje wartosci przed indexem
            NewTab[ i ] = tab[ i ];

        NewTab[ index ] = value; //na index wstawiam zadana wartosc
        for( int i = index + 1; i < cnt + 1; ++i ) // i kopiuje reszte
            NewTab[ i ] = tab[ i - 1 ];
    }

    delete[] tab; //zwalniam pamiec zajmowana przez poprzednia tablice
    tab = NewTab; // przypisuje wskaznik na nowa tablice.
    ++cnt; // zwiekszam licznik
}
//dodanie na poczatek
void Table::addOnBeg( int value )
{
    int * NewTab = new int[ cnt + 1 ]; //nowa tablica

    NewTab[0] = value; //wstawiam zadana wartoscna poczatek
    for( int i = 1; i < cnt + 1; ++i ) // i kopiuje reszte
         NewTab[ i ] = tab[ i - 1 ];

    delete[] tab; //zwalniam pamiec zajmowana przez poprzednia tablice
    tab = NewTab; // przypisuje wskaznik na nowa tablice.
    ++cnt; // zwiekszam licznik
}
//dodanie na koniec
void Table::addOnEnd( int value )
{
    int * NewTab = new int[ cnt + 1 ]; //nowa tablica
    for( int i = 0; i < cnt; ++i ) // kopiuje wartosci
         NewTab[ i ] = tab[ i ];

    NewTab[ cnt ] = value; //wstawiam zadana wartosc na koniec

    delete[] tab; //zwalniam pamiec zajmowana przez poprzednia tablice
    tab = NewTab; // przypisuje wskaznik na nowa tablice.
    ++cnt; // zwiekszam licznik
}
//usuniecie elementu
void Table::deleteElement(int index)
{
    int * NewTab = new int[ cnt - 1 ]; //nowa tablica

    if(index < 0) //sprawdzenie czy podany indeks jest >= 0
    {
        cout << "Indeks nie moze byc 0 " << endl;
        return;
    }

    else if(index > cnt) //jesli podany indeks jest wiekszy od rozmiaru, usun ostatni element
    {
       index = cnt - 1;
    }

    for( int i = 0; i < index; ++i ) // kopiuje wartosci przed indexem
         NewTab[ i ] = tab[ i ];

    for(int i = index; i < cnt-1; i++) //kopiuje wartosci po index
        NewTab[ i ] = tab[ i+1 ];

    delete[] tab; //zwalniam pamiec zajmowana przez poprzednia tablice
    tab = NewTab; // przypisuje wskaznik na nowa tablice.
    --cnt; // zmniejszam licznik
}

