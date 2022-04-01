#ifndef LISTA2_H
#define LISTA2_H

#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

//reprezentacja elementu listy
class ListElement
{
    public:
    int data;           //zawartosc elementu
    ListElement *next;  //wskaznik na nastepnik
    ListElement *prev;  //wskaznik na poprzednik
    ListElement();      //konstruktor
};

//reprezentacja listy
class OneList
{
    public:
    ListElement *first;                         //glowa listy
    void addOnEnd(int data);                    //dodanie na koniec
    void addOnBeg(int data);                    //dodanie na poczatek
    void addOnIndex(int data, int i);           //dodanie na index
    int getSize(ListElement *first);            //zwrocenie rozmiaru listy
    void deleteElement(int i);                  //usuniecie elementu
    ListElement* findLast(ListElement *first);  //zwrocenie ogona listy
    void showElement(int i);                    //wypisanie elementu listy
    void searchValue(int value);                //wyszukiwanie wartosci
    void showList();                            //wyswietlenie listy
    void showReverse();                         //od tylu
    void clearList();                           //usuniecie z pamieci
    OneList();                                  //konstruktor
};

#endif
