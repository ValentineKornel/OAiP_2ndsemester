#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;

	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	

	Stack1* myStk1 = new Stack1; //выделение памяти для стека
	myStk1->head = NULL;

	Stack2* myStk2 = new Stack2; //выделение памяти для стека
	myStk2->head = NULL;

	while (true)
	{
		cout << "Enter:" << endl;
		cout << "1 - доп 1" << endl;
		cout << "2 - доп 2" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: dop1(myStk1);
			break;
		case 2: dop2(myStk2);
			break;
		case 0: return 0;
			break;
		}
	}
	return 0;
}

void dop1(Stack1* myStk1)
{
	string a;
	short i = 0;
	cout << "Input the string with the even number of characters:\n";
	cin >> a;
	short length = a.length();

	for (i = 0; i < (length / 2); i++)
	{
		Stack1* e = new Stack1;    //выделение памяти для нового элемента
		e->letter = a[i];           //запись элемента x в поле v 
		e->next = myStk1->head;   //перенос вершины на следующий элемент 
		myStk1->head = e;         //сдвиг вершины на позицию вперед
	}

	while (myStk1->head)
	{
		cout << myStk1->head->letter << " ";
		myStk1->head = myStk1->head->next;
	}

	for (i = (length / 2); i < length; i++)
	{
		Stack1* e = new Stack1;    //выделение памяти для нового элемента
		e->letter = a[i];           //запись элемента x в поле v 
		e->next = myStk1->head;   //перенос вершины на следующий элемент 
		myStk1->head = e;         //сдвиг вершины на позицию вперед
	}

	while (myStk1->head)
	{
		cout << myStk1->head->letter << " ";
		myStk1->head = myStk1->head->next;
	}

	cout << '\n';
}

void dop2(Stack2* myStk2)
{
	ifstream file("dop2.txt");
	string str;
	short counter = 1, seqNum = 1, min = SHRT_MAX, minData;
	int* Array = new int[10];

	while (getline(file, str))
	{
		Stack2* e = new Stack2;
		e->data = str.length();
		e->data = e->data;
		if (e->data <= min)
		{
			min = e->data;
			minData = min;
			seqNum = counter;
		}
		e->next = myStk2->head;
		myStk2->head = e;
		counter++;
	}

	while (myStk2->head)
	{
		cout << myStk2->head->data << " ";
		myStk2->head = myStk2->head->next;
	}

	cout << "\nThe last shortest line number is " << seqNum << " and its length euqal " << minData << ".\n";
}
