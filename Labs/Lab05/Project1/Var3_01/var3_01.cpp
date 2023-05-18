#include <iostream>
#include <string>
using namespace std;

/* 
Ученики. Ф.И.О., класс (цифра+буква), оценки, средний балл. Выбор по 
фамилии. Класс реализовать с помощью битового поля, предметы через перечисление.
*/

const int SIZE = 30;
int current_size = 0;

enum Sublects {
	math = 1,
	physics,
	literature,
	english,  
	kpo,
	oaip
};

struct Klass {
	unsigned num : 4;
	char letter;
};

struct Pupils {
	string surname;
	string name;
	string middlename;
	Klass klass;
	int marks[6];
	float average;
} pupils[SIZE];
struct Pupils empty_pupil;

void addNew();
void displayOneStructure(Pupils onePupil);
void display();
void deleteRecord();
void search();

void main()
{
	
	short choose;
	do
	{
		cout << "Enter:\n1 - to enter new record;\n2 - to display information;\n3 - to delete the rocord;\n4 - to search\n5 - to exit.\n";
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
		cin >> pupils[current_size].surname;

		cout << "Name: ";
		cin >> pupils[current_size].name;

		cout << "Middlename: ";
		cin >> pupils[current_size].middlename;

		cout << "klass(number): ";
		int klass_num;
		cin >> klass_num;
		if (klass_num < 1 or klass_num > 11) {
			cout << "Incorrect input" << endl;
			cin >> klass_num;
		}
		pupils[current_size].klass.num = klass_num;

		cout << "klass(letter): ";
		cin >> pupils[current_size].klass.letter;

		cout << "Marks(math, physics, literature, english, kpo, oaip): ";
		for (int i = 0; i < 6; i++) {
			cin >> pupils[current_size].marks[i];
		}
		pupils[current_size].average = (((float)pupils[current_size].marks[math] +
			(float)pupils[current_size].marks[physics] +
			(float)pupils[current_size].marks[literature] +
			(float)pupils[current_size].marks[english] +
			(float)pupils[current_size].marks[kpo] +
			(float)pupils[current_size].marks[oaip]) / 6);
		
		current_size++;
	}
	else
		cout << "No any monre records cane be enetered" << endl;
}


void displayOneStructure(Pupils onePupil) {
	cout << endl;
	cout << "Surname: " << onePupil.surname << endl;
	cout << "Name: " << onePupil.name << endl;
	cout << "Middlename: " << onePupil.middlename << endl;
	cout << "klass(number): " << onePupil.klass.num << endl;
	cout << "klass(letter): " << onePupil.klass.letter << endl;
	cout << "Marks:" << endl;
	cout << "Math: " << onePupil.marks[math] << endl;
	cout << "Physics: " << onePupil.marks[physics] << endl;
	cout << "Literature: " << onePupil.marks[literature] << endl;
	cout << "English: " << onePupil.marks[english] << endl;
	cout << "KPO: " << onePupil.marks[kpo] << endl;
	cout << "OAiP: " << onePupil.marks[oaip] << endl;
	cout << "Average grade: " << onePupil.average << endl;
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
		displayOneStructure(pupils[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			displayOneStructure(pupils[i]);
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
			pupils[de] = pupils[de + 1];
		current_size -= 1;
	}
	if (rec_number == 0)
		for (int i = 0; i < SIZE; i++)
			pupils[i] = empty_pupil;
}

void search() {
	string nedded_surname;
	cout << "Enter the surname to search: ";
	cin >> nedded_surname;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (pupils[i].surname == nedded_surname)
			displayOneStructure(pupils[i]);
	}
}