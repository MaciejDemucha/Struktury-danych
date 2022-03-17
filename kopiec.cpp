
#include<iostream>
#include<climits>
using namespace std;

//Zamiana elementow na ktore wskazuj¹ wskazniki
void swap(int *x, int *y);

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
    int extractMin();

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

    //MinHeapify(0);
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

int MinHeap::extractMin()
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
    extractMin();
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

int main()
{
    MinHeap h(11);
    h.push(3);
    h.push(2);
    h.deleteKey(1);
    h.push(15);
    h.push(5);
    h.push(4);
    h.push(45);
    h.print();
    h.searchValue(155);
    cout << h.extractMin() << endl;;
    cout << h.getMin() << endl;
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
