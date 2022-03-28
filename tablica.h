#ifndef TABLICA_H
#define TABLICA_H

#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

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

#endif
