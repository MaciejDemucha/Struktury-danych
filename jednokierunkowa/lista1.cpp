#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct ListElement
{
    int data;
    ListElement *next;
    ListElement();
};

ListElement::ListElement()
{
    next = 0;
}

struct OneList
{
    ListElement *first;
    void addOnEnd(int data);
    void addOnBeg(int data);
    void addOnIndex(int data, int i);
    void deleteElement(int i);
    void showElement(int i);
    void showList();
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
    }
}
//Dodawanie na początek
void OneList::addOnBeg(int data)
{
    ListElement *newElement = new ListElement;

    newElement->data = data;
    newElement->next = first;
    first = newElement;
}

//Dodanie na wybrane miejsce
void OneList::addOnIndex(int data, int i)
{
    int listSize = 0;
    ListElement *temp = first;
    ListElement *temp2 = first; //aby nie stracic pierwotnej wartosci temp

    ListElement *newElement = new ListElement;

        newElement->data = data;
        newElement->next = first;

    //Rozmiar
    while(temp)
    {
        temp = temp->next;
        listSize++;
    }
    temp = first;

    //na początek
    if(i == 0)
    {
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

//Wyświetlenie listy
void OneList::showList()
{
    ListElement *temp = first;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    OneList *myList = new OneList;

    myList->addOnEnd(1);
    myList->addOnEnd(2);
    myList->addOnEnd(3);
    myList->addOnEnd(4);
    myList->deleteElement(2);
    myList->addOnBeg(10);
    myList->addOnIndex(5, 1);

    myList->showList();
    cout << endl;
    myList->showElement(0);

    delete myList;

    system("pause >nul");

    return 0;
}
