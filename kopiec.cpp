#include "kopiec.h"

using namespace std;

//Zamiana elementow na ktore wskazuja wskazniki
void swap(int *x, int *y);

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

//szukanie wartosci
void MinHeap::searchValue(int value)
{
    int i = 0;

    while ( i < heap_size && harr[i] != value ) i++; //przeszukujemy, az dotrzemy do konca tablicy

    if( i == heap_size )
    {
        cout << "Nie ma takiej liczby w kopcu" << endl;
    }
    else
    {
        cout << "Liczba " << harr[i] << " znaleziona na indeksie "<< i << "." << endl;
    }
}

//wyswietlenie kopca (elementow w tablicy po kolei)
void MinHeap::print()
{
    for(int i = 0; i<heap_size; i++)
    {
        cout << harr[i] << " ";
    }
    cout << endl;
}

//usuniecie kopca z pamieci
void MinHeap::clearHeap()
 {
      if( harr == 0 )
         return;

    delete[] harr;
    harr = new int[capacity];
    heap_size = 0;
 }

 //dodanie wartosci do kopca
void MinHeap::push(int k)
{
    //Wykrycie przekroczenia pojemnosci kopca
    if (heap_size == capacity)
    {
        cout << "\nOverflow\n";
        return;
    }

    //wstawienie nowej wartosci
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    //przywrocenie wlasnosci kopca po dodaniu
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

//zmmniejszenie wartosci wybranego elementu, wykorzystywane przy usuwaniu elementu z kopca
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val; //zmiana wartosci

    //przywrocenie wlasnoci kopca po zmianie
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

//usuniecie elementu z kopca i zwrocenie jego wartosci
int MinHeap::pop()
{
    if (heap_size <= 0) //sprawdzenie czy rozmiar jest wiekszy od 0
        return INT_MAX;
    if (heap_size == 1) //usuniecie z 1-elementowego kopca
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0]; //przechowujemy wartosc usunietego elementu z korzenia
    harr[0] = harr[heap_size-1]; //poprzednia wartosc korzenia przyjmuje wartosc elementu ostatniego w tablicy
    heap_size--; //zmniejszamy rozmiar kopca
    MinHeapify(0); //przywrocenie wlasnosci kopca od korzenia

    return root; //zwrocenie wartosci usunietej
}

//usuwanie przez zmniejszenie elementu do mozliwie malego, co sprawi, ze bedzie w korzeniu kopca i uzycie funkcji pop
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    pop();
}

//przywrocenie wlasnosci kopca
void MinHeap::MinHeapify(int i)
{
    int smallest = i; //indeks wezla od ktorego przywracamy wlasnosc, podanie 0 przywraca wlasnosc calemu kopcowi
    int l = left(i); //indeks potomka lewego
    int r = right(i); //indeks potomka prawego

    //jesli indeks lewego/prawego potomka jest mniejszy od ilosci el. w kopcu i
    //jego wartosc jest mniejsza od rodzica,
    //to wstaw potomka na miejsce rodzica

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;

    //jesli doszlo do zamiany wartosci
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]); //zamien ze soba adresy obecnego korzenia i tego przed operacja
        MinHeapify(smallest);            //rekurencyjne powtorzenie operacji
    }
}

//zamiana adresow, ktore przechowuja wskazniki, funkcja pomocnicza
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
