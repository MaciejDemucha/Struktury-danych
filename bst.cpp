#include "bst.h"

using namespace std;

NodeBST::NodeBST()
{
    root = left = right = nullptr;
}

NodeBST::NodeBST(int value)
{
    data = value;
    root = left = right = nullptr;
}

NodeBST* NodeBST::GetRoot(NodeBST* root)
{
    return root;
}

NodeBST* NodeBST::Insert(NodeBST* root, int data)
{
    NodeBST* newNode = new NodeBST(data);

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

NodeBST* NodeBST ::Delete(NodeBST* root, int data)
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
          NodeBST* temp = root;
          root = root->right;
          delete temp;
        }
        else if(root->right == NULL)
        {
          NodeBST* temp = root;
          root = root->left;
          delete temp;
        }
        else
        {
            NodeBST* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
        return root;

    }
}

void NodeBST ::Inorder(NodeBST* root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

bool NodeBST::Search(NodeBST* root, int data)
{
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

NodeBST* NodeBST ::FindMin(NodeBST* root)
{
    while(root->left)
    {
        root = root->left;
    }
    return root;
}

void NodeBST::ClearBST(NodeBST* root)
{
    if (root == NULL) return;

    /* first delete both subtrees */
    if(root->left!=NULL) ClearBST(root->left);
    if(root->right!=NULL) ClearBST(root->right);

    /* then delete the node */
    //cout << "\n Deleting node: " << root->data;
    delete root;
}


