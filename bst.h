#ifndef BST_H
#define BST_H

#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

class NodeBST
{
public:
    int data;
    NodeBST* left;
    NodeBST* right;
    NodeBST* root;
    NodeBST();
    NodeBST(int value);
    NodeBST* Insert(NodeBST* root, int data);
    void Inorder(NodeBST* root);
    bool Search(NodeBST* root, int data);
    NodeBST* Delete(NodeBST* root, int data);
    NodeBST* FindMin(NodeBST* root);
    void ClearBST(NodeBST* root);
    NodeBST* GetRoot(NodeBST* root);
};

#endif
