#pragma once
#include <list>
#include <iostream>
using namespace std;
enum  state { empty, full, deleted };
template<class K, class T>
class Item
{
public:
	T data;
	K key;
	state flag;
	Item() { key = K(); data = T(); flag = empty; } //defult c-tor
	Item(K k, T d) { data = d; key = k; } 
	Item(K k, T d, state f) { data = d; key = k; flag = f; }


};
