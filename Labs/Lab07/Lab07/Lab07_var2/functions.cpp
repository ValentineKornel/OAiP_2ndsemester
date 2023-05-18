#include "Header.h"

void push(struct Stack*& MyStack) {
	char chislo[9];
	cout << "Input the elements into the stask (type 'q' to finish input): " << endl;
	while (cin >> chislo && *chislo != 'q') {
		Stack* data = new Stack;
		data->date = atof(chislo);
		data->next = MyStack->head;
		MyStack->head = data;
	}
	cout << "The data is pushed!\n";
	return;
}

float pop(Stack* myStk)   //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "The stack is empty" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}
	else
	{
		Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
		float a = myStk->head->date;   //������ ����� �� ���� data � ���������� a 
		myStk->head = myStk->head->next; //������� �������
		delete e;                        //�������� ��������� ����������
		return a;                        //������� �������� ���������� ��������
	}
}





void clearStack(Stack*& MyStack) {
	if (!MyStack->head) { cout << "The stack is alreatdy empty!\n"; }
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
	if (!MyStack->head) { cout << "The stack is empty:\n"; }
	else { cout << "Here is your stack: \n"; }
	while (data) {
		cout << data->date << "\n";
		data = data->next;
	}
}


void WriteInFile(Stack* myStk) {
	ofstream file1("data.txt");
	Stack* e = myStk->head;
	while (e)
	{
		float data = e->date;
		if (data != 0)
		{
			file1 << data << endl;
			e = e->next;
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
			data->date = indicate;
			data->next = MySt->head;
			MySt->head = data;
			if (!(FILE >> indicate)) { break; }
		}
		cout << "Data had been read from the file\n";
	}
	FILE.close();
}

void search(Stack* MySt) {
	int counter = 0;
	Stack* data = MySt->head;
	if (!MySt->head) { cout << "The stask is empty\n"; }
	else {
		while (data) {
			if (data->date == data->next->date) {
				cout << data->date << "\n";
				counter++;
			}
			data = data->next;
			if (data->next == NULL)
				break;
		}
	}
	if (counter == 0) cout << "There is no any needed element" << endl;
}