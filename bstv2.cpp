#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node();
    Node(int value);
};

Node::Node()
{
    left = right = nullptr;
}

Node::Node(int value)
{
    data = value;
    left = right = nullptr;
}

class Tree
{
public:
    Node* root;
    Tree();
    Node* Insert(Node* root, int data);
    bool Search(Node* root, int data);
    void Inorder(Node* root);
};

Tree::Tree()
{
    root = nullptr;
}

Node* Tree::Insert(Node* root, int data)
{
    Node* newNode = new Node(data);

    if(root == NULL)
    {
        root = newNode;

    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

void Tree ::Inorder(Node* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

bool Tree::Search(Node* root, int data)
{
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

int main()
{
    Tree* myTree = new Tree();

    myTree->Insert(myTree->root, 5);
    //myTree->Insert(myTree->root, 6);
    //myTree->Insert(myTree->root, 7);
   // myTree->Insert(myTree->root, 4);

    cout << myTree->root->data;

    /*char c;
    while(c != 'q')
    {
        cout << "q to exit\n ";
        cout << "Enter a number: ";
        cin >> c;
        int number = c - '0';
        if(myTree->Search(myTree->root, number)) cout << "Found " << number << endl;
        else cout << "Not found " << number << endl;
    }*/

}
