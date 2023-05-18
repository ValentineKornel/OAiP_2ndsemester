#include <iostream>
#include <fstream>
#include <string>

#define str_length 30
#define size 30
using namespace std;

/*В соответствии со своим вариантом разработать программу для данных, приведенных в таблице ниже. Определить
структурированный тип, разработать меню для работы с массивом структур.
В программу должны войти функции:
− ввод элементов структуры с клавиатуры;
− вывод элементов структуры в консольное окно;
− удаление заданной структурированной переменной;
− поиск информации;
− запись информации в файл;
− чтение данных из файла.

Справочник автомобилей. Марка автомобиля, цвет, заводской номер, дата выпуска, тип кузова (седан,
универсал и т. п.), дата последнего техосмотра, владелец. Выбор транспортных средств по владельцу.
*/

int choice;
int current_year = 2023;
int current_y = 2023;
int current_m = 2;
int current_d = 14;

struct Automobile {
	char car_brand[str_length];
	char car_color[str_length];
	char factory_number[17];     // composed of 17 characters;
	int release_year;
	char body_type[str_length];
	int last_inspection_date;
	char owner[str_length];
};

struct Automobile list_of_cars[size];
struct Automobile empty_car;
int current_size = 0;

bool checkIfCorrectDate(int date, int current_y, int current_m, int current_d) {
	int is_correct_inspection_date = 0;
	int day, month, year;
	year = date % 10000;
	month = (date % 1000000 - year) / 10000;
	day = date / 1000000;

	if (year == current_y)
		is_correct_inspection_date = 2;
	if (year < current_y)
		is_correct_inspection_date = 1;
	if (is_correct_inspection_date == 2) {
		if (month > current_m)
			is_correct_inspection_date = 0;
		else if (month == current_m)
			is_correct_inspection_date = 2;
		else if (month < current_m)
			is_correct_inspection_date = 1;
		else if (month > 12)
			is_correct_inspection_date = 0;
	}
	if (is_correct_inspection_date == 2) {
		if (day > current_d)
			is_correct_inspection_date = 0;
		else if (day <= current_d)
			is_correct_inspection_date = 1;
		else if (day > 31)
			is_correct_inspection_date = 0;
	}
	if (month > 12 or day > 31)
		is_correct_inspection_date = 0;
	if (is_correct_inspection_date == 0) {
		cout << "Incorrect input" << endl;
		return false;
	}
	else return true;
}

void enter_new() {

	cout << "Information Entry" << endl;
	if (current_size < size) {
		cout << "Line number " << current_size + 1 << endl;

		cout << "Brand of the car: ";
		cin >> list_of_cars[current_size].car_brand;

		cout << "Car's color: ";
		cin >> list_of_cars[current_size].car_color;

		bool is_correct_year = false;
		do {
			cout << "Year of the car's release: ";
			cin >> list_of_cars[current_size].release_year;
			if (list_of_cars[current_size].release_year <= current_year)
				is_correct_year = true;
			else
				cout << "Incorrect input" << endl;
		} while (is_correct_year == false);

		cout << "Body type: ";
		cin >> list_of_cars[current_size].body_type;



		int is_correct_inspection_date = 0;
		do {
			cout << "Last_inspection_date(DDMMYYYY): ";
			cin >> list_of_cars[current_size].last_inspection_date;

			int day, month, year;
			year = list_of_cars[current_size].last_inspection_date % 10000;
			month = (list_of_cars[current_size].last_inspection_date % 1000000 - year) / 10000;
			day = list_of_cars[current_size].last_inspection_date / 1000000;

			if (year == current_y)
				is_correct_inspection_date = 2;
			if (year < current_y)
				is_correct_inspection_date = 1;
			if (is_correct_inspection_date == 2) {
				if (month > current_m)
					is_correct_inspection_date = 0;
				else if (month == current_m)
					is_correct_inspection_date = 2;
				else if (month < current_m)
					is_correct_inspection_date = 1;
				else if (month > 12)
					is_correct_inspection_date = 0;
			}
			if (is_correct_inspection_date == 2) {
				if (day > current_d)
					is_correct_inspection_date = 0;
				else if (day <= current_d)
					is_correct_inspection_date = 1;
				else if (day > 31)
					is_correct_inspection_date = 0;
			}
			if (month > 12 or day > 31)
				is_correct_inspection_date = 0;
			if (is_correct_inspection_date == 0)
				cout << "Incorrect input" << endl;
		} while (is_correct_inspection_date == 0);

		cout << "Owner: ";
		cin >> list_of_cars[current_size].owner;
		current_size++;
	}
	else
		cout << "No any more line can be entered" << endl;
}

