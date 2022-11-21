#include <iostream>
#include "../include/ArrayBST.h"

arraybinarysearchtree::arraybinarysearchtree()
{
    for (int i = 0; i < MAX_NUM_NODES; i++)
    {
        this->nodes[i] = NULL;
    }
}
arraybinarysearchtree::~arraybinarysearchtree() //making destructor
{
    int i;
    for (i = 1; i <= MAX_NUM_NODES; i++)
    {

        delete this->nodes[i];
        this->nodes[i] = NULL;
    }
}

bool arraybinarysearchtree::isEmpty()
{
    return this->nodes[1] == NULL;
}
void arraybinarysearchtree::add(int key, int value)
{
    ArrayNode *newData(new ArrayNode(key, value));

    for (int i = 1; i < MAX_NUM_NODES;)
    {
        ArrayNode *node = this->nodes[i];

        if (node == NULL)
        {
            this->nodes[i] = newData;
            break;
        }
        //adding on right if the current node's key is less than the new key
        else if (node->key < key)
        {
            i = 2 * i + 1;
        }

        //adding right if the current node's key is less than the new key
        else
        {
            i = 2 * i;
        }
    }
}

void arraybinarysearchtree::remove(int targetKey)
{
    if (this->search(targetKey)) //if the target key exists in the BST
    {
        std::cout <<"Removing the key : " << targetKey << std::endl;
        int n2d_i = this->index_of_target_key(targetKey);
        int min_nd_i = this->index_of_target_key(targetKey);
        int max_nd_i = min_nd_i;
        if (this->nodes[min_nd_i * 2] == NULL && this->nodes[min_nd_i * 2 + 1] == NULL)
        {
            this->nodes[min_nd_i] = NULL;
        }
        else if (this->nodes[min_nd_i * 2 + 1] != NULL)
        {
            min_nd_i = min_nd_i * 2 + 1;
            while (this->nodes[min_nd_i] != NULL)
                      {
                if (this->nodes[min_nd_i * 2] != NULL)  //checking if there is any  left child after the next right child
                    {
                    while (this->nodes[min_nd_i * 2] != NULL)
                    {
                        min_nd_i = min_nd_i * 2; //minimum node
                    
                    }
                }
                this->nodes[n2d_i] = this->nodes[min_nd_i];
                n2d_i = min_nd_i;
                this->nodes[min_nd_i] = NULL;
                if (this->nodes[min_nd_i * 2 + 1] != NULL)
                {
                    min_nd_i = min_nd_i * 2 + 1;
                }
            }
        }
        //has no right child from its parent
        else if (this->nodes[max_nd_i * 2 + 1] == NULL)
        {
            max_nd_i = max_nd_i * 2;
            while (this->nodes[max_nd_i] != NULL)  //if not found
           
            {
                //if right child exist
                if (this->nodes[max_nd_i * 2 + 1] != NULL)
                //checking if there is any  right child after the next left child
                {
                    while (this->nodes[max_nd_i * 2 + 1] != NULL)
                    {
                        max_nd_i = max_nd_i * 2 + 1;
                        //keeping minimum node's index to the last left most leave as it is the minimum node
                    }
                }

                this->nodes[n2d_i] = this->nodes[max_nd_i];
                n2d_i = max_nd_i;
                this->nodes[max_nd_i] = NULL;
                if (this->nodes[max_nd_i * 2] != NULL)
                {
                    max_nd_i = max_nd_i * 2;
                }
            }
        }
    }

    else
    {
        std::cout << "The target key doesnt exist." << std::endl;
    }
}

bool arraybinarysearchtree::search(int targetKey)
{

    int i = 1;
    bool found = false;
    while (i < MAX_NUM_NODES)
    {
        ArrayNode *node = this->nodes[i];
        if (node == NULL)
        {
            break;
        }
        else if (node->key == targetKey)
        {
            found = true;
            break;
        }
        else if (node->key < targetKey)
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * i;
        }
    }
    return found;
}

int arraybinarysearchtree::index_of_target_key(int targetKey)
{
    int i = 1;
    int index;
    while (i < MAX_NUM_NODES)
    {
        ArrayNode *node = this->nodes[i];
        if (node == NULL)
        {
            break;
        }
        else if (node->key == targetKey)
        {
            index = i;
            break;
        }
        else if (node->key < targetKey)
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * i;
        }
    }
    return index;
}

void arraybinarysearchtree::inorder()
{
    std::cout << "Inorder traversal BST:: " << std::endl;
    this->inorder(1);
    std::cout << std::endl;
}

void arraybinarysearchtree::inorder(int index, char sep)
{
    if (index < MAX_NUM_NODES && nodes[index] != NULL)
    {
        this->inorder(2 * index);
        std::cout << nodes[index]->key << sep;
        this->inorder(2 * index + 1);
    }
}
