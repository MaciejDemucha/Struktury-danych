#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

using namespace std;

class Table
{
    int * tab; //tablica dynamiczna
    int cnt; //ilosc elementow w tablicy
public:
    Table();
    void clearTable();
    void addOnIndex( int value, int index );
    void showTable();
    void addOnEnd(int value);
    void addOnBeg(int value);
    void deleteElement(int i);
    void showElement(int i);
    void searchValue(int value);
};

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
    for(int i = 0; i<cnt; i++)
    {
        cout << tab[i] << " ";
    }
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
        cout << "Poza zakresem, dodano na koniec" << endl;


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
    if(index > cnt || index<0)
    {
        cout << "Nie ma elementu o takim indeksie" << endl;
        return;
    }

    int * NewTab = new int[ cnt - 1 ]; //nowa tablica

    for( int i = 0; i < index; ++i ) // kopiuje wartosci przed indexem
         NewTab[ i ] = tab[ i ];

    for(int i = index; i<cnt; i++) //kopiuje wartosci po index
        NewTab[ i ] = tab[ i+1 ];

    delete[] tab; //zwalniam pamiec zajmowana przez poprzednia tablice
    tab = NewTab; // przypisuje wskaznik na nowa tablice.
    --cnt; // zmniejszam licznik
}

int main()
{
    Table *myTab = new Table;

    /*
    int el, razy;
    std::cout << "Ile elementow dodac do tablicy?";
    std::cin >> el;
    std::cout << "Ile razy dodac elementy do tablicy?";
    std::cin >> razy;
    auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
    for( int j = 0; j < razy; ++j )
    {
        for( int i = 0; i < el; ++i )
             myTab->addOnIndex( 0, rand() % 1000 ); //dodaj na poczatek tablicy losowa wartosc z przedzialu <0-999>

        myTab->showTable();
        myTab->clearTable(); //zwolnij pamiec po kazdym dodaniu elementow do tablicy
    }
    auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
    std::chrono::duration < double > czas = stop - start; //odejmij czasy
    std::cout << "Sredni czas dodawania elementow do tablicy:" << czas.count() / razy << "\n"; //wyswietl w sekundach
    */

    myTab->addOnBeg(1);
    myTab->addOnBeg(2);
    myTab->addOnEnd(3);
    myTab->addOnIndex(6, 2);
    myTab->deleteElement(1);
    myTab->showTable();
    cout << endl;
    myTab->showElement(0);
    myTab->searchValue(3);
    myTab->searchValue(7);

}
