#include<iostream>	
	#include "LinkedListBST.cpp"
	
	
	int main()

	{

	// LinkedBST implementation starts from here

	std::cout<<"\nLinked -> List BST Implementation \n \n 1 = True \n 0 = False\n"<<std::endl;
	
	linkedBST * BST = new linkedBST();
	
	std::cout<<BST->isempty()<<std::endl;

	BST->add(5);

	std::cout<<BST->isempty()<<std::endl;

	BST->removeBST(BST->root, 1);
	BST->removeBST(BST->root, 5);
	BST->add(1);
	BST->add(2);
	BST->add(3);
	BST->add(4);
	BST->add(7);
	BST->exists(1);
	BST->exists(10);

	}
