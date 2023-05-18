#include "MyQueue.h"

extern int qsize;

void insertToQueue(qmanager* My_Queue)
{
	float n;
	cin >> n;

	Queue* p = new Queue;
	p->data = n;

	if (My_Queue->head == NULL) {
		My_Queue->head = My_Queue->tail = p;
		p->next = NULL;
	}
	else {
		p->next = My_Queue->tail;
		My_Queue->tail = p;
	}
}

void showQueue(qmanager* My_Queue) {
	Queue* p = new Queue;
	p = My_Queue->tail;
	int count = 0;
	while (p) {
		cout << p->data << " ";
		p = p->next;
		count++;
	}
	cout << "---- size = " << count << endl;
	qsize = count;
}
void deletion(qmanager* My_Queue) {
	Queue* p = new Queue;
	Queue* previous = new Queue;
	p = My_Queue->tail;
	previous = NULL;
	while (p->next && p->next->next) {
		p = p->next;
	}
	if (My_Queue->head == My_Queue->tail) {
		My_Queue->tail = My_Queue->head = 0;
		delete(p);
	}
	else {
		My_Queue->head = p;
		previous = p;
		p = p->next;
		previous->next = NULL;
		delete(p);
	}
}

void insertToMQueue(qmanager* My_Queue, float element)
{
	float n = element;

	Queue* p = new Queue;
	p->data = n;

	if (My_Queue->head == NULL) {
		My_Queue->head = My_Queue->tail = p;
		p->next = NULL;
	}
	else {
		p->next = My_Queue->tail;
		My_Queue->tail = p;
	}
}

void task(qmanager* My_Queue) {

	qmanager* Min_Queue = new qmanager;
	Min_Queue->head = NULL;
	Min_Queue->tail = NULL;

	qmanager* Max_Queue = new qmanager;
	Max_Queue->head = NULL;
	Max_Queue->tail = NULL;

	Queue* p = new Queue;
	float min;
	float max;
	float prevmax;
	float prevmin;
	int s = qsize;
	p = My_Queue->tail;
	if (p == NULL) {
		cout << "The queue is empty\n";
		return;
	}
	else {

		// adding first min element
		min = p->data;
		while (p != NULL) {
			if (p->data <= min) {
				min = p->data;
			}
			p = p->next;
		}
		insertToMQueue(Min_Queue, min);
		// adding the rest elements
		prevmin = min;
		int iter;
		if (s % 2 == 0)
			iter = s / 2;
		else
			iter = s / 2 + 1;
		for (int i = 1; i < iter; i++) {
			p = My_Queue->tail;
			min = 999;
			while (p != NULL) {
				if (p->data <= min && p->data > prevmin) {
					min = p->data;
				}
				p = p->next;
			}
			prevmin = min;
			insertToMQueue(Min_Queue, min);
		}
		showQueue(Min_Queue);



		// adding first max element;
		p = My_Queue->tail;
		max = p->data;
		while (p != NULL) {
			if (p->data >= max) {
				max = p->data;
			}
			p = p->next;
		}
		insertToMQueue(Max_Queue, max);
		// adding the rest elements
		prevmax = max;
		for (int i = 1; i < s / 2; i++) {
			p = My_Queue->tail;
			max = -999;
			while (p != NULL) {
				if (p->data >= max && p->data < prevmax) {
					max = p->data;
				}
				p = p->next;
			}
			prevmax = max;
			insertToMQueue(Max_Queue, max);
		}
		showQueue(Max_Queue);
	}

	for (int i = 0; i < s; i++) {
		deletion(My_Queue);
	}
	cout << "Done\n\n";
	system("PAUSE");

}