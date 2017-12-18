/*
 * HashMap.h
 *
 *  Created on: Dec 18, 2017
 *      Author: yewei
 */

#ifndef DATA_STRUCT_INC_HASHMAP_H_
#define DATA_STRUCT_INC_HASHMAP_H_
#include <iostream>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;


template<typename RcdType,typename KeyType>
class HashItem{
	RcdType Rcd;
	KeyType Key;
public:
	HashItem(RcdType R,KeyType K):Rcd(R),Key(K){}
	RcdType getRcd(){return Rcd;}
	KeyType getKey(){return Key;}

};


template<typename RcdType,typename KeyType>
class HashTable{
private:
	HashItem<RcdType,KeyType> **table;
	int size;
public:
	HashTable(int size);
	~HashTable();
	void InsertHash(RcdType val,KeyType key);
	Status SearchHash(KeyType key);
	static int hash(int key,int hashsize){
		return key%hashsize;
	};
};

template<typename RcdType,typename KeyType>
HashTable<RcdType,KeyType>::HashTable(int inp_size){
	table = new HashItem*[inp_size]();
	size = inp_size;
}

template<typename RcdType,typename KeyType>
HashTable<RcdType,KeyType>::~HashTable(){
	for(int i=0;i<size;i++)
		if(table[i]!=NULL)delete table[i];
	delete[] table;
}

template<typename RcdType,typename KeyType>
void HashTable<RcdType,KeyType>::InsertHash(RcdType val,KeyType key){
	int ind = hash(key,size);
	if(table[ind]!=NULL)
		delete table[ind];
	table[ind] = new HashItem(key, val);
}

template<typename RcdType,typename KeyType>
Status HashTable<RcdType,KeyType>::SearchHash(KeyType key){

}

void unit_test_HashMap();

#endif /* DATA_STRUCT_INC_HASHMAP_H_ */
