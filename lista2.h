#ifndef LISTA2_H
#define LISTA2_H

#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

class ListElement
{
    public:
    int data;
    ListElement *next;
    ListElement *prev;
    ListElement();
};

class OneList
{
    public:
    ListElement *first;
    void addOnEnd(int data);
    void addOnBeg(int data);
    void addOnIndex(int data, int i);
    int getSize(ListElement *head);
    //void deleteElement(ListElement* del);
    //void deleteIndex(int n);
    void deleteElement(int i);
    void usun_osobe(int nr);
    ListElement* findTail(ListElement *head);
    void showElement(int i);
    void searchValue(int value);
    void showList();
    void showReverse();
    void clearList();
    void prevNext();
    OneList();
};

#endif
