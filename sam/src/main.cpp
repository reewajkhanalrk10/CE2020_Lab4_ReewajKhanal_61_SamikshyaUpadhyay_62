#include <iostream>
#include "../include/ArrayBST.h"

int main()
{
    arraybinarysearchtree a;
    std::cout << "The tree is empty :" << a.isEmpty() << std::endl;
    a.add(5, 1);
    a.add(4, 2);
    a.add(20, -1);
    a.add(22, -1);
    
    a.add(60, -1);
    a.add(25, -1);
    a.add(35,9);
    a.remove(20);
    
    a.inorder();
    a.remove(19);
    a.inorder();
    a.remove(22);
    a.inorder();
    a.remove(3);
    a.inorder();
}
