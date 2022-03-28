#ifndef KOPIEC_H
#define KOPIEC_H

#include<iostream>
#include<climits>

class MinHeap
{
    int *harr; // wkaznik na tablice reprezentujaca kopiec
    int capacity; // rozmiar
    int heap_size; // ilosc obecnych elementow
public:

    MinHeap(int capacity);

    // przywrocenie wlasnosci kopca od elementu o wybranym indeksie
    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    // indeks lewego dziecko wezla o indeksie i
    int left(int i) { return (2*i + 1); }

    // indeks prawego dziecko wezla o indeksie i
    int right(int i) { return (2*i + 2); }

    //Usuniecie ze szczytu (u¿ywa funkcji MinHeapify)
    int pop();

    // Zmniejszenie elementu o indeksie i
    void decreaseKey(int i, int new_val);

    //Szczyt kopca
    int getMin() { return harr[0]; }

    // Usuniêcie elementu o indeksie i (u¿ywa decreaseKey i extractMin)
    void deleteKey(int i);

    // Dodanie do kopca
    void push(int k);

    //Wyswietlenie kopca
    void print();

    //szukanie wartosci
    void searchValue(int value);
};

#endif
