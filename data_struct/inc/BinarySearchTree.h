/*
 * BinarySearchTree.h
 *
 *  Created on: Jan 22, 2018
 *      Author: yewei
 */

#ifndef DATA_STRUCT_INC_BINARYSEARCHTREE_H_
#define DATA_STRUCT_INC_BINARYSEARCHTREE_H_
#include <iostream>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;


template<typename KeyType,typename ElemType>
class BST{
private:
	struct Node{
		ElemType data;
		KeyType key;
		Node *left;
		Node *right;
		Node(KeyType ele,ElemType key){
			this->data = ele;
			this->key = key;
			this->left = this->right = NULL;
		}
	};
	Node *TreeRoot;
	int count;
public:
	BST(){
		TreeRoot = NULL;
		count = 0;
	}

	~BST(){
		destroy(TreeRoot);
	}

	int Getsize(){
		return count;
	}

	bool isEmpty(){
		if(count==0)
			return TRUE;
		else return FALSE;
	}

	bool contain(KeyType key){
		return contain(TreeRoot,key);
	}

	ElemType search(KeyType key){
		return search(TreeRoot,key);
	}

	void preOrder(){
		preOrder(TreeRoot);
	}

	void inOrder(){
		inOrder(TreeRoot);
	}

	void postOrder(){
		postOrder(TreeRoot);
	}

	void insert(KeyType key,ElemType ele){
		TreeRoot = insert(TreeRoot,key,ele);
	}
private:
	//插入二叉树节点
	Node* insert(Node *node,KeyType key,ElemType ele){
		if(node==NULL){
			count++;
			return (new Node(key,ele));
		}
		if(key == node->key)
			node->data = ele;
		else if(key < (node->key)){
			node->left = insert(node->left,key,ele);
		}
		else if(key > (node->key)){
			node->right = insert(node->right,key,ele);
		}
		return node;
	}

	Status contain(Node *node,KeyType key){
		if(node==NULL){
			return FALSE;
		}
		if(key==node->key){
			return TRUE;
		}
		else if(key < (node->key)){
			return contain(node->left,key);
		}
		else if(key > (node->key)){
			return contain(node->right,key);
		}
	}

	ElemType search(Node *node,KeyType key){
		if(node==NULL)
			return FALSE;
		if(key==node->key){
			return node->data;
		}
		else if(key < (node->key)){
			return search(node->left,key);
		}
		else if(key > (node->key)){
			return search(node->right,key);
		}
	}

 // 对以node为根的二叉搜索树进行前序遍历, 递归算法
	void preOrder(Node* node){
		if( node != NULL ){
			std::cout<<node->key<<std::endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	// 对以node为根的二叉搜索树进行中序遍历, 递归算法
	void inOrder(Node* node){
		if( node != NULL ){
			inOrder(node->left);
			std::cout<<node->key<<std::endl;
			inOrder(node->right);
		}
	}

	// 对以node为根的二叉搜索树进行后序遍历, 递归算法
	void postOrder(Node* node){
		if( node != NULL ){
			postOrder(node->left);
			postOrder(node->right);
			std::cout<<node->key<<std::endl;
		}
	}

	void destroy(Node* node){
		if(node!=NULL){
			destroy(node->left);
			destroy(node->right);
			delete node;
			count --;
		}
	}


};

void binary_search_tree_unit_test();


#endif /* DATA_STRUCT_INC_BINARYSEARCHTREE_H_ */
