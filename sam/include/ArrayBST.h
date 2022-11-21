#ifndef ArrayBST_h
#define ArrayBST_h
#define MAX_NUM_NODES 128
#include "AbstractBST.h"

struct ArrayNode
{
    int key;
    int value;

    ArrayNode(int key, int value) : key(key), value(value) {}
};

class arraybinarysearchtree : public AbstractBST
{
public:
    arraybinarysearchtree();
    ~arraybinarysearchtree();

    //Checks if the BST is empty
    bool isEmpty();
    void add(int key, int value);
    bool search(int targetKey);
    int index_of_target_key(int targetKey);
    void remove(int targetKey);
    void inorder();

private:
    ArrayNode *nodes[MAX_NUM_NODES];
    void inorder(int index, char sep = ' ');
};
#endif
