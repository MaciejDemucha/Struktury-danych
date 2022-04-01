#ifndef TABLICA_H
#define TABLICA_H

#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

class Table
{
    int * tab; //wskaznik na tablice dynamiczna
    int cnt; //ilosc elementow w tablicy
public:
    Table();                                    //konstruktor
    void clearTable();                          //usuniecie z pamieci
    void addOnIndex( int value, int index );    //dodanie na wybrany index
    void showTable();                           //wyswietlenie elementow tablicy
    void addOnEnd(int value);                   //dodanie na koniec
    void addOnBeg(int value);                   //dodanie na poczatek
    void deleteElement(int i);                  //usuniecie elementu
    void showElement(int i);                    //wyswietlenie elementu
    void searchValue(int value);                //wyszukanie wartosci
};

#endif
