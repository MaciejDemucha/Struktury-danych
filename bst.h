#ifndef BST_H
#define BST_H

#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node();
    Node(int value);
    Node* Insert(Node* root, int data);
    void Inorder(Node* root);
    bool Search(Node* root, int data);
    Node* Delete(Node* root, int data);
    Node* FindMin(Node* root);
};

#endif
