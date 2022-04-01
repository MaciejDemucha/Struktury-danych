#include "lista2.h"

using namespace std;

//konstruktor elementu listy
ListElement::ListElement()
{
    next = 0;
    prev = 0;
}
//konstruktor listy
OneList::OneList()
{
    first = 0;
}

//Dodawanie na koniec
void OneList::addOnEnd(int data)
{
    ListElement *newElement = new ListElement;

    newElement->data = data;

    if(first == 0)  //jesli lista jest pusta to nowy element jest glowa
    {
        first = newElement;
    }
    else
    {
        ListElement *temp = findLast(first); //szukamy ogona

        temp->next = newElement; //dodajemy element po ogonie
        newElement->next = 0;    //wskaznik na nastepnik nowego elementu jest NULL
        newElement->prev = temp; //dawny ogon staje sie poprzednikiem nowego elementu
    }
}
//Dodawanie na początek
void OneList::addOnBeg(int data)
{
    ListElement *newElement = new ListElement;

    newElement->data = data;
    newElement->next = first;
    newElement->prev = NULL;

    if (first != NULL) //jesli lista nie jest pusta to ustaw poprzednik dawnej glowy listy na nowy element
        first->prev = newElement;

    first = newElement;
}

//Rozmiar
int OneList::getSize(ListElement *first)
{
    int listSize = 0;
    ListElement *temp = first;

    while(temp)
    {
        temp = temp->next;
        listSize++;
    }

    return listSize;
}

//Dodanie na wybrane miejsce
void OneList::addOnIndex(int data, int i)
{
    int listSize = getSize(first);
    ListElement *temp = first;  //zmienne pomocnicze
    ListElement *temp2 = first; //aby nie stracic pierwotnej wartosci temp

    ListElement *newElement = new ListElement;

        newElement->data = data;
        newElement->next = first;

    //na początek
    if(i == 0)
    {
        addOnBeg(data);
    }

    //na koniec
    else
    {
        if(i >= listSize)
        {
            addOnEnd(data);
        }

        //w środku
        else
        {
           temp = first;
           int j = 1;

           //wskaźnik temp na element i-1
            while(temp)
            {
                if(j==i) break;

                temp = temp->next;
                j++;
            }
            temp2 = temp->next;       //przechowujemy adres elementu po miejscu gdzie chcemy wstawic nowy element
            temp->next = newElement; //wstawiamy nowy element na miejsce po temp
            newElement->next = temp2; //ustawiamy poprzednik i nastepnik nowego elementu
            newElement->prev = temp;
            temp2->prev = newElement; //ustawiamy poprzednik elementu po tym nowo wstawionym
        }
    }
}


//Usuwanie elementu
void OneList::deleteElement(int i)
{
    if(first->next == NULL)
    {
        delete first;
        first = nullptr;
        return;
    }

    //usunięcie pierwszego elementu
    if(i==0)
    {
        ListElement *temp = first;
        first = temp->next;
        first->prev = 0;
        delete temp;
    }

    //pozostałe przypadki
    else if(i>=1)
    {
        int j = 1;
        ListElement *temp = first;

        //wskaźnik temp na element n-1
        while(temp->next)
        {
            if(j==i) break;

            temp = temp->next;
            j++;
        }

        //usunięcie ostatniego
        if(temp->next->next == 0)
        {
            if(!temp) return;
             temp -> prev -> next = NULL;
             delete temp->next;
        }

        //środkowego
        else
        {
            ListElement *deletedEl = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete deletedEl;
        }
    }
}
//usuniecie z pamieci
 void OneList::clearList()
 {
      if( first == 0 ) //sprawdzenie czy lista nie jest pusta
         return;

    delete first;
    first = nullptr;
 }

//Wyszukiwanie po indeksie
void OneList::showElement(int i)
{
    int j = 0;                  //zmienna pomocnicza do porownywania indeksu odwiedzonego i docelowego
    ListElement *temp = first;  //zmienna pomocnicza do przeszukiwania listy
    while(temp)
    {
        if(j == i) break;       //jesli dotarlismy do podanego indeksu, przerwij

        temp = temp->next;
        j++;                    //zliczanie indeksu odwiedzonego elementu
    }
    if(temp == NULL)
    {
        cout<< "Poza zakresem" << endl;
    }
    else
    {
        cout<< temp->data << endl;
    }
}
//wyszukiwanie wartosci
void OneList::searchValue(int value)
{
    ListElement *temp = first;  //zmienna pomocnicza
    bool found = false;         //czy znaleziono
    int i = 0;                  //indeks znalezionej wartosci

    while(temp)     //przesuwamy sie po liscie
    {
        if(temp->data == value)
        {
            found = true; //jesli znaleziono, przerwij
            break;
        }

        temp = temp->next;
        i++; //zliczamy indeksy
    }

    if(found)
        cout << "Liczba " << value << " znaleziona na indeksie "<< i << "." << endl;
    else
        cout << "Nie znaleziono liczby: " << value << endl;
}
//Zwrocenie ogona listy
ListElement* OneList::findLast(ListElement *first)
{
    if(!first)
        return NULL; //sprawdzamy czy lista nie jest pusta

    while(first->next) //przesuwamy na koniec
    {
        first = first->next;
    }
    return first; //zwracamy ogon
}

//Wyswietlenie listy
void OneList::showList()
{
    if(!first)
    {
        cout << "Lista jest pusta" << endl;
        return;
    }

    ListElement *temp = first;

    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

//Od tylu
void OneList::showReverse()
{

    ListElement *tail = findLast(first);

    do
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }while(tail);

    cout << endl;
}
