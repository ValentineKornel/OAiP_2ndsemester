#include "Header.h"

void menu() {
	cout << "Enter" << endl;
	cout << "1 - to input element into a stack" << endl;
	cout << "2 - to pop the element" << endl;
	cout << "3 - to display the stack" << endl;
	cout << "4 - to clear the stack" << endl;
	cout << "5 - to check if there any number from given lapse" << endl;
	cout << "6 - to write the stack into the file" << endl;
	cout << "7 - to read the stack from the file" << endl;
	cout << "0 - to exit" << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number, choise;
	Stack* MyStack = new Stack;

	MyStack->head = nullptr;

	while (true) {
		menu();
		cin >> choise;
		switch (choise) {
		case 0: return 0;
		case 1:
		{
			system("cls");
			cout << "Enter the elsements of the stask:" << endl;
			push(MyStack);
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			float temp = pop(MyStack);
			if (temp != -1)
				cout << "Gained element is " << temp << endl;

			break;
		}
		case 3:
		{
			system("cls");
			cout << "Stack elements:" << endl;
			showStack(MyStack);
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			clearStack(MyStack);
			cout << "The stack is cleaned\n";
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			search(MyStack);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			WriteInFile(MyStack);
			break;
		}
		case 7:
		{
			system("cls");
			ReadFromFile(MyStack, "data.txt");
			system("pause");
			system("cls");
			break;
		}
		default: {
			cout << "Incorrect input" << endl;
		}
		}
	}
}