#include "heap.h"
#include <iostream>
using namespace std;
using namespace heap;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	Heap* ph2 = &h2;
	for (;;)
	{
		std::system("cls");
		h1.scan(0);
		cout << "1 - to add element" << endl;
		cout << "2 - delet biggest element" << endl;
		cout << "3 - delete smallest element" << endl;
		cout << "4 - to delete neede element" << endl;
		cout << "5 - to merge first and second heaps into the third one" << endl;
		cout << "6 - to switch heap" << endl;
		cout << "0 to exit" << endl;
		cout << "Your choice? ";
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: {	AAA* a = new AAA;
			cout << "Введите ключ:" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 2:   h1.extractMax();
			break;
		case 3:   h1.extractMin();
			break;
		case 4:
			int i;
			cout << "Введите i:\n";
			cin >> i;
			h1.extractI(i);
			break;
		case 5:
		{
			int j = 1;
			cout << "Введите вторую кучу:\n";
			while (j > 0)
			{
				AAA* b = new AAA;
				cout << "Введите ключ:" << endl; 	cin >> j;
				if (j > 0)
				{
					b->x = j;
					h2.insert(b);
				}
			}
			h1.unionHeap(ph2);
			break;
		}
		default: break;
		}
		std::system("pause");
	} return 0;
}