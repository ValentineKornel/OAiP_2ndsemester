#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;

struct List {
	int number;
	List* next;
};


void insert(List*&, int);
int del(List*&, int);
int isEmpty(List*);
void printList(List*);
void menu();
void sumPositiveDivisibleFive(List*);
void writeToFile(List*& p);
void readFromFile(List*& p);
void search(List*);

void main() {

	List* first = NULL;
	int choise;
	int value;
	menu();
	cout << "What's on? ";
	cin >> choise;
	while (choise != 8) {
		switch (choise)
		{
		case 1: {
			cout << "Enter the number" << endl;
			string temp;
			cin >> temp;
			char temp1[10];
			bool flag = false;
			for (int i = 0; i < temp.length(); i++) {
				if (temp[i] == '.')
					flag = true;
			}
			for (int i = 0; i < temp.length(); i++) {
				temp1[i] = temp[i];
			}
			if (flag == false)
				value = atoi(temp1);
			else {
				cout << "Incorrect input" << endl;
				break;
			}
			insert(first, value);
			break;
		}
		case 2: {
			printList(first);
			break;
		}
		case 3: {
			if (!isEmpty(first)) {
				cout << "Enter the number to delete" << endl;
				cin >> value;
				if (del(first, value)) {
					cout << "Number " << value << " is deleted" << endl;
					printList(first);
				}
				else
					cout << "Number is not founded" << endl;
			}
			else
				cout << "The list is empty" << endl;
			break;
		}
		case 4: {
			sumPositiveDivisibleFive(first);
			break;
		}
		case 5: {
			writeToFile(first);
			break;
		}
		case 6: {
			readFromFile(first);
			break;
		}
		case 7: {
			search(first);
			break;
		}
		default: {
			cout << "Incorrect input" << endl;
			menu();

			cin >> choise;
			break;
		}
		}
		cout << "What's on? ";
		cin >> choise;
	}
}

void menu() {
	cout << "Enter" << endl;
	cout << "1 - to input new number" << endl;
	cout << "2 - to display the list" << endl;
	cout << "3 - to delte the number" << endl;
	cout << "4 - to count the sum of positive numbers devisible to 5" << endl;
	cout << "5 - to write the list into the fiel" << endl;
	cout << "6 - to read the information from the file" << endl;
	cout << "7 - to search the element" << endl;
	cout << "8 - to exit" << endl;
}

void insert(List*& p, int value) {
	List* newP = new List;
	if (newP != NULL) {
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Insert operation wasn't done" << endl;
}

int del(List*& p, int value) {
	List* previous, * current, * temp;
	if (value == p->number) {
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else {
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value) {
			previous = current;
			current = current->next;
		}
		if (current != NULL) {
			temp = current;
			previous->next = current->next;
			free(temp);
			return value;
		}
	}
	return 0;
}

int isEmpty(List* p) {
	return p == NULL;
}

void printList(List* p) {
	if (p == NULL)
		cout << "The list is empty" << endl;
	else {
		cout << "The list: " << endl;
		while (p != NULL) {
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void sumPositiveDivisibleFive(List* p) {
	int sm = 0;
	if (p == NULL)
		cout << "The list is empty";
	else {
		while (p != NULL) {
			if (p->number > 0 and (p->number % 5 == 0))
				sm = sm + (p->number);
			p = p->next;
		}
		if (sm == 0)
			cout << "There is no any positive element divisible to 5" << endl;
		else
			cout << "Summ = " << sm << endl;
	}
}

void writeToFile(List*& p) {
	List* temp = p;
	ofstream file1("myList.txt");
	if (file1.fail()) {
		cout << "Error opening the file";
		exit(1);
	}
	while (temp) {
		int nn = temp->number;
		file1 << nn << endl;
		temp = temp->next;
	}
	file1.close();
	cout << "Information is written into the file" << endl;
}

void readFromFile(List*& p) {
	char buf[10];

	ifstream file1("myList.txt");
	if (file1.fail()) {
		cout << "Error opening the file";
		exit(1);
	}
	while (!file1.eof()) {
		file1.getline(buf, 10);
		if (strlen(buf))
			insert(p, atoi(buf));
		cout << "-->" << buf;
	}
	cout << "-->NULL" << endl;
	file1.close();
}

void search(List* p) {
	bool isFnd = false;
	int element;
	int counter = 0;
	cout << "Enter the element: ";
	cin >> element;
	List* fnd = p;
	while (fnd) {
		if (fnd->number == element) {
			isFnd = true;
			cout << "Element is founded, its sequential number is " << counter + 1 << endl;
			break;
		}
		fnd = fnd->next;
		counter++;
	}
	if (!isFnd)
		cout << "Element isn't founded" << endl;
}