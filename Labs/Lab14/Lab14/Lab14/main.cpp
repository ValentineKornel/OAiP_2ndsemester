#include "Hash.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>
using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;   return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " key " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	cout << "hash for key 20 is " << HashFunction(20, 16, 0) << endl;
	cout << "hash for key 52 is " << HashFunction(52, 16, 0) << endl;
	AAA a1(1, (char*)"one"), a2(2, (char*)"two"), a3(4, (char*)"three"), a4(2, (char*)"fo");
	int siz = 10, choice, k;
	cout << "Enter hash-table size: " << endl; 	cin >> siz;
	vector<int> keys;
	clock_t start, end;
	double searching_time;
	Object H = create(siz, key);
	for (;;)
	{
		cout << "1 - display hash-table" << endl;
		cout << "2 - add new element" << endl;
		cout << "3 - delete element" << endl;
		cout << "4 - search element" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choise?" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);  break;
		case 2: { AAA* a = new AAA;
			char* str = new char[20];
			bool is_correct = false;
			do {
				cout << "Enter key" << endl;	cin >> k;
				a->key = k;
				if (std::count(keys.begin(), keys.end(), k) == 0 and k > -1)
				{
					keys.push_back(k);
					is_correct = true;
				}
				else cout << "Incorrect input" << endl;
			} while (!is_correct);
			cout << "Input line" << endl; 
			cin.get();
			cin.getline(str, 20);
			a->mas = str;
			if (H.N == H.size)
				cout << "Table is full" << endl;
			else
				H.insert(a);
		} break;
		case 3: {  cout << "eneter key to delete" << endl;
			cin >> k;
			keys.erase(std::find(keys.begin(), keys.end(), k));
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "eneter key to search" << endl;
			cin >> k;
			start = clock();
			if (H.search(k) == NULL)
				cout << "element wasn't founded" << endl;
			else
				AAA_print(H.search(k));
			end = clock();
			searching_time = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "searching time: " << searching_time << endl;
		}  break;
		}
	}
	return 0;
}