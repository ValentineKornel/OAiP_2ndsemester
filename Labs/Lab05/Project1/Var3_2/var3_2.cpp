#include <iostream>
#include <string>
using namespace std;

/*
Ломбард. База хранимых товаров и недвижимости: анкетные данные клиента, 
наименование товара, оценочная стоимость; сумма, выданная под залог, 
дата сдачи, срок хранения. Выбор товаров по наименованию.
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
	int numb;
	float fnumb;
};

struct Notebook {
	forstruct surname;
	forstruct name;
	forstruct middlename;
	forstruct product_name;
	forstruct price;
	forstruct pledge;
	forstruct delivery_date;
	forstruct storage_time;
} products[30];


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
		cin >> products[current_size].surname.str;

		cout << "Name: ";
		cin >> products[current_size].name.str;

		cout << "Middlename: ";
		cin >> products[current_size].middlename.str;

		cin.get();
		cout << "Product name: ";
		std::cin.getline(products[current_size].product_name.str, 50);

		cout << "Price(bel rub): ";
		cin >> products[current_size].price.fnumb;

		cout << "Pledge(bel rub): ";
		cin >> products[current_size].pledge.fnumb;

		int is_correct_delivery_time = 0;
		do {
			cout << "Delivery time: ";
			cin >> products[current_size].delivery_date.numb;

			int day, month, year;
			year = products[current_size].delivery_date.numb % 10000;
			month = (products[current_size].delivery_date.numb % 1000000 - year) / 10000;
			day = products[current_size].delivery_date.numb / 1000000;

			if (year == current_y)
				is_correct_delivery_time = 2;
			if (year < current_y)
				is_correct_delivery_time = 1;
			if (is_correct_delivery_time == 2) {
				if (month > current_m)
					is_correct_delivery_time = 0;
				else if (month == current_m)
					is_correct_delivery_time = 2;
				else if (month < current_m)
					is_correct_delivery_time = 1;
				else if (month > 12)
					is_correct_delivery_time = 0;
			}
			if (is_correct_delivery_time == 2) {
				if (day > current_d)
					is_correct_delivery_time = 0;
				else if (day <= current_d)
					is_correct_delivery_time = 1;
				else if (day > 31)
					is_correct_delivery_time = 0;
			}
			if (month > 12 or day > 31)
				is_correct_delivery_time = 0;
			if (is_correct_delivery_time == 0)
				cout << "Incorrect input" << endl;
		} while (is_correct_delivery_time == 0);



		cout << "Storage time(days): ";
		cin >> products[current_size].storage_time.numb;
		current_size++;
	}
	else
		cout << "No any monre records cane be enetered" << endl;
}

void displayOneStructure(Notebook oneProduct) {
	cout << endl;
	cout << "Surname: " << oneProduct.surname.str << endl;
	cout << "Name: " << oneProduct.name.str << endl;
	cout << "Middlename: " << oneProduct.middlename.str << endl;
	cout << "Product name: " << oneProduct.product_name.str << endl;
	cout << "Price(bel rub): " << oneProduct.price.fnumb << endl;
	cout << "Pledge(bel rub): " << oneProduct.pledge.fnumb << endl;
	cout << "Delivery date: " << oneProduct.delivery_date.numb << endl;
	cout << "Srorage time(days): " << oneProduct.storage_time.numb << endl;
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
		displayOneStructure(products[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			displayOneStructure(products[i]);
			cout << endl;
		}
	}
	else
		cout << "Incorrect input";
}

void search() {
	string nedded_product;
	cout << "Enter the name of the product: ";
	cin.get();
	getline(cin, nedded_product);
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (products[i].product_name.str == nedded_product) {
			displayOneStructure(products[i]);
		}
	}
}