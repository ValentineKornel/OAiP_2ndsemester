#include <iostream>
#include <string>
using namespace std;

/*В соответствии со своим вариантом разработать программу 
с использованием структуры в виде объединения, для работы 
с данными из таблицы, приведенной ниже. Реализовать 
функции ввода с клавиатуры, вывода на экран и поиска.

Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). 
Реализовать выборку по году рождения.
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
	char ch;
};

struct Notebook {
	forstruct surname;
	forstruct name;
	forstruct middlename;
	forstruct birthdate;
	forstruct adress;
	forstruct male;
} citizens[30];


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
		cin >> citizens[current_size].surname.str;

		cout << "Name: ";
		cin >> citizens[current_size].name.str;

		cout << "Middlename: ";
		cin >> citizens[current_size].middlename.str;
		
		
		int is_correct_delivery_time = 0;
		do {
			cout << "Birthdate: ";
			cin >> citizens[current_size].birthdate.numb;

			int day, month, year;
			year = citizens[current_size].birthdate.numb % 10000;
			month = (citizens[current_size].birthdate.numb % 1000000 - year) / 10000;
			day = citizens[current_size].birthdate.numb / 1000000;

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


		cin.get();
		cout << "Adress: ";
		std::cin.getline(citizens[current_size].adress.str, 50);

		

		cout << "Male: ";
		cin >> citizens[current_size].male.ch;
		current_size++;
	}
	else
		cout << "No any monre records cane be enetered" << endl;
}

void displayOneStructure(Notebook oneCitizen) {
	cout << endl;
	cout << "Surname: " << oneCitizen.surname.str << endl;
	cout << "Name: " << oneCitizen.name.str << endl;
	cout << "Middlename: " << oneCitizen.middlename.str << endl;
	cout << "Birthdate: " << oneCitizen.birthdate.numb << endl;
	cout << "Adress: " << oneCitizen.adress.str << endl;
	cout << "Male: " << oneCitizen.male.ch << endl;
}

void display() {
	for (int i = 0; i < current_size; i++) {
		displayOneStructure(citizens[i]);
	}
}

void search() {
	int nedded_birth_year;
	cout << "Enter the birth year: ";
	cin >> nedded_birth_year;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		int temp_y = citizens[i].birthdate.numb;
		if (temp_y % 10000 == nedded_birth_year) {
			displayOneStructure(citizens[i]);
		}
	}
}

