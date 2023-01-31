//
//  main.cpp
//  Tree Traversal
//
//  Created by Ivan Reynoso on 1/30/23.
//



#include <iostream>

using namespace std;

 

template<typename T>

class Node

{

public:

       Node();

       Node(T e, Node<T>* r, Node<T>* l);

       T element;

       Node<T>* right;

       Node<T>* left;

};

template<typename T>

Node<T>::Node() { right = left = NULL; }

 

template<typename T>

Node<T>::Node(T e, Node<T>* r, Node<T>* l) { element = e; right = r; left = l; }

 

template<typename T>

class BTree

{

public:

       BTree() { root = NULL; }

       BTree(Node<T>* rt) { root = rt; }

       void BSTInsert(T value);

       void BSTRemove(T value);

       Node<T>*& getRoot() { return root; }

       Node<T>* BSTsearch(T value);

       int BSTNodeLevel(T value);

       void BSTPrint();

private:

       Node<T>* root;

       void deleteNode(Node<T>* z);

       void transplant(Node<T>* u, Node<T>* v);

       void print(Node<T>* a, int s);

};

 

 

template<typename T>

int  BTree<T>::BSTNodeLevel(T value)

{

       // set cur to the tree root, traverse down the tree to find the element.

       // As the code traverses down the tree, node level is incremented.

       // if node is not in the tree, -1 is returned as the node level.

       int level = 0;

       Node<T>* cur = root;

       while (cur != NULL)

       {

             if (value == cur->element)

                    return level;

             else if (value < cur->element)

                    cur = cur->left;

             else

                    cur = cur->right;

             level++;

       }

       return -1;

}

 

template<typename T>

Node<T>* BTree<T>::BSTsearch(T value)

{

       Node<T>* cur = root;

       while (cur != NULL)

       {

             if (value == cur->element)

                    return cur;

             else if (value < cur->element)

                    cur = cur->left;

             else

                    cur = cur->right;

       }

       return NULL;

}

 

template<typename T>

void BTree<T>::BSTPrint() {

       print(root, 0);

}

template<typename T>

void BTree<T>::print(Node<T>* a, int s) {

       if (a == NULL)

             return;

 

       s += 8;

       print(a->right, s);

       cout << endl;

       for (int i = 8; i < s; i++)

             cout << " ";

       cout << a->element << "\n";

       print(a->left, s);

}


