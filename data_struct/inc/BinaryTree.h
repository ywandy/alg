/*
 * BinaryTree.h
 *
 *  Created on: Dec 20, 2017
 *      Author: yewei
 */

#ifndef DATA_STRUCT_INC_BINARYTREE_H_
#define DATA_STRUCT_INC_BINARYTREE_H_
#include <iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;

template<typename ElemType>
struct BitNode{
	ElemType data;
	struct BitNode *lchild,*rchild;
};

template<typename ElemType>
class BiTree{
private:
	BitNode<ElemType> *TreeRoot;
public:
	BiTree(ElemType e);
	~BiTree();
	BitNode<ElemType>* MakeBiTree(ElemType e,BitNode<ElemType> *L,BitNode<ElemType> *R);
	void DestoryBiTree(BitNode<ElemType> *T);
	Status BiTreeEmpty(BitNode<ElemType> *T);
	Status BreakBiTree(BitNode<ElemType> *T,BitNode<ElemType> *L,BitNode<ElemType> *R);
	Status ReplaceLeft(BitNode<ElemType> *T,BitNode<ElemType> *LT);
	Status ReplaceRight(BitNode<ElemType> *T,BitNode<ElemType> *RT);
	Status CutLeft(BitNode<ElemType> *T,BitNode<ElemType> *LT);
	Status CutRight(BitNode<ElemType> *T,BitNode<ElemType> *RT);
};

template<typename ElemType>
BiTree<ElemType>::BiTree(ElemType e){
	TreeRoot = new BitNode<ElemType>;
	if(t==NULL)
		exit(-1);
	TreeRoot->data = e;
}

#endif /* DATA_STRUCT_INC_BINARYTREE_H_ */
