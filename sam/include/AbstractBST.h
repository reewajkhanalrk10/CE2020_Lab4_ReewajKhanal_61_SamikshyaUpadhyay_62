
#ifndef AbstractBST_h
#define AbstractBST_h

class AbstractBST
{
public:
    virtual bool isEmpty() = 0;
    virtual void add(int key, int value) = 0;
    virtual void remove(int targetkey) = 0;
    virtual bool search(int targetKey) = 0;
    virtual void inorder() = 0;
};
#endif
