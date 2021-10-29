#pragma once
#include "Item.h"





static bool isPrime(int num) //the func check if the number is primary
{

	int count = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
			count++;
	}

	return (count == 2);
}


template<class K, class T>
class HashTable
{
public:
	list<Item<K, T> >* table;
	HashTable() {}
	HashTable(int size)  //c-tor ,accepts as a parameter the size of the table and initializes a table in the size of a prime number closest to the requested size
	{
		while (!isPrime(size))
			size++;
		this->size = size;
		table = new list<Item<K, T> >(size);
	typename list<Item<K,T> >::iterator it = this->table->begin();
		while (it != this->table->end())
		{

			(*it).flag = empty;
			it++;
		}
	};
	~HashTable() //d-tor
	{
	    this->table->clear();
	}

	virtual int h1(K key) = 0; //h1  hashing function that receives a type K key and returns a position in the table
	virtual int h2(K key) = 0;//h2 skip function
	int hash(K k, int i); //The function that returns the position in the table for key k in attempt i
	void update(K key, T data);//Function for updating (repositioning) an organ at a specific place in the table. (Provided his key is unchanged).
	int search(K key); // A search function variable (if the member is found, returns its entry number; otherwise, returns 1-).
	void insert(K key, T data); // Function for inserting an organ into a table.
	void erase(K key); //Delete a subject
protected:
	int size; //size of the table
};

template<class K, class T>
int HashTable<K, T>::hash(K k, int i)
{
	return (h1(k) + i * h2(k)) % size;
}



template<class K, class T>
int HashTable<K, T>::search(K key)
{
	int index = 0;
	int indexToInsert = hash(key, index);
	while (indexToInsert != size)
	{
		typename list<Item<K,T> >::iterator  l_front = this->table->begin();

		advance(l_front, indexToInsert);
		if ((*l_front).flag == empty)
		{
			return -1;
		}
		else if ((*l_front).key == key)
		{
			return indexToInsert;
		}
		index++;
		indexToInsert = hash(key, index);
	}
	return -1;
}

template<class K, class T>
void HashTable<K, T>::insert(K key, T data)
{
	if (search(key) != -1)
		return;
	int index = 0;
	int indexToInsert = hash(key, index);
	while (indexToInsert != size)
	{
		typename list<Item<K,T> >::iterator   l_front = this->table->begin();

		advance(l_front, indexToInsert);
		if ((*l_front).flag == empty)
		{
			typename list<Item<K,T> >::iterator  it = table->begin();
			Item<K, T>* newItem = new Item<K, T>(key, data);
			(*newItem).flag = full;
			advance(it, indexToInsert);
			*it = *newItem;
			return;
		}
		index++;
		indexToInsert = hash(key, index);
	}
	return;
}
template<class K, class T>
void HashTable<K, T>::erase(K key)
{
	int index = search(key);
	if (index == -1)
		return;
	typename list<Item<K,T> >::iterator it = this->table->begin();
	advance(it, index);
	
		(*it).flag = deleted;
	
	
}
template<class K, class T>
void HashTable<K, T>::update(K key, T data)
{
	int index = search(key);
	if (index == -1)
		return;
 typename list<Item<K,T> >::iterator  it = this->table->begin();
	advance(it, index);
	if ((*it).flag != deleted)
	{
		(*it).data = data;
		(*it).flag = full;
	}
	//throw new exception("This item was erased ");
}

