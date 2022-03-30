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

void MinHeap::searchValue(int value)
{
    int i = 0;

    while ( i < heap_size && harr[i] != value ) i++;

    if( i == heap_size )
    {
        cout << "Nie ma takiej liczby w kopcu" << endl;
    }
    else
    {
        cout << "Liczba " << harr[i] << " znaleziona na indeksie "<< i << "." << endl;
    }
}

void MinHeap::print()
{
    for(int i = 0; i<heap_size; i++)
    {
        cout << harr[i] << " ";
    }
    cout << endl;
}

void MinHeap::clearHeap()
 {
      if( harr == 0 )
         return;

    delete[] harr;
    harr = new int[capacity];
    heap_size = 0;
 }

void MinHeap::push(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

int MinHeap::pop()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    pop();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
