#include <iostream>
#include <string>
using namespace std;

/*
Клиенты банка. Ф.И.О., тип счета (срочный, льготный и т. д.), 
номер счета, сумма на счете, дата последнего изменения. Выбор по 
диапазону суммы (<100,  >100). Дату реализовать с помощью битового 
поля, тип счета  с помощью перечисления.
*/

const int SIZE = 30;
int current_size = 0;
int current_y = 2023;
int current_m = 3;
int current_d = 14;

enum bang_account_type {
	urgent = 1,
	grace,
	budget,
	deposit
};

struct EditDate {
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 11;
};

struct Clients {
	string surname;
	string name;
	string middlename;
	bang_account_type type;
	string bank_account_number;
	float amount_of_money_in_bank_account;
	EditDate date;
} clients[SIZE];
struct Clients empty_client;

void addNew();
void displayOneStructure(Clients oneClient);
void display();
void deleteRecord();
void search();

void main()
{

	short choose;
	do
	{
		cout << "\nEnter:\n1 - to enter new record;\n2 - to display information;\n3 - to delete the rocord;\n4 - to search\n5 - to exit.\n";
		cin >> choose;
		switch (choose) {
		case 1: addNew(); break;
		case 2: display(); break;
		case 3: deleteRecord(); break;
		case 4: search(); break;
		}
	} while (choose != 5);

}

void addNew() {
	cout << "Information Entry" << endl;
	cout << "Record number" << current_size + 1 << endl;

	if (current_size < SIZE) {
		cout << "Surname: ";
		cin >> clients[current_size].surname;

		cout << "Name: ";
		cin >> clients[current_size].name;

		cout << "Middlename: ";
		cin >> clients[current_size].middlename;

		cout << "Bank account type(1 - urgent, 2 - grace, 3 - budget, 4 - deposit): ";
		int fac;
		do {
			cin >> fac;
			if (fac < 1 or fac > 4)
				cout << "Incoret input";
		} while (fac < 1 or fac > 4);
		if (fac == 1)
			clients[current_size].type = urgent;
		if (fac == 2)
			clients[current_size].type = grace;
		if (fac == 3)
			clients[current_size].type = budget;
		if (fac == 4)
			clients[current_size].type = deposit;

		cout << "Bank account number: ";
		cin >> clients[current_size].bank_account_number;

		cout << "Amount of money in bank account: ";
		cin >> clients[current_size].amount_of_money_in_bank_account;

		int is_correct_last_edit_time = 0;
		do {
			int day;
			int month;
			int year;
			cout << "Last edit time: " << endl;

			cout << "Day: ";
			cin >> day;
			clients[current_size].date.day = day;
			cout << "Month: ";
			cin >> month;
			clients[current_size].date.month = month;
			cout << "Year: ";
			cin >> year;
			clients[current_size].date.year = year;

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


void displayOneStructure(Clients oneClient) {
	cout << endl;
	cout << "Surname: " << oneClient.surname << endl;
	cout << "Name: " << oneClient.name << endl;
	cout << "Middlename: " << oneClient.middlename << endl;
	cout << "Bank account type: ";
	if (oneClient.type == urgent)
		cout << "urgent" << endl;
	if (oneClient.type == grace)
		cout << "grace" << endl;
	if (oneClient.type == budget)
		cout << "budget" << endl;
	if (oneClient.type == deposit)
		cout << "deposit" << endl;
	cout << "Bank account number: " << oneClient.bank_account_number << endl;
	cout << "Amount of money in bank account: " 
		<< oneClient.amount_of_money_in_bank_account;

	cout << "Last edit time: " << endl;
	cout << "Day: " << oneClient.date.day << endl;
	cout << "Month: " << oneClient.date.month << endl;
	cout << "Year: " << oneClient.date.year << endl;
	
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

void deleteRecord() {
	int rec_number;
	cout << "Enter teh number of record to delete" << endl;
	cin >> rec_number;
	if (rec_number != 0) {
		for (int de = (rec_number - 1); de < current_size - 1; de++)
			clients[de] = clients[de + 1];
		current_size -= 1;
	}
	if (rec_number == 0)
		for (int i = 0; i < SIZE; i++)
			clients[i] = empty_client;
}

void search() {
	int nedded_amount;
	cout << "Accounts with amount of money to show (1 - '<100', 2 - '>100': ";
	cin >> nedded_amount;
	if (nedded_amount == 1) {
		for (int i = 0; i < current_size; i++) {
			if (clients[i].amount_of_money_in_bank_account < 100)
				displayOneStructure(clients[i]);
			cout << endl;

		}
	}
	else if (nedded_amount == 2) {
		for (int i = 0; i < current_size; i++) {
			if (clients[i].amount_of_money_in_bank_account > 100)
				displayOneStructure(clients[i]);
			cout << endl;
		}
	}
	else
		cout << "Incorrect input";
}