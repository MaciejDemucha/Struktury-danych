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
    NodeBST b, *root = NULL;
    root = b.Insert(root, 20);
    b.Insert(root, 30);
    b.Insert(root, 10);
    b.Insert(root, 40);
    b.Inorder(root);
    cout << root->FindMin(root)->data;
    root->Delete(root, root->FindMin(root)->data);
    cout << endl;
    b.Inorder(root);



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
                        myList->showReverse();
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
                    cout << "Ile razy wykonac operacje?\n ";
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
                            myList->usun_osobe(i);
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
                OneList *myList = new OneList;
                    int el, razy, x;
                    cout << "Ile elementow dodac do listy? ";
                    cin >> el;
                    cout << "Ile razy wykonac operacje?\n ";
                    cin >> razy;

                    auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                    for( int k = 0; k < razy; ++k )
                    {
                        for( int j = 0; j < el; ++j )
                            myList->addOnIndex( rand() % 1000, 0); //dodaj na poczatek tablicy losowa wartosc z przedzialu <0-999>

                            myList->searchValue(rand() % 1000);

                        cout << endl;
                        myList->clearList(); //zwolnij pamiec po kazdym dodaniu elementow do tablicy
                    }
                    auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                    chrono::duration < double > czas = stop - start; //odejmij czasy
                    cout << "\nSredni czas wyszukiwania elementow w liscie:" << (czas.count() / razy)* 1000 << " ms\n"; //wyswietl w milisekundach

                    break;
            }
            case '4':
                exit(0);

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
        cout << "2. Usuwanie z kopca \n";
        cout << "3. Wyszukiwanie elementu \n";
        cout << "4. Wyjscie \n";

        c = getch();

        switch(c)
        {
            case '1':
            {
                int el, razy;
                cout << "Ile elementow dodac do kopca? ";
                cin >> el;
                cout << "Ile razy wykonac operacje?\n ";
                cin >> razy;

                MinHeap *myHeap = new MinHeap(el);

                auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                for( int j = 0; j < razy; ++j )
                {
                    for( int k = 0; k < el; ++k )
                        myHeap->push(rand() % 1000); //dodaj do kopca losowa wartosc z przedzialu <0-999>

                        myHeap->print();
                        cout << endl;
                        myHeap->clearHeap(); //zwolnij pamiec po kazdym dodaniu elementow do kopca
                }

                auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                chrono::duration < double > czas = stop - start; //odejmij czasy
                cout << "\nSredni czas dodawania elementow do kopca:" << (czas.count() / razy )* 1000 << " ms\n"; //wyswietl w milisekundach

                break;
            }
            case '2':
            {
                int el, razy;
                cout << "Ile elementow dodac do kopca? ";
                cin >> el;
                cout << "Ile razy wykonac operacje?\n ";
                cin >> razy;

                MinHeap *myHeap = new MinHeap(el);

                auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                for( int j = 0; j < razy; ++j )
                {
                    for( int j = 0; j < el; ++j )
                            myHeap->push( rand() % 1000); //dodaj na poczatek kopca losowa wartosc z przedzialu <0-999>

                        for( int j = 0; j < el; ++j )
                        {
                            myHeap->pop();
                            myHeap->print();
                        }

                        cout << endl;
                        myHeap->clearHeap(); //zwolnij pamiec po kazdym dodaniu elementow do kopca
                }

                auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                chrono::duration < double > czas = stop - start; //odejmij czasy
                cout << "\nSredni czas usuwania elementow z kopca:" << (czas.count() / razy )* 1000 << " ms\n"; //wyswietl w milisekundach

                break;
            }
            case '3':
            {
                int el, razy;
                cout << "Ile elementow dodac do kopca? ";
                cin >> el;
                cout << "Ile razy wykonac operacje?\n ";
                cin >> razy;

                MinHeap *myHeap = new MinHeap(el);

                auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                for( int k = 0; k < razy; ++k )
                    {
                        for( int j = 0; j < el; ++j )
                            myHeap->push( rand() % 1000); //dodaj na poczatek kopca losowa wartosc z przedzialu <0-999>

                            myHeap->searchValue(rand() % 1000);

                        cout << endl;
                        myHeap->clearHeap(); //zwolnij pamiec po kazdym dodaniu elementow do kopca
                    }

                auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                chrono::duration < double > czas = stop - start; //odejmij czasy
                cout << "\nSredni czas wyszukiwania elementow w kopcu:" << (czas.count() / razy )* 1000 << " ms\n"; //wyswietl w milisekundach

                break;
            }
            case '4':
            {
                exit(0);
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
        cout << "2. Usuwanie z BST \n";
        cout << "3. Wyszukiwanie elementu \n";
        cout << "4. Wyjscie \n";

        c = getch();

        switch(c)
        {
            case '1':
            {
                NodeBST b, *root = NULL;

                int el, razy;
                cout << "Ile elementow dodac do BST? ";
                cin >> el;
                cout << "Ile razy wykonac operacje?\n ";
                cin >> razy;

                auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                for( int j = 0; j < razy; ++j )
                {
                    root = b.Insert(root,NULL);

                    for( int k = 0; k < el; ++k )
                        root->Insert(root, rand() % 1000); //dodaj do BST losowa wartosc z przedzialu <0-999>

                        root->Inorder(root);
                        cout << endl;
                        b.ClearBST(root);
                        root = nullptr;
                }

                auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                chrono::duration < double > czas = stop - start; //odejmij czasy
                cout << "\nSredni czas dodawania elementow do BST:" << (czas.count() / razy )* 1000 << " ms\n"; //wyswietl w milisekundach

                break;
            }
            case '2':
            {
                NodeBST b, *root = NULL;

                int el, razy;
                cout << "Ile elementow dodac do BST? ";
                cin >> el;
                cout << "Ile razy wykonac operacje?\n ";
                cin >> razy;

                auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                for( int j = 0; j < razy; ++j )
                {
                    root = b.Insert(root,NULL);

                    for( int k = 0; k < el; ++k )
                        root->Insert(root, rand() % 1000); //dodaj do BST losowa wartosc z przedzialu <0-999>

                    for( int k = 0; k < el; ++k )
                    {
                        int data = root->FindMin(root)->data;
                        root->Delete(root, data);
                        root->Inorder(root);
                        cout << endl;
                    }
                        root = nullptr;
                }

                auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                chrono::duration < double > czas = stop - start; //odejmij czasy
                cout << "\nSredni czas usuwania elementow z BST:" << (czas.count() / razy )* 1000 << " ms\n"; //wyswietl w milisekundach

                break;
            }
            case '3':
            {
               NodeBST b, *root = NULL;

                int el, razy;
                cout << "Ile elementow dodac do BST? ";
                cin >> el;
                cout << "Ile razy wykonac operacje?\n ";
                cin >> razy;

                auto start = chrono::high_resolution_clock::now(); //poczatek odliczania
                for( int j = 0; j < razy; ++j )
                {
                    root = b.Insert(root,NULL);

                    for( int k = 0; k < el; ++k )
                        root->Insert(root, rand() % 1000); //dodaj do BST losowa wartosc z przedzialu <0-999>


                        int data = rand() % 1000;
                        if(root->Search(root, data))
                            cout << "Znaleziono liczbe: " << data;

                        else
                            cout << "Nie znaleziono liczby: " << data;

                        cout << endl;
                        b.ClearBST(root);
                        root = nullptr;
                }

                auto stop = chrono::high_resolution_clock::now(); //koniec odliczania
                chrono::duration < double > czas = stop - start; //odejmij czasy
                cout << "\nSredni czas wyszukiwania elementow w BST:" << (czas.count() / razy )* 1000 << " ms\n"; //wyswietl w milisekundach

                break;
            }
            case '4':
            {
                exit(0);
            }
            default:
                cout << "Zly numer \n";
        }
    }
}
