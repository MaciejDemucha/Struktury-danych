#include <iostream>
#include <stdio.h>
#include <numeric>
#include <conio.h>
#include <chrono>
#include <cstdlib>
#include "bst.h"
#include "kopiec.h"
#include "lista2.h"
#include "tablica.h"

using namespace std;

void testTable();
void testList();
void testHeap();
void testBST();

int main()
{
    char c;

    while(true)
    {
        cout << "Wybierz strukture danych: \n";
        cout << "1. Tablica dynamiczna \n";
        cout << "2. Lista dwukierunkowa \n";
        cout << "3. Kopiec binarny \n";
        cout << "4. Drzewo BST \n";
        cout << "5. Wyjscie \n";

        c = getch();

        switch(c)
        {
            case '1':
                testTable();
                break;

             case '2':
                 testList();
                break;

             case '3':
                 testHeap();
                break;

             case '4':
                 testBST();
                break;

             case '5':
                exit(0);

             default:
                cout << "Zly numer \n";

        }
    }

    //bst
   /*Node b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 10);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.Delete(root, 10);
    b.Delete(root, 80);
    b.Delete(root, 40);

    b.Inorder(root);*/

    //kopiec
   /* MinHeap h(11);
    h.push(3);
    h.push(2);
    h.push(15);
    h.push(5);
    h.push(4);
    h.push(45);
    h.print();
    h.pop();
    h.print();
    h.pop();
    h.print();
    h.pop();
    h.print();
    h.pop();
    h.print();
    h.pop();
    h.print();
    h.pop();*/


    //lista
    /*


    myList->addOnEnd(3);
    myList->addOnEnd(4);
    cout << "Lista przed usunieciem: ";
    myList->showList();
    myList->deleteElement(2);
    cout << "Lista po usunieciu: ";
    myList->showList();
    myList->addOnBeg(10);
    myList->addOnEnd(5);
    myList->addOnIndex(5, 1);
    myList->addOnIndex(7, 4);
    myList->addOnIndex(6, 5);

    cout << "Lista po dodaniu: ";
    myList->showList();
    cout << "\nOd konca: ";
    myList->showReverse();
    cout << "\nElement na 1. pozycji: ";
    myList->showElement(1);
    myList->searchValue(7);

    //myList->prevNext();

    delete myList;*/

    system("pause >nul");
    return 0;
}

void testTable()
{
    char c;

    while(true)
    {
        cout << "Wybierz operacje: \n";
        cout << "1. Dodawanie \n";
        cout << "2. Usuwanie z tablicy \n";
        cout << "3. Wyszukiwanie elementu \n";
        cout << "4. Wyjscie \n";

        c = getch();

        switch(c)
        {
            case '1':
            {
                Table *myTab = new Table;

            int el, razy, x, i;
            cout << "Ile elementow dodac do tablicy? ";
            cin >> el;
            cout << "Ile razy dodac elementy do tablicy? ";
            cin >> razy;
            cout << "1. Na poczatek\n";
            cout << "2. Na koniec\n";
            cout << "3. Na indeks\n";
            cin >> x;

            if(x == 2)
            {
                i = INT_MAX;
            }

            else if(x == 3)
            {
                cout << "Podaj indeks: \n";
                cin >> i;
            }

            else
            {
                i = 0;
            }

            auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
            for( int j = 0; j < razy; ++j )
                {
                    for( int k = 0; k < el; ++k )
                        myTab->addOnIndex( rand() % 1000, i); //dodaj do tablicy losowa wartosc z przedzialu <0-999>

                        myTab->showTable();
                        cout << endl;
                        myTab->clearTable(); //zwolnij pamiec po kazdym dodaniu elementow do tablicy
                }

                auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                chrono::duration < double > czas = stop - start; //odejmij czasy
                cout << "\nSredni czas dodawania elementow do tablicy:" << (czas.count() / razy )* 1000 << " ms\n"; //wyswietl w milisekundach


            break;
            }

             case '2':
                 {
                    Table *myTab = new Table;
                    int el, razy, x, i;
                    cout << "Ile elementow dodac do tablicy? ";
                    cin >> el;
                    cout << "Ile razy wykonac operacje? ";
                    cin >> razy;

                    cout << "\nUsuwanie: \n";
                    cout << "1. Z poczatku\n";
                    cout << "2. Z konca\n";
                    cout << "3. Wg. indeksu\n";
                    cin >> x;

                    if(x == 2)
                    {
                        i = INT_MAX;
                    }

                    else if(x == 3)
                    {
                        cout << "Podaj indeks: \n";
                        cin >> i;
                    }

                    else
                    {
                        i = 0;
                    }

                    auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                    for( int k = 0; k < razy; ++k )
                    {
                        for( int j = 0; j < el; ++j )
                            myTab->addOnIndex( rand() % 1000, 0); //dodaj na poczatek tablicy losowa wartosc z przedzialu <0-999>

                        for( int j = 0; j < el; ++j )
                        {
                            myTab->deleteElement(i);
                            myTab->showTable();
                        }

                        cout << endl;
                        myTab->clearTable(); //zwolnij pamiec po kazdym dodaniu elementow do tablicy
                    }
                    auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                    chrono::duration < double > czas = stop - start; //odejmij czasy
                    cout << "\nSredni czas usuwania elementow z tablicy:" << (czas.count() / razy)* 1000 << " ms\n"; //wyswietl w milisekundach

                    break;
                 }


             case '3':
                {
                    Table *myTab = new Table;
                    int el, razy, x;
                    cout << "Ile elementow dodac do tablicy? ";
                    cin >> el;
                    cout << "Ile razy wykonac operacje? ";
                    cin >> razy;

                    auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                    for( int k = 0; k < razy; ++k )
                    {
                        for( int j = 0; j < el; ++j )
                            myTab->addOnIndex( rand() % 1000, 0); //dodaj na poczatek tablicy losowa wartosc z przedzialu <0-999>

                        for( int j = 0; j < el; ++j )
                            myTab->searchValue(rand() % 1000);

                        cout << endl;
                        myTab->clearTable(); //zwolnij pamiec po kazdym dodaniu elementow do tablicy
                    }
                    auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                    chrono::duration < double > czas = stop - start; //odejmij czasy
                    cout << "\nSredni czas wyszukiwania elementow w tablicy:" << (czas.count() / razy)* 1000 << " ms\n"; //wyswietl w milisekundach

                    break;
                }

             case '4':
                exit(0);

             default:
                cout << "Zly numer \n";
            }

    }
}




