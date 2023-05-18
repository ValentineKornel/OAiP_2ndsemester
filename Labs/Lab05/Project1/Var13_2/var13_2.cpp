#include <iostream>
#include <string>
using namespace std;

/*
√осударство. Ќаименование, столица, численность населени€, площадь, 
фамили€ президента. ¬ыбор государства по названию.
*/


const int SIZE = 30;
int current_size = 0;

void addNew();
void display();
void search();


union forstruct {
	char str[50];
	long int numb;
	long float fnumb;
};

struct Notebook {
	forstruct name;
	forstruct capital;
	forstruct surname;
	forstruct population;
	forstruct area;
} governments[30];


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

		cin.get();
		cout << "Name of government: ";
		std::cin.getline(governments[current_size].name.str, 50);

		cout << "Capital: ";
		cin >> governments[current_size].capital.str;

		cout << "Population: ";
		cin >> governments[current_size].population.fnumb;

		cout << "Area (in thouthands sq km): ";
		cin >> governments[current_size].area.fnumb;

		cout << "President surname: ";
		cin >> governments[current_size].surname.str;

		current_size++;
	}
	else
		cout << "No any monre records cane be enetered" << endl;
}

void displayOneStructure(Notebook oneProduct) {
	cout << endl;
	cout << "Name of Government: " << oneProduct.name.str << endl;
	cout << "Capital: " << oneProduct.capital.str << endl;
	cout << "Population: " << oneProduct.population.fnumb << endl;
	cout << "Area (in thouthands sq km): " << oneProduct.area.fnumb << endl;
	cout << "President surname: " << oneProduct.surname.str << endl;

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
		displayOneStructure(governments[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			displayOneStructure(governments[i]);
			cout << endl;
		}
	}
	else
		cout << "Incorrect input";
}

void search() {
	string nedded_government_name;
	cout << "Enter the name of the government to search: ";
	cin.get();
	getline(cin, nedded_government_name);
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (governments[i].name.str == nedded_government_name) {
			displayOneStructure(governments[i]);
		}
	}
}