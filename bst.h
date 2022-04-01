#ifndef BST_H
#define BST_H

#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

class NodeBST
{
public:
    int data;                                       //wartosc w wezle
    NodeBST* left;                                  //wskaznik na lewego potomka
    NodeBST* right;                                 //wskaznik na prawego potomka
    NodeBST* root;                                  //wskaznik na korzen
    NodeBST();                                      //konstruktor bez wartosci
    NodeBST(int value);                             //konstruktor z podaniem wartosci do dodania
    NodeBST* Insert(NodeBST* root, int data);       //dodawanie nowego elementu
    void Inorder(NodeBST* root);                    //wyswietlenie w porzadku rosnacym
    bool Search(NodeBST* root, int data);           //wyszukanie podanej wartosci
    NodeBST* Delete(NodeBST* root, int data);       //usuniecie wartosci
    NodeBST* FindMin(NodeBST* root);                //znalezienie wartosci minimalnej
    void ClearBST(NodeBST* root);                   //usuniecie z pamieci
    NodeBST* GetRoot(NodeBST* root);                //zwrocenie korzenia
};

#endif
