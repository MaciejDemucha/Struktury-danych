#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

using namespace std;

class ListElement
{
    public:
    int data;
    ListElement *next;
    ListElement *prev;
    ListElement();
};

ListElement::ListElement()
{
    next = 0;
    prev = 0;
}

class OneList
{
    public:
    ListElement *first;
    void addOnEnd(int data);
    void addOnBeg(int data);
    void addOnIndex(int data, int i);
    int getSize(ListElement *head);
    void deleteElement(int i);
    ListElement* findTail(ListElement *head);
    void showElement(int i);
    void searchValue(int value);
    void showList();
    void showReverse();
    OneList();
};

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
    newElement->prev = 0;
    first->prev = newElement;
    first = newElement;
}

//Rozmiar
int OneList::getSize(ListElement *head)
{
    int listSize = 0;
    ListElement *temp = head;

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
        newElement->prev = 0;
        first->prev = newElement;
        first = newElement;
    }

    //na koniec
    else
    {
        if(i == listSize)
        {
            while(temp->next)
            {
                temp = temp->next;
            }

            temp->next = newElement;
            newElement->next = 0;
            newElement->prev = temp;
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
        }
    }
}

//Usuwanie po indeksie
void OneList::deleteElement(int i)
{
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
        while(temp)
        {
            if(j==i) break;

            temp = temp->next;
            j++;
        }

        //usunięcie ostatniego
        if(temp->next->next == 0)
        {
            delete temp->next;
            temp->next = 0;
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
    int i = 0;

    while(temp)
    {
        if(temp->data == value) break;

        temp = temp->next;
        i++;
    }
    if(temp->data == value)
    {
        cout << "Liczba " << value << " znaleziona na indeksie "<< i << "." << endl;
    }
    else
    {
        cout << "Nie ma takiej liczby w tablicy" << endl;
    }
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
}


int main()
{
    OneList *myList = new OneList;


    myList->addOnEnd(2);
    myList->addOnBeg(1);
    myList->addOnEnd(3);
    myList->addOnEnd(4);
    myList->deleteElement(2);
    myList->addOnBeg(10);
    myList->addOnIndex(5, 1);
    myList->addOnIndex(6, 5);

    cout << "Lista: ";
    myList->showList();
    cout << "\nOd konca: ";
    myList->showReverse();
    cout << "\nElement na 1. pozycji: ";
    myList->showElement(1);
    myList->searchValue(7);

    delete myList;

    system("pause >nul");

    return 0;
}
