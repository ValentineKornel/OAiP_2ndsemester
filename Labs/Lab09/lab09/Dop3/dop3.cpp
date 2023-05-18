#include <iostream>
using namespace std;

struct numbers
{
	char num[50];       
	numbers* next;
};

char* circle(numbers*, int, int);     //сделать блок схему
numbers* zapoln(int);

int main()
{
	int kolv;
	int k;
	cout << "Input number of members: ";
	cin >> kolv;
	numbers* g = zapoln(kolv);
	cout << "Input k: ";
	cin >> k;
	cout << "The last one leaved is: " << circle(g, k, kolv) << endl;
	return 0;
}

numbers* zapoln(int kolv)
{
	numbers* first = nullptr;
	numbers* Head;
	numbers* nowiy;
	char a[50];
	if (kolv > 0)
	{
		nowiy = new numbers;
		Head = nowiy;
	}
	else
	{
		return first;
	}
	for (int i = 0; i < kolv; i++)
	{
		cout << "Input a memer: ";
		cin.get();
		cin.getline(a, 50);
		for (int y = 0; y < 50; y++)
		{
			if (a[y] == '\0')
			{
				nowiy->num[y] = '\0';
				break;
			}
			nowiy->num[y] = a[y];
		}
		first = nowiy;
		nowiy = new numbers;
		first->next = nowiy;
	}
	first->next = Head;
	return Head;
}

char* circle(numbers* g, int ocher, int kolv)
{
	int u = 0;
	numbers* buff;
	numbers* h = g;
	while (h->next != h)
	{
		for (int i = 0; i < ocher - 2; i++)
		{
			h = h->next;
		}
		buff = h->next;
		cout << "Deleted " << buff->num << endl;
		h->next = h->next->next;
		h = h->next;
		delete buff;
	}
	return h->num;
}