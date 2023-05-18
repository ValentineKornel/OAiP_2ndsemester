#include "Header.h"

void push(struct Stack*& MyStack) {
	char chislo[9];
	cout << "Input the elements into the stask (type 'q' to finish input): " << endl;
	while (cin >> chislo && *chislo != 'q') {
		Stack* data = new Stack;
		data->data = atof(chislo);
		data->next = MyStack->head;
		MyStack->head = data;
	}
	cout << "The data is pushed!\n";
	return;
}

float pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "The stack is empty" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		float a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}


void clearStack(Stack*& MyStack) {
	if (MyStack->head == 0) { cout << "The stack is alreatdy empty!\n"; }
	else {
		while (MyStack->head) {
			Stack* delStack = MyStack->head;
			MyStack->head = MyStack->head->next;
			delete delStack;
		}
	}
}


void showStack(Stack*& MyStack) {
	Stack* data = MyStack->head;
	if (MyStack->head == 0) { cout << "The stack is empty:\n"; }
	else { cout << "Here is your stack: \n"; }
	while (data) {
		cout << data->data << "\n";
		data = data->next;
	}
}

void search(Stack* MySt) {
	int counter = 0;
	Stack* data = MySt->head;
	if (MySt->head == 0) { cout << "The stask is empty\n"; }
	else {
		float down, up;
		cout << "Enter the borders of the lapse to search" << endl;
		cout << "The down one: ";
		cin >> down;
		cout << "And the upper one: ";
		cin >> up;
		while (data) {
			if (data->data > down && data->data < up) {
				cout << data->data << "\n";
				counter++;
			}
			data = data->next;
		}
	}
	if (counter == 0) cout << "There is no any data in the given laps" << endl;
}


void WriteInFile(Stack* myStk) {
	ofstream file1("data.txt");
	Stack* st = myStk->head;
	while (st)
	{
		float data = st->data;
		if (data != 0)
		{
			file1 << data << endl;
			st = st->next;
		}
	}
	file1.close();
	cout << "The stack has been written into the file data.txt\n";
}

void ReadFromFile(Stack* MySt, string fileName) {
	clearStack(MySt);
	float indicate;
	ifstream FILE;
	FILE.open(fileName, ofstream::app);
	if (!(FILE >> indicate)) { cout << "The file is empty\n"; }
	else {
		while (indicate) {
			Stack* data = new Stack;
			data->data = indicate;
			data->next = MySt->head;
			MySt->head = data;
			if (!(FILE >> indicate)) { break; }
		}
		cout << "Data had been read from the file\n";
	}
	FILE.close();
}
