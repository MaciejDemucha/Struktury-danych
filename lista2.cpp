#include "lista2.h"

using namespace std;

ListElement::ListElement()
{
    next = 0;
    prev = 0;
}

OneList::OneList()
{
    first = 0;
}

//Dodawanie na koniec
void OneList::addOnEnd(int data)
{
    ListElement *newElement = new ListElement;

    newElement->data = data;

    if(first == 0)
    {
        first = newElement;
    }
    else
    {
        ListElement *temp = first;
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newElement;
        newElement->next = 0;
        newElement->prev = temp;
    }
}
//Dodawanie na początek
void OneList::addOnBeg(int data)
{
    ListElement *newElement = new ListElement;

    newElement->data = data;
    newElement->next = first;
    newElement->prev = NULL;

    if (first != NULL)
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
    ListElement *temp = first;
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

           //wskaźnik temp na element n-1
            while(temp)
            {
                if(j==i) break;

                temp = temp->next;
                j++;
            }
            temp2 = temp->next;
            temp->next = newElement;
            newElement->next = temp2;
            newElement->prev = temp;
            temp2->prev = newElement;
        }
    }
}


//Usuwanie po indeksie
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
            //deleteLast();
            if(!temp) return;
             temp -> prev -> next = NULL;
             delete temp->next;

           // delete temp->next;
            //temp->next = 0;
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

void OneList::usun_osobe (int nr)
{
    // jezeli to pierwszy element listy
    if (nr==1)
    {
        ListElement *temp = first;
        first = temp->next; //ustawiamy poczatek na drugi element
        delete temp; // usuwamy stary pierwszy element z pamieci
    }
    // jeżeli nie jest to pierwszy element
    else if (nr>=2)
    {
        int j = 1;

        // do usuniecia srodkowego elemetnu potrzebujemy wskaznika na osobe n-1
        // wskaznik *temp bedzie wskaznikiem na osobe poprzedzajaca osobe usuwana
        ListElement *temp = first;

        while (temp)
        {
            // sprawdzamy czy wskaznik jest na osobie n-1 niz usuwana
            if ((j+1)==nr) break;

            // jezeli nie to przewijamy petle do przodu
            temp = temp->next;
            j++;
        }

        // wskaznik *temp wskazuje teraz na osobe n-1
        // nadpisujemy wkaznik n-1 z osoby n na osobe n+1
        // bezpowrotnie tracimy osobe n-ta

        // jezeli usuwamy ostatni element listy
        if (temp->next->next==0) {
            delete temp->next;
            temp->next = 0;
        }
        // jezeli usuwamy srodkowy element
        else {
            ListElement *usuwana = temp->next;
            temp->next = temp->next->next;
            delete usuwana;
        }
    }
}

 void OneList::clearList()
 {
      if( first == 0 )
         return;

    delete first;
    first = nullptr;
 }

//Wyszukiwanie po indeksie
void OneList::showElement(int i)
{
    int j = 0;
    ListElement *temp = first;
    while(temp)
    {
        if(j == i) break;

        temp = temp->next;
        j++;
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

void OneList::searchValue(int value)
{
    ListElement *temp = first;
    bool found = false;
    int i = 0;

    while(temp)
    {
        if(temp->data == value)
        {
            found = true;
            break;
        }

        temp = temp->next;
        i++;
    }

    if(found)
        cout << "Liczba " << value << " znaleziona na indeksie "<< i << "." << endl;
    else
        cout << "Nie znaleziono liczby: " << value << endl;
}

ListElement* OneList::findTail(ListElement *head)
{
    if(!head)
        return NULL;

    while(head->next)
    {
        head = head->next;
    }
    return head;
}

//Wyświetlenie listy
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

//Od tyłu
void OneList::showReverse()
{

    ListElement *tail = findTail(first);

    do
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }while(tail);

    cout << endl;
}

//sprawdzenie wskaznikow prev i next
void OneList::prevNext()
{
    ListElement *temp = first;

    while(temp)
    {
        cout << temp->data << " ";
        if(temp->prev != NULL)
            cout << "prev -> " << temp->prev->data;
        if(temp->next != NULL)
            cout << " next -> " << temp->next->data << endl;
        temp = temp->next;
    }
}
