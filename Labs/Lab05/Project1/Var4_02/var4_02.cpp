#include <iostream>
#include <string>
using namespace std;

/*
Клиенты банка. Ф.И.О., тип счета, номер счета, 
сумма на счете, дата последнего изменения. 
Выбор по номеру счета.
*/


const int SIZE = 30;
int current_size = 0;
int current_y = 2023;
int current_m = 3;
int current_d = 14;

void addNew();
void display();
void search();


union forstruct {
	char str[50];
	long int numb;
	long float fnumb;
};

struct Notebook {
	forstruct surname;
	forstruct name;
	forstruct middlename;
	forstruct account_type;
	forstruct account_number;
	forstruct amount_of_money_in_account;
	forstruct last_edit_date;
} clients[30];


int main() {
	int choose;
	do
	{
		cout << "\nEnter:\n1 - to enter new record;\n2 - to dsiplay information;\n3 - to search;\n4 - to exit.\n";
		cin >> choose;
		switch (choose) {
		case 1: addNew(); break;
		case 2: display(); break;
		case 3: search(); break;
		}
	} while (choose != 4);

}

void addNew() {
	cout << "Information Entrance" << endl;

	cout << "Record number " << current_size + 1 << endl;
	if (current_size < SIZE) {

		cout << "Surname: ";
		cin >> clients[current_size].surname.str;

		cout << "Name: ";
		cin >> clients[current_size].name.str;

		cout << "Middlename: ";
		cin >> clients[current_size].middlename.str;

		cin.get();
		cout << "Type of bank account: ";
		std::cin.getline(clients[current_size].account_type.str, 50);


		cout << "Account number: ";
		cin >> clients[current_size].account_number.str;

		cout << "Amount of money in bank account: ";
		cin >> clients[current_size].amount_of_money_in_account.fnumb;

		int is_correct_last_edit_time = 0;
		do {
			cout << "Last edit date: ";
			cin >> clients[current_size].last_edit_date.numb;

			int day, month, year;
			year = clients[current_size].last_edit_date.numb % 10000;
			month = (clients[current_size].last_edit_date.numb % 1000000 - year) / 10000;
			day = clients[current_size].last_edit_date.numb / 1000000;

			if (year == current_y)
				is_correct_last_edit_time = 2;
			if (year < current_y)
				is_correct_last_edit_time = 1;
			if (is_correct_last_edit_time == 2) {
				if (month > current_m)
					is_correct_last_edit_time = 0;
				else if (month == current_m)
					is_correct_last_edit_time = 2;
				else if (month < current_m)
					is_correct_last_edit_time = 1;
				else if (month > 12)
					is_correct_last_edit_time = 0;
			}
			if (is_correct_last_edit_time == 2) {
				if (day > current_d)
					is_correct_last_edit_time = 0;
				else if (day <= current_d)
					is_correct_last_edit_time = 1;
				else if (day > 31)
					is_correct_last_edit_time = 0;
			}
			if (month > 12 or day > 31)
				is_correct_last_edit_time = 0;
			if (is_correct_last_edit_time == 0)
				cout << "Incorrect input" << endl;
		} while (is_correct_last_edit_time == 0);

		current_size++;
	}
	else
		cout << "No any monre records cane be enetered" << endl;
}

void displayOneStructure(Notebook oneClient) {
	cout << endl;
	cout << "Surname: " << oneClient.surname.str << endl;
	cout << "Name: " << oneClient.name.str << endl;
	cout << "Middlename: " << oneClient.surname.str << endl;
	cout << "Bank account type: " << oneClient.account_type.str << endl;
	cout << "Bank account number: " << oneClient.account_number.str << endl;
	cout << "Amount of money in bank account: " << oneClient.amount_of_money_in_account.fnumb << endl;
	cout << "Last edit date: " << oneClient.last_edit_date.numb << endl;

}


void display() {
	int ch, num;
	cout << "1 - to display one record" << endl;
	cout << "2 - to display all records" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter the number of record to display" << endl;
		cin >> num;
		if (num > current_size or num < 1)
			cout << "Incorrect input";
		cout << endl;
		displayOneStructure(clients[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			displayOneStructure(clients[i]);
			cout << endl;
		}
	}
	else
		cout << "Incorrect input";
}

void search() {
	string nedded_account_number;
	cout << "Enter bank account number to search: ";
	cin >> nedded_account_number;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (clients[i].account_number.str == nedded_account_number) {
			displayOneStructure(clients[i]);
		}
	}
}