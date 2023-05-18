#include <iostream>
#include <string>
using namespace std;

/* 
Студенты. Ф.И.О., дата поступления, специальность, группа, факультет, 
средний балл. Выбор по среднему баллу. Дату поступления реализовать с 
помощью битового поля, факультет  с помощью перечисления.
*/

const int SIZE = 30;
int current_size = 0;
int current_y = 2023;
int current_m = 3;
int current_d = 14;

enum Faculties {
	FIT = 1, 
	TOV,
	HTIT,
	PIM
};

struct EnterTime {
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 11;
};

struct Students {
	string surname;
	string name;
	string middlename;
	EnterTime enter_time;
	string specialty;
	unsigned group : 5;
	Faculties faculty;
	float average;
} students[SIZE];
struct Students empty_student;

void addNew();
void displayOneStructure(Students onePupil);
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
		cin >> students[current_size].surname;

		cout << "Name: ";
		cin >> students[current_size].name;

		cout << "Middlename: ";
		cin >> students[current_size].middlename;

		int is_correct_arriving_time = 0;       
		do {
			int day;
			int month;
			int year;
			cout << "Entering time: " << endl;
			
			cout << "Day: ";
			cin >> day;
			students[current_size].enter_time.day = day;
			cout << "Month: ";
			cin >> month;
			students[current_size].enter_time.month = month;
			cout << "Year: ";
			cin >> year;
			students[current_size].enter_time.year = year;

			if (year == current_y)
				is_correct_arriving_time = 2;
			if (year < current_y)
				is_correct_arriving_time = 1;
			if (is_correct_arriving_time == 2) {
				if (month > current_m)
					is_correct_arriving_time = 0;
				else if (month == current_m)
					is_correct_arriving_time = 2;
				else if (month < current_m)
					is_correct_arriving_time = 1;
				else if (month > 12)
					is_correct_arriving_time = 0;
			}
			if (is_correct_arriving_time == 2) {
				if (day > current_d)
					is_correct_arriving_time = 0;
				else if (day <= current_d)
					is_correct_arriving_time = 1;
				else if (day > 31)
					is_correct_arriving_time = 0;
			}
			if (month > 12 or day > 31)
				is_correct_arriving_time = 0;
			if (is_correct_arriving_time == 0)
				cout << "Incorrect input" << endl;
		} while (is_correct_arriving_time == 0);

		

		cout << "Specialty: ";
		cin.get();
		getline(cin, students[current_size].specialty);

		int gr;
		cout << "Group: ";
		cin >> gr;
		students[current_size].group = gr;

		cout << "Faculty(1 - FIT, 2 - TOV, 3 - HTIT, 4 - PIM): ";
		int fac;
		do {
			cin >> fac;
			if (fac < 1 or fac > 4)
				cout << "Incoret input";
		} while (fac < 1 or fac > 4);
		if (fac == 1)
			students[current_size].faculty = FIT;
		if (fac == 2)
			students[current_size].faculty = TOV;
		if (fac == 3)
			students[current_size].faculty = HTIT;
		if (fac == 4)
			students[current_size].faculty = PIM;

		cout << "Average grade: ";
		cin >> students[current_size].average;

		current_size++;
	}
	else
		cout << "No any monre records cane be enetered" << endl;
}


void displayOneStructure(Students onePupil) {
	cout << endl;
	cout << "Surname: " << onePupil.surname << endl;
	cout << "Name: " << onePupil.name << endl;
	cout << "Middlename: " << onePupil.middlename << endl;
	cout << "Entertin time: " << endl;
	cout << "Day: " << onePupil.enter_time.day << endl;
	cout << "Month: " << onePupil.enter_time.month << endl;
	cout << "Year: " << onePupil.enter_time.year << endl;
	cout << "Specialty: " << onePupil.specialty << endl;
	cout << "Group: " << onePupil.group << endl;
	cout << "Faculty:";
	if (onePupil.faculty == FIT)
		cout << "FIT" << endl;
	if (onePupil.faculty == TOV)
		cout << "TOV" << endl;
	if (onePupil.faculty == HTIT)
		cout << "HTIT" << endl;
	if (onePupil.faculty == PIM)
		cout << "PIM" << endl;
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
		displayOneStructure(students[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			displayOneStructure(students[i]);
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
			students[de] = students[de + 1];
		current_size -= 1;
	}
	if (rec_number == 0)
		for (int i = 0; i < SIZE; i++)
			students[i] = empty_student;
}

void search() {
	float nedded_average;
	cout << "Enter the average grade to search: ";
	cin >> nedded_average;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (students[i].average == nedded_average)
			displayOneStructure(students[i]);
	}
}

