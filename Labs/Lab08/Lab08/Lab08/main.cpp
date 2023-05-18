#include "MyQueue.h"

using namespace std;

int qsize = 0;

int main()
{
	setlocale(LC_ALL, "Rus");

	qmanager* My_Queue = new qmanager;
	My_Queue->head = NULL;
	My_Queue->tail = NULL;


	int coise;
	do {
		cout << "Enter what to do\n";
		cout << "1 - to ener elements\n";
		cout << "2 - to delete the element\n";
		cout << "3 - to clear the queue\n";
		cout << "4 - variant task\n";
		cout << "0 - to exit\n";
		showQueue(My_Queue);
		cout << "------------------\n";
		cin >> coise;
		system("CLS");
		switch (coise) {
		case 1: {
			int amount_of_elements;
			cout << "Enter the size of queue: ";
			cin >> amount_of_elements;
			for (int i = 0; i < amount_of_elements; i++) {
				insertToQueue(My_Queue);
			}
			system("CLS");
			break;
		}
		case 2: {
			deletion(My_Queue); break;
		}
		case 3: {
			for (int i = 0; i < qsize; i++) {
				deletion(My_Queue);
			}
		}
		case 4: task(My_Queue);
			system("CLS");
			break;
		}
	} while (coise != 0);
}