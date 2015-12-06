#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T key;
    Node<T>* p;
    Node<T>* left;
    Node<T>* right;

    Node(T x):key(x),p(nullptr),left(nullptr),right(nullptr) {};
};

template <class T>
class BinarySearchTree
{
public:
    Node<T>* root;

    BinarySearchTree():root(nullptr) {};
};

template <class T>
void InorderTreeWalk(Node<T>* n)
{
    if(n != nullptr)
    {
        InorderTreeWalk(n->left);
        cout << n->key << "\t";
        InorderTreeWalk(n->right);
    }
}

template <class T>
Node<T>* TreeSearch(Node<T>* n, T value)
{
    if (n == nullptr || n->key == value)
        return n;
    if (value < n->key)
        TreeSearch(n->left, value);
    else
        TreeSearch(n->right, value);
}

template <class T>
Node<T>* TreeMaximum(Node<T>* n)
{
    if (n->right != nullptr)
        return TreeMaximum(n->right);
    return n;
}

template <class T>
Node<T>* TreeMinimum(Node<T>* n)
{
    if (n->left != nullptr)
        return TreeMinimum(n->left);
    return n;
}

template <class T>
Node<T>* TreeSuccessor(Node<T>* n)
{
    if (n->right != nullptr)
        return TreeMinimum(n->right);
    Node<T>* y = n->p;
    while(y->right == n && y != nullptr)
        y = y->p;
    return y;
}

template <class T>
Node<T>* TreePredecessor(Node<T>* n)
{
    if (n->left != nullptr)
        return TreeMaximum(n->left);
    Node<T>* y = n->p;
    while(y->left == n && y != nullptr)
        y = y->p;
    return y;
}

template <class T>
void Transplant(BinarySearchTree<T>* R, Node<T>* u, Node<T>* v)
{
    if (u->p == nullptr)
        R->root = v;
    else if (u->p->left == u)
        u->p->left = v;
    else
        u->p->right = v;
    if(v != nullptr)
        v->p = u->p;

}

template <class T>
void TreeInsert(BinarySearchTree<T>* R, Node<T>* n)
{
    Node<T>* y = nullptr;
    Node<T>* x = R->root;
    while(x != nullptr)
    {
        y = x;
        if(n->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    n->p = y;
    if(y == nullptr)
        R->root = n;
    else if (n->key < y->key)
        y->left = n;
    else
        y->right = n;
}

template <class T>
void TreeDelete(BinarySearchTree<T>*R, Node<T>* n)
{
    if(n->left == nullptr)
        Transplant(R, n, n->right);
    else if (n->right == nullptr)
        Transplant(R, n, n->left);
    else
    {
        Node<T>* tmp = TreeMinimum(n->right);
        if (tmp->p != n)
        {
            Transplant(R, tmp, tmp->right);
            tmp->right = n->right;
            tmp->right->p = tmp;
        }
        Transplant(R, n, tmp);
        tmp->left = n->left;
        tmp->left->p = tmp;
    }
}

int main()
{
    int A[] = {5,7,3,5,8,9,1,2,7,8};
    Node<int>* node[10];
    BinarySearchTree<int> tree;
    BinarySearchTree<int>* Tree = &tree;
    for(int i = 0; i < 10; i++)
    {
        node[i] = new Node<int>(A[i]);
        TreeInsert(Tree,node[i]);
    }
    InorderTreeWalk(Tree->root);
    delete[] node;
    return 0;
}
