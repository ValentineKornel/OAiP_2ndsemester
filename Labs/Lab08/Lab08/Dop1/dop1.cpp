/* 1 задание из списка */


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
		cout << "Head element = " << p->data << endl;
		head = head->next;
		delete p;
	}
}
void getFromHead()  //get the first element
{
	if (isNull())
		cout << "The queue is empty" << endl;
	else
		cout << "Head element = " << head->data << endl;
	system("PAUSE");
	system("CLS");
}

void getFromTail()  //get the last element
{
	if (isNull())
		cout << "the queue is empty" << endl;
	else
		cout << "Tail element = " << tail->data << endl;
	system("PAUSE");
	system("CLS");
}

void insertToQueue(float x)  // adding the element
{
	Item* p = new Item;      //new pointer
	p->data = x;
	p->next = NULL;
	Item* v = new Item;      //pointer for new number
	Item* p1 = new Item;
	Item* p2 = new Item;
	int i = 0;               // flag
	if (isNull())
		head = tail = p;
	else
	{
		p2 = head; p1 = head;
		while (p1 != NULL)  //until the queue is empty
		{
			if (i == 1)
			{
				if (x <= p1->data)  //less number then in the queue one 
				{
					v->data = x;
					v->next = p1;
					p2->next = v;
					return;
				}
				p2 = p2->next;      // next number
			}
			else
			{
				if (x <= p1->data)
				{
					v->data = x;
					v->next = p1;
					head = v;
					return;
				}
			}
			p1 = p1->next;
			i = 1;
		}
		if (p1 == NULL)
		{
			tail->next = p;
			tail = p;
		}
	}
	system("PAUSE");
	system("CLS");
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
				cout << p->data << " "; cout << "->";
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

void clrQueue()           //the queue cleaning
{
	while (!isNull()) deletFirst();
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 1, choice = 1; head = NULL;  tail = NULL; float z;
	while (choice != 0)
	{
		printQueue();
		cout << "Enter" << endl;
		cout << "1 - to add an element" << endl;
		cout << "2 - to get the head element" << endl;
		cout << "3 - to get the tail element" << endl;
		cout << "4 - to pop the head element" << endl;
		cout << "5 - to clean the queue" << endl;
		cout << "0 - exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Input the element:  "; cin >> z;
			insertToQueue(z);  break;
		case 2: getFromHead(); break;
		case 3: getFromTail(); break;
		case 4: deletFirst();
			cout << "The head element has just been popped" << endl;
			system("PAUSE");
			system("CLS");
			break;
		case 5: clrQueue();    break;
		}
	}
	return 0;
}
