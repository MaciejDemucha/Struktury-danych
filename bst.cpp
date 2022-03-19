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
    Node* Insert(Node* root, int data);
    void Inorder(Node* root);
    bool Search(Node* root, int data);
    Node* Delete(Node* root, int data);
    Node* FindMin(Node* root);
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

Node* Node::Insert(Node* root, int data)
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

Node* Node ::Delete(Node* root, int data)
{
    if(root == NULL) return NULL;

    else if(data < root->data)
        root->left = Delete(root->left, data);

    else if(data > root->data)
        root->right = Delete(root->right, data);

    else
    {
        if(root->left == NULL && root->right == NULL)
        {
           delete root;
           root = NULL;
        }
        else if(root->left == NULL)
        {
          Node* temp = root;
          root = root->right;
          delete temp;
        }
        else if(root->right == NULL)
        {
          Node* temp = root;
          root = root->left;
          delete temp;
        }
        else
        {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
        return root;

    }
}

void Node ::Inorder(Node* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

bool Node::Search(Node* root, int data)
{
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

Node* Node ::FindMin(Node* root)
{
    while(root->left)
    {
        root = root->left;
    }
    return root;
}

int main()
{
    Node b, *root = NULL;
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

    b.Inorder(root);


    return 0;


}
