#include <iostream>
#include "LinkedListBST.h"

bool linkedBST:: isempty()
{
    if (!this->root)
    {
        std::cout<<"The BST is empty "<<std::endl;

        return true;
    }
        std::cout<<"The BST is not empty "<<std::endl;

    return false;
    
}

void linkedBST::addRec(Node*& r, int value)
{
    if(r==nullptr)
    {
        Node *newNode = new Node(value);
        r = newNode;
        std::cout<<value<<" added successfully!"<<std::endl;
         return;
    }

    if( value < r->data)
    {
        addRec(r->leftChild, value);
    }
    else
    {
         addRec(r->rightChild, value);
    }
}

bool linkedBST::searchBST(Node *r, int searchValue)
{
    if( r->data == searchValue)
    {
        std::cout<< searchValue<<" is found in the tree"<<std::endl;
        return true;
    }

     else if(searchValue< r->data )
    {
        if(r->leftChild == nullptr)
        {
           std::cout<< searchValue<<" is not found in the tree"<<std::endl;
            return false;
        }
       return searchBST(r->leftChild,searchValue);

    }
    else 
    {
        if(r->rightChild== nullptr)
        {
            std::cout<< searchValue<<" is not found in the tree"<<std::endl;
            return false;
        }
    
     return searchBST(r->rightChild, searchValue);
    
    }
}

 Node* linkedBST::maxx(Node *r)
{
    
    if(r->rightChild==nullptr)
    {
        return r;
    }
     return maxx(r->rightChild);   
}

Node* linkedBST::minn(Node *r)
{
    
    if(r->leftChild==nullptr)
    {
        return r;
    }
    
     return minn(r->leftChild);
    
}


bool linkedBST::removeBST(Node*& r, int dataToDelete)
{
    if(r->data == dataToDelete)
    {
        if(r->leftChild==nullptr && r->rightChild == nullptr)
        {
            if(r== this->root)
            {
                r= nullptr;
            }
            else{
                delete r;
            }
        }
        else if(r->leftChild != nullptr)
        {
            Node *temp = maxx(r->leftChild);
            r->data = temp ->data;
            delete temp;
        }
        else{
            Node *temp = minn(r->rightChild);
            r->data = temp->data;
            delete temp;
        }
        std::cout<< dataToDelete <<" has been removed successfully"<<std::endl;
        return true;
    }
    else if (dataToDelete < r->data)
    {
        if(r->leftChild == nullptr)
        {
            std::cout<<"the data is not found in the given tree"<<std::endl;
            return false;
        }
        return removeBST(r->leftChild, dataToDelete);
    }
    else
    {
        if(r->rightChild == nullptr)
        {
            std::cout<<"the data is not found in the given tree"<<std::endl;
            return false;
        }
        return removeBST(r->rightChild, dataToDelete);
    }
    
}