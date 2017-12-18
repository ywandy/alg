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


template<typename KeyType,typename RcdType>
class HashItem{
	RcdType Val;
	KeyType Key;
	//int Size_value,Size_Key;
public:
//	HashItem(RcdType* value,KeyType* key,int size_value,int size_key):Size_value(size_value),Size_Key(size_key){
//		RcdType* value_tmp = new RcdType[size_value];
//		KeyType* key_tmp = new KeyType[size_key];
//		memcpy(value_tmp,value,size_value);
//		memcpy(key_tmp,key,size_key);
//	}
	HashItem(KeyType key,RcdType value):Key(key),Val(value){}
	//int getSize(){return Size_value;}
	RcdType getValue(){return Val;}
	KeyType getKey(){return Key;}

};


template<typename KeyType,typename RcdType>
class HashTable{
private:
	HashItem<KeyType,RcdType> **table;
	int size;
public:
	HashTable(int size);
	~HashTable();
	void InsertHash(KeyType key,RcdType val);
	RcdType SearchHash(KeyType key);
	static int hash(KeyType key,int hashsize){
		return key%hashsize;
	};
};

template<typename KeyType,typename RcdType>
HashTable<KeyType,RcdType>::HashTable(int inp_size){
	table = new HashItem<KeyType,RcdType>*[inp_size]();
	size = inp_size;
}

template<typename KeyType,typename RcdType>
HashTable<KeyType,RcdType>::~HashTable(){
	for(int i=0;i<size;i++)
		if(table[i]!=NULL)delete table[i];
	delete[] table;
}

template<typename KeyType,typename RcdType>
void HashTable<KeyType,RcdType>::InsertHash(KeyType key,RcdType val){
	int ind = hash(key,size);
	if(table[ind]!=NULL)
		delete table[ind];
	table[ind] = new HashItem<KeyType,RcdType>(key, val);
}

template<typename KeyType,typename RcdType>
RcdType HashTable<KeyType,RcdType>::SearchHash(KeyType key){
	if(table[hash(key,size)]!=NULL)
		return table[hash(key,size)]->getValue();
	return ERROR;
}

void unit_test_HashMap();

#endif /* DATA_STRUCT_INC_HASHMAP_H_ */
