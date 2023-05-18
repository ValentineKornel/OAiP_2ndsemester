#include<iostream>
using namespace std;
struct Item
{
	float data;
	Item* next;
};
Item* head, * tail;

bool isNull(void)    //check is empty
{
	return (head == NULL);
}
void deletFirst()   //pop the first element
{
	if (isNull())
		cout << "The queue is empty" << endl;
	else
	{
		Item* p = head;
		head = head->next; 
		delete p;
	}
}

void insertToQueue(float x)  //adding a new element
{
	Item* p = new Item;
	p->data = x;
	p->next = NULL;
	if (isNull())
		head = tail = p;
	else
	{
		tail->next = p;
		tail = p;
	}
	system("PAUSE");
	system("CLS");
}
void sortmax()
{
	Item* p = new Item;
	p = head;
	int count = 1, i = 1;
	float max = head->data;
	while (p != NULL)
	{
		if (max < p->data)
		{
			max = p->data;
			count = i;
		}
		i++;
		p = p->next;
	}
	tail->next = head;
	while ((count - 1))
	{
		head = head->next;
		tail = tail->next;
		count--;
	}
	tail->next = NULL;
}
void printQueue()             //display the queue
{
	Item* p = new Item;
	if (isNull())
		cout << "The queue is empty" << endl;
	else
	{
		cout << "The queue = ";
		p = head;
		while (!isNull())
		{
			if (p != NULL)
			{
				cout << p->data << " "; cout << "-> ";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

void clrQueue()           //queue cleaning
{
	while (!isNull()) deletFirst();
}
int main()
{
	int i = 1, choice = 1; head = NULL;  tail = NULL; float z;
	while (choice != 0)
	{
		printQueue();
		cout << "Enter" << endl;
		cout << "1 - to add an element" << endl;
		cout << "2 - to pop the head element" << endl;
		cout << "3 - circle shift to the biggest elemetn" << endl;
		cout << "4 - to clean the queue" << endl;
		cout << "0 - exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Input the element: "; cin >> z;
			insertToQueue(z); break;
		case 2: deletFirst();
			cout << "The head element has just been popped" << endl;
			system("PAUSE");
			system("CLS"); 
			break;
		case 3: sortmax();  break;
		case 4: clrQueue();    break;
		}
	}
	return 0;
}