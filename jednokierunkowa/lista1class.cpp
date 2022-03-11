#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node()
    {
        data = 0;
        next = NULL;
    }


    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


class LinkedList
{
    Node *head;

    public:
        Linkedlist() { head = NULL; }

        void pushBack(int);
        void pushFront(int data);
        void pushOnIndex(int data, int i);
        void popNode(int i);
        void showNode(int i);
        void showList();
};


//Dodawanie na koniec
void LinkedList::pushBack(int data)
{
    // Create the new Node.
    Node* newNode = new Node(data);

    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {

        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}
//Dodawanie na początek
void LinkedList::pushFront(int data)
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

//Dodanie na wybrane miejsce
void LinkedList::pushOnIndex(int data, int i)
{
    int listSize = 0;
    Node *temp = head;
    Node *temp2 = head; //aby nie stracic pierwotnej wartosci temp

    Node *newNode = new Node;

        newNode->data = data;
        newNode->next = head;

    //Rozmiar
    while(temp)
    {
        temp = temp->next;
        listSize++;
    }
    temp = head;

    //na początek
    if(i == 0)
    {
        head = newNode;
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

            temp->next = newNode;
            newNode->next = 0;
        }

        //w środku
        else
        {
           temp = head;
           int j = 1;

           //wskaźnik temp na element n-1
            while(temp)
            {
                if(j==i) break;

                temp = temp->next;
                j++;
            }
            temp2 = temp->next;
            temp->next = newNode;
            newNode->next = temp2;
        }
    }
}

//Usuwanie po indeksie
void LinkedList::popNode(int i)
{
    //usunięcie pierwszego elementu
    if(i==0)
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
    }

    //pozostałe przypadki
    else if(i>=1)
    {
        int j = 1;
        Node *temp = head;

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
            Node *deletedEl = temp->next;
            temp->next = temp->next->next;
            delete deletedEl;
        }
    }
}

//Wyszukiwanie po indeksie
void LinkedList::showNode(int i)
{
    int j = 0;
    Node *temp = head;
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
        cout<< temp->data << " ";
    }
}

//Wyświetlenie listy
void LinkedList::showList()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    LinkedList myList;

    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(4);
    myList.pushBack(5);
    /*myList->popNode(2);
    myList->pushFront(10);
    myList->pushOnIndex(5, 1);*/

    myList.showList();
    cout << endl;
    //myList->showNode(0);

   // delete myList;

    system("pause >nul");

    return 0;
}
