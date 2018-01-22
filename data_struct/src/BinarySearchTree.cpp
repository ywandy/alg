/*
 * BinarySearchTree.cpp
 *
 *  Created on: Jan 22, 2018
 *      Author: yewei
 */

#include <BinarySearchTree.h>
#include <ctime>
#define NUM 10
void binary_search_tree_unit_test(){
	BST<int,int> *bst = new BST<int,int>();
	for(int i=0;i<NUM;i++){
		int key,value;
		key = value = rand()%100;
		(*bst).insert(key,value);
		std::cout<<key<<" ";
	}
	std::cout<<std::endl;

	std::cout<<"bst 's size:"<<(*bst).Getsize()<<std::endl;

	std::cout<<"preOrder:"<<std::endl;
	(*bst).preOrder();
	std::cout<<std::endl;

	std::cout<<"inOrder:"<<std::endl;
	(*bst).inOrder();
	std::cout<<std::endl;

	std::cout<<"postOrder:"<<std::endl;
	(*bst).postOrder();
	std::cout<<std::endl;

	std::cout<<"depth:"<<(*bst).bitTreeDepth()<<std::endl<<std::endl;

	std::cout<<"level order traverse:"<<std::endl;
	(*bst).LevelOrderTraverse();

}