void testList()
{
    char c;

    while(true)
    {
        cout << "Wybierz operacje: \n";
        cout << "1. Dodawanie do listy \n";
        cout << "2. Usuwanie z listy \n";
        cout << "3. Wyszukiwanie elementu \n";
        cout << "4. Wyjscie \n";

        c = getch();

        switch(c)
        {
            case '1':
            {
                OneList *myList = new OneList;

                int el, razy, x, i;
                cout << "Ile elementow dodac do listy? ";
                cin >> el;
                cout << "Ile razy wykonac operacje? ";
                cin >> razy;
                cout << "1. Na poczatek\n";
                cout << "2. Na koniec\n";
                cout << "3. Na indeks\n";
                cin >> x;

                if(x == 2)
                {
                    i = INT_MAX;
                }

                else if(x == 3)
                {
                    cout << "Podaj indeks: \n";
                    cin >> i;
                }

                else
                {
                    i = 0;
                }

                auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                for( int j = 0; j < razy; ++j )
                {
                    for( int k = 0; k < el; ++k )
                        myList->addOnIndex( rand() % 1000, i); //dodaj do listy losowa wartosc z przedzialu <0-999>

                        myList->showList();
                        cout << endl;
                        myList->clearList(); //zwolnij pamiec po kazdym dodaniu elementow do listy
                }

                auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                chrono::duration < double > czas = stop - start; //odejmij czasy
                cout << "\nSredni czas dodawania elementow do listy:" << (czas.count() / razy )* 1000 << " ms\n"; //wyswietl w milisekundach

                break;
            }
            case '2':
            {
                OneList *myList = new OneList;
                int el, razy, x, i;
                    cout << "Ile elementow dodac do listy? ";
                    cin >> el;
                    cout << "Ile razy wykonac operacje? ";
                    cin >> razy;

                    cout << "\nUsuwanie: \n";
                    cout << "1. Z poczatku\n";
                    cout << "2. Z konca\n";
                    cout << "3. Wg. indeksu\n";
                    cin >> x;

                    if(x == 2)
                    {
                        i = INT_MAX;
                    }

                    else if(x == 3)
                    {
                        cout << "Podaj indeks: \n";
                        cin >> i;
                    }

                    else
                    {
                        i = 0;
                    }

                    auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                    for( int k = 0; k < razy; ++k )
                    {
                        for( int j = 0; j < el; ++j )
                            myList->addOnIndex( rand() % 1000, 0); //dodaj na poczatek tablicy losowa wartosc z przedzialu <0-999>

                        for( int j = 0; j < el; ++j )
                        {
                            myList->deleteElement(i);
                            myList->showList();
                        }

                        cout << endl;
                        myList->clearList(); //zwolnij pamiec po kazdym dodaniu elementow do tablicy
                    }
                    auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                    chrono::duration < double > czas = stop - start; //odejmij czasy
                    cout << "\nSredni czas usuwania elementow z listy:" << (czas.count() / razy)* 1000 << " ms\n"; //wyswietl w milisekundach
                break;
            }
            case '3':
            {
                break;
            }
            case '4':
            {
                break;
            }
            default:
                cout << "Zly numer \n";
        }
    }
}
void testHeap()
{
    char c;

    while(true)
    {
        cout << "Wybierz operacje: \n";
        cout << "1. Dodawanie \n";
        cout << "2. Usuwanie z tablicy \n";
        cout << "3. Wyszukiwanie elementu \n";
        cout << "4. Wyjscie \n";

        c = getch();

        switch(c)
        {
            case '1':
            {
                break;
            }
            case '2':
            {
                break;
            }
            case '3':
            {
                break;
            }
            case '4':
            {
                break;
            }
            default:
                cout << "Zly numer \n";
        }
    }
}
void testBST()
{
    char c;

    while(true)
    {
        cout << "Wybierz operacje: \n";
        cout << "1. Dodawanie \n";
        cout << "2. Usuwanie z tablicy \n";
        cout << "3. Wyszukiwanie elementu \n";
        cout << "4. Wyjscie \n";

        c = getch();

        switch(c)
        {
            case '1':
            {
                break;
            }
            case '2':
            {
                break;
            }
            case '3':
            {
                break;
            }
            case '4':
            {
                break;
            }
            default:
                cout << "Zly numer \n";
        }
    }
}
