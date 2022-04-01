#ifndef KOPIEC_H
#define KOPIEC_H

#include<iostream>
#include<climits>

class MinHeap
{
    int *harr; // wskaznik na tablice przechowujaca elementy kopca
    int capacity; // rozmiar
    int heap_size; // ilosc obecnych elementow
public:

    MinHeap(int capacity); //konstruktor

    // przywrocenie wlasnosci kopca od elementu o wybranym indeksie
    void MinHeapify(int i);

    //indeks rodzica o potomku z indeksem i
    int parent(int i) { return (i-1)/2; }

    // indeks lewego dziecko rodzica o indeksie i
    int left(int i) { return (2*i + 1); }

    // indeks prawego dziecko rodzica o indeksie i
    int right(int i) { return (2*i + 2); }

    //Usuniecie ze szczytu (uzywa funkcji MinHeapify w celu przywrocenia wartosci)
    int pop();

    // Zmniejszenie elementu o indeksie i
    void decreaseKey(int i, int new_val);

    //Szczyt kopca
    int getMin() { return harr[0]; }

    // Usuniecie elementu o indeksie i (uzywa decreaseKey i extractMin w celu usuniecia)
    void deleteKey(int i);

    // Dodanie do kopca
    void push(int k);

    //Wyswietlenie kopca
    void print();

    //Usuniecie kopca z pamieci
    void clearHeap();

    //szukanie wartosci
    void searchValue(int value);
};

#endif
