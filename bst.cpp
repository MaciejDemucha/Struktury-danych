#include "bst.h"

using namespace std;

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
    if (!root)
    {
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


