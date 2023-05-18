#include "Hash.h"
#include <iostream>


#ifdef VAR10
int HashFunction(int key, int size, int p)
{
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (p + key) % size;
}
#endif

#ifdef VAR1
int HashFunction(int key, int size, int p)
{
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (p + key) % size;
}
#endif

#ifdef VAR15
int HashFunction(int key, int size, int p)
{
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (p + key) % size;
}
#endif

#ifdef VAR9
int HashFunction(int key, int size, int p)
{
	return key % size;
}
#endif


#ifdef VAR15
int Next_hash(int key, int size, int p) {
	int h1 = key % size;
	int h2 = 1 + key % size;
	return h1 + (p * h2) % size;
}
#endif

#ifdef VAR9
int Next_hash(int hash, int size, int p) {
	return (hash + 5 * p + 3 * p * p) % size;
}
#endif

#ifdef VAR10
int Next_hash(int hash, int size, int p)
{
	return (hash + p) % size;
}
#endif

#ifdef VAR1
int Next_hash(int hash, int size, int p) {
	return (hash + 7 * p + 5 * p * p) % size;
}
#endif

Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))	
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d)
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0);
			i != size && !b;  j = Next_hash(j, size, ++i)) {
		if (data[j] == NULL || data[j] == DEL)
		{
			data[j] = d;
			N++;
			b = true;
		}
	}
	return b;
}
//-------------------------------
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;             //key must be varialbe, when it is const its mistaken result!!!!!!!!!!!
	if (N != 0)
		//for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = Next_hash(key, size, ++i))  эта хуйня при множ. коллизиях работать не будет
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = Next_hash(j, size, ++i))
		{
			if (j > size)
				continue;
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
		}
	return t;
}


//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " record # " << i;
		if ((this->data)[i] == NULL)
			std::cout << "  - " << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  -" << std::endl;
			else
				f((this->data)[i]);
	}
}