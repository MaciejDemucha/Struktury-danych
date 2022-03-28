#include "tablica.h"

using namespace std;

Table::Table()
{
    tab = nullptr;
    cnt = 0;
}

void Table::clearTable()
{
    if( cnt == 0 )
         return;

    delete[] tab;
    tab = nullptr;
    cnt = 0;
}

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

void Table::showElement(int i)
{
    cout << tab[i] << endl;
}

void Table::searchValue(int value)
{
    int i = 0;

    while ( i < cnt && tab[i] != value ) i++;

    if( i == cnt )
    {
        cout << "Nie ma takiej liczby w tablicy" << endl;
    }
    else
    {
        cout << "Liczba " << tab[i] << " znaleziona na indeksie "<< i << "." << endl;
    }
}

void Table::addOnIndex( int value, int index )
{
    int * NewTab = new int[ cnt + 1 ]; //nowa tablica

    if(index > cnt)
    {
        for(int i = 0; i<cnt; i++)
            NewTab[ i ] = tab[ i ];
        NewTab[cnt] = value;
    }

    else if(index<0)
    {

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

void Table::deleteElement(int index)
{
    int * NewTab = new int[ cnt - 1 ]; //nowa tablica

    if(index < 0)
    {
        cout << "Indeks nie moze byc 0 " << endl;
        return;
    }

    else if(index > cnt)
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