void del() {

	int str_number;
	cout << "Enter the number of line to delete (enter 0 to clean all)" << endl;
	cin >> str_number;
	if (str_number != 0) {
		for (int de = (str_number - 1); de < current_size; de++)
			list_of_cars[de] = list_of_cars[de - 1];
		current_size -= 1;
	}
	if (str_number == 0)
		for (int i = 0; i < size; i++)
			list_of_cars[i] = empty_car;
}

void outputOneStructure(Automobile oneCar) {
	cout << "Brand of the car: " << oneCar.car_brand << endl;
	cout << "Car's color: " << oneCar.car_color << endl;
	cout << "Year of the car's release: " << oneCar.release_year << endl;
	cout << "Body type: " << oneCar.body_type << endl;
	cout << "Last inspection date(DDMMYYYY): " << oneCar.last_inspection_date << endl;
	cout << "Owner: " << oneCar.owner << endl;
}

void out() {
	int ch, num;
	cout << "1 - to display one record" << endl;
	cout << "2 - to display all records" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter the number of line to display" << endl;
		cin >> num;
		if (num > current_size or num < 1)
			cout << "Incorrect input";
		cout << endl;
		outputOneStructure(list_of_cars[num - 1]);
	}
	else if (ch == 2) {
		for (int i = 0; i < current_size; i++) {
			outputOneStructure(list_of_cars[i]);
			cout << endl;
		}
	}
	else
		cout << "Incorrect input";
}

void outToFile() {
	int N = 10;
	fflush(stdin); //clean the stream;
	ofstream file1("information.txt");
	for (int i = 0; i < current_size; i++) {
		file1 << "\tCar № " << i + 1 << endl;

		file1 << "Brand of the car: ";
		file1 << list_of_cars[i].car_brand << endl;

		file1 << "Car's color: ";
		file1 << list_of_cars[i].car_color << endl;


		file1 << "Year of the car's release: ";
		file1 << list_of_cars[i].release_year << endl;

		file1 << "Body type: ";
		file1 << list_of_cars[i].body_type << endl;


		file1 << "Last_inspection_date(DDMMYYYY): ";
		file1 << list_of_cars[i].last_inspection_date << endl;

		file1 << "Owner: ";
		file1 << list_of_cars[i].owner << endl << endl << endl;
	}
	cout << endl << endl;
}

void inputFromFile() {
	string str;
	ifstream file1("information.txt");
	while (file1) {
		getline(file1, str);
		cout << str << endl;
	}
}

void search() {
	char the_owner[str_length];
	cout << "Enter the name of the owner" << endl;
	cin >> the_owner;
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		if (strcmp(list_of_cars[i].owner, the_owner) == 0) {
			outputOneStructure(list_of_cars[i]);
		}
	}
}




int main() {
	int temp;
	cin >> temp;
	cout << "enter the date to check if correct" << endl;
	checkIfCorrectDate(temp, current_y, current_m, current_d);

	setlocale(LC_CTYPE, "Russian");
	cout << "No information" << endl;
	do {
		cout << "Enter:" << endl;
		cout << "1 - to make new record" << endl;
		cout << "2 - to detele record" << endl;
		cout << "3 - to display records" << endl;
		cout << "4 - to enter into the file" << endl;
		cout << "5 - to display the information in the file" << endl;
		cout << "6 - to searh by the owner" << endl;
		cout << "7 - to exit" << endl;
		cin >> choice;

		switch (choice) {
		case 1: enter_new(); break;
		case 2: del(); break;
		case 3: out(); break;
		case 4: outToFile(); break;
		case 5: inputFromFile(); break;
		case 6: search(); break;
		}
	} while (choice != 7);
	
}