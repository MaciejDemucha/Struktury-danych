#include "bst.h"

using namespace std;

//konstruktor bez wartosci
NodeBST::NodeBST()
{
    root = left = right = nullptr;
}
//konstruktor z podaniem wartosci do dodania
NodeBST::NodeBST(int value)
{
    data = value;
    root = left = right = nullptr;
}
//zwrocenie korzenia
NodeBST* NodeBST::GetRoot(NodeBST* root)
{
    return root;
}
//dodawanie nowego elementu
NodeBST* NodeBST::Insert(NodeBST* root, int data)
{
    NodeBST* newNode = new NodeBST(data); //utworzenie wezla z danymi

    if(root == NULL)
    {
        root = newNode; //kiedy BST jest puste, element jest korzeniem
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data); //nowy element jest niewiekszy od korzenia, wstawiamy po lewej stronie
    }
    else
    {
        root->right = Insert(root->right, data); //nowy element jest wiekszy od korzenia, wstawiamy po prawej stronie
    }
    return root; //zwrocenie wartosci korzenia
}
//usuniecie wartosci
NodeBST* NodeBST ::Delete(NodeBST* root, int data)
{
    if(root == NULL) return NULL; //sprawdzenie czy root nie jest NULL

    //jesli wartosc usuwana jest mniejsza od rodzica, szukaj danej do usuniecia w lewym potomku
    else if(data < root->data)
        root->left = Delete(root->left, data);

    //jesli wartosc usuwana jest wieksza od rodzica, szukaj danej do usuniecia w prawym potomku
    else if(data > root->data)
        root->right = Delete(root->right, data);

    //jesli wartosci sie zgadzaja
    else
    {
        //usuniecie wezla bez potomkow
        if(root->left == NULL && root->right == NULL)
        {
           delete root;
           root = NULL;
        }
        //z 1 potomkiem
        else if(root->left == NULL)
        {
          NodeBST* temp = root; //przechowanie wartosci do usuniecia
          root = root->right;   //potomek przechodzi na miejsce rodzica
          delete temp;          //usuniecie wskazanej wartosci
        }
        else if(root->right == NULL)
        {
          NodeBST* temp = root; //przechowanie wartosci do usuniecia
          root = root->left;    //potomek przechodzi na miejsce rodzica
          delete temp;          //usuniecie wskazanej wartosci
        }
        //z 2 potomkami
        else
        {
            NodeBST* temp = FindMin(root->right); //znalezienie najmniejszego potomka w prawym podrzewie
            root->data = temp->data;              //wstawienie go w miejsce usuwanego elementu
            root->right = Delete(root->right, temp->data); //usuniecie potomka z jego poprzedniego miejsca
        }
        return root;

    }
}
//wyswietlenie w porzadku rosnacym, rekurencyjnie w kolejnosci lewy potomek, rodzic, prawy potomek
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
//wyszukanie podanej wartosci
bool NodeBST::Search(NodeBST* root, int data)
{
    if(root == NULL) return false; //sprawdzenie czy drzewo nie jest puste
    else if(root->data == data) return true; //znalezienie wartosci
    else if(data <= root->data) return Search(root->left, data); //jesli niewieksza, szukaj w lewmy potomku
    else return Search(root->right, data); //jesli wieksza, szukaj w prawym potomku
}
//znalezienie wartosci minimalnej przechodzac caly czas po lewym potomku
NodeBST* NodeBST ::FindMin(NodeBST* root)
{
    while(root->left)
    {
        root = root->left;
    }
    return root;
}
//usuniecie z pamieci
void NodeBST::ClearBST(NodeBST* root)
{
    if (root == NULL) return; //sprawdzenie czy drzewo nie jest puste

    //usuniecie potomkow rodzica
    if(root->left!=NULL) ClearBST(root->left);
    if(root->right!=NULL) ClearBST(root->right);

    //usuniecie rodzica
    delete root;
}


