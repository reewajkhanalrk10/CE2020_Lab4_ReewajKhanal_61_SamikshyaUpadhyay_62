#ifndef LinkedListBST_H
#define LinkedListBST_H
#include "AbstractBST.h"

class  Node
{
    public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node() : leftChild(nullptr), rightChild(nullptr) {}
    Node(int data) : data(data), leftChild(nullptr), rightChild(nullptr) {}
    Node(int data, Node *leftChild, Node *rightChild) : data(data), leftChild(leftChild), rightChild(rightChild) {}
};

class linkedBST : public AbstractBST
{
    public:
        Node *root;
        linkedBST(): root(nullptr){}
        linkedBST(Node * r): root(r){}

        bool isempty();
        virtual void add(int key)
        {
            this ->addRec(this->root, key);
        }
        void addRec( Node*& r ,int value);

        virtual int max ()
        {
            
            return this->maxx(this->root)->data;
        }
        virtual int min ()
        {
             return this->minn(this->root)->data;
        }

        Node* maxx (Node *r);
        Node* minn (Node *r);
        bool removeBST(Node*& r, int dataToDelete);
        bool searchBST(Node *r,int searchValue);
        virtual void exists(int key)
        {
            searchBST(this->root, key);

        }
    
};
#endif