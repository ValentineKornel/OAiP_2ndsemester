#include <iostream>
#include <string>
using namespace std;

/* В соответствии со своим вариантом разработать программу с использованием 
перечислений и битовых полей для работы с данными из таблицы, приведенной ниже. 
Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов. 
Интерфейс пользователя осуществить в виде меню.

Государство. Наименование, столица, численность населения, площадь. Выбор государства 
по занимаемой площади (> заданного значения). Форму правления реализовать с помощью 
перечисления.
*/

const int SIZE = 30;
int current_size = 0;

enum Form_of_government {
	Democraty = 1,
	Tyrany,
	Kapitalistic,
	Monarhy
}forms_of_government;

struct Government {
	string name;
	string capital;
	unsigned population : 6;
	float area;
	Form_of_government form_of_gov;
} governments[SIZE];
struct Government empty_government;

void addNew();
void displayOneStructure(Government oneGovernment);
void display();
void deleteRecord();
void search();

void main()
{
	short choose;
	do
	{
		cout << "Enter:\n1 - to enter new record;\n2 - to display information;\n3 - to delete the record;\n4 - to search\n5 - to exit.\n";
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

		cout << "Govenment name: ";
		cin.get();
		getline(cin, governments[current_size].name);

		cout << "Capital: ";
		cin >> governments[current_size].capital;

		cout << "Population: ";
		int temp; 
		cin >> temp;
		governments[current_size].population = temp;

		cout << "Area (in thouthands sq km): ";
		cin >> governments[current_size].area;

		cout << "Form of government(1 - Democraty, 2 - Tyrany, 3- Kapitalistic, 4 - Monarhy): ";
		int form;
		do {
			cin >> form;
			if (form < 1 or form > 4)
				cout << "Incorrect Input";
		} while (form < 1 or form > 4);
		if (form == 1)
			governments[current_size].form_of_gov = Democraty;
		if (form == 2)
			governments[current_size].form_of_gov = Tyrany;
		if (form == 3)
			governments[current_size].form_of_gov = Kapitalistic;
		if (form == 4)  
			governments[current_size].form_of_gov = Monarhy;

		current_size++;
}


void displayOneStructure(Government oneGovernment){
	cout << "Government name: " << oneGovernment.name << endl;
	cout << "Capital: " << oneGovernment.capital << endl;
	cout << "Population: " << oneGovernment.population << endl;
	cout << "Area (in thouthands sq km): " << oneGovernment.area << endl;
	cout << "Form of fovernment: ";
	if (oneGovernment.form_of_gov == Democraty)
		cout << "Democraty" << endl;
	if (oneGovernment.form_of_gov == Tyrany)
		cout << "Tyrany" << endl;
	if (oneGovernment.form_of_gov == Kapitalistic)
		cout << "Kapitalistic" << endl;
	if (oneGovernment.form_of_gov == Monarhy)
		cout << "Monarhy" << endl;
}

void display() {
	for (int i = 0; i < current_size; i++) {
		displayOneStructure(governments[i]);
		cout << endl;
	}
}

void deleteRecord() {
	int rec_number;
	cout << "Enter teh number of record to delete" << endl;
	cin >> rec_number;
	if (rec_number != 0) {
		for (int de = (rec_number - 1); de < current_size - 1; de++)
			governments[de] = governments[de + 1];
		current_size -= 1;
	}
	if (rec_number == 0)
		for (int i = 0; i < SIZE; i++)
			governments[i] = empty_government;
}

void search() {
	int nedded_area;
	cout << "Enter the area: ";
	cin >> nedded_area;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (governments[i].area > nedded_area)
			displayOneStructure(governments[i]);
	}
}