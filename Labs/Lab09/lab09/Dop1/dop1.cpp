/*1 доп
Дополнить проект, разработав функцию
deleteList (удаление списка) и функцию
countList (подсчет числа элементов списка).
В содержимом списка отразить информацию
в соответствии со своим вариантом из лабораторной
работы № 4. Справочник автомобилей. Марка автомобиля, цвет, 
заводской номер, дата выпуска, тип кузова (седан, универсал и т. п.), 
дата последнего техосмотра, владелец. Выбор транспортных средств по владельцу.
*/
#include <iostream>
#include "List.h"
using namespace std;

int current_year = 2023;
int current_month = 3;
int current_day = 29;

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
		return false;
	}
	else return true;
}

void insert(address* e, address** phead, address** plast)
{
	address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

address* setelement()
{
	address* temp = new address();
	if (!temp)
	{
		cerr << "Error giving the memory";
		return NULL;
	}
	cout << "Input car brand: ";
	cin.get();
	cin.getline(temp->car_brand, NAME_SIZE);
	cout << "Input car color: ";
	cin.get();
	cin.getline(temp->car_color, NAME_SIZE);
	cout << "Input factory number: ";
	cin.get();
	cin.getline(temp->factory_number, NAME_SIZE);
	cout << "Input relese year: ";
	bool is_correct_year = true;
	cin >> temp->release_year;
	if (temp->release_year > current_year)
		is_correct_year = false;
	while (!is_correct_year) {
		cout << "Incorrect input" << endl;
		cout << "Input relese year: ";
		cin >> temp->release_year;
		if (temp->release_year <= current_year)
			is_correct_year = true;
	}
	cout << "Input body type: ";
	cin.get();
	cin.getline(temp->body_type, NAME_SIZE);
	cout << "Input last inspection date: ";
	cin >> temp->last_inspection_date;
	if (!checkIfCorrectDate(temp->last_inspection_date, current_year, current_month, current_day)) {
		while (!checkIfCorrectDate(temp->last_inspection_date, current_year, current_month, current_day)) {
			cout << "Incorrect input" << endl;
			cout << "Input last inspection date: ";
			cin >> temp->last_inspection_date;
		}
	}
	cout << "Input owner: ";
	cin.get();
	cin.getline(temp->owner, NAME_SIZE);
	
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputlist(address** phead, address** plast)
{
	address* t = *phead;
	if (t == NULL)
	{
		cout << "The list is empty!" << endl;
	}
	while (t)
	{
		cout << endl;
		cout << "Car brand:" << t->car_brand << endl;
		cout << "Car color:" << t->car_color << endl;
		cout << "Factory number:" << t->factory_number << endl;
		cout << "Release year:" << t->release_year << endl;
		cout << "Body type:" << t->body_type << endl;
		cout << "Last inspection date:" << t->last_inspection_date;
		cout << "owner:" << t->owner << endl;
		cout << endl;
		
		t = t->next;
	}
	cout << "" << endl;
}
void find(char number[NAME_SIZE], address** phead)
{
	address* t = *phead;
	while (t)
	{
		if (!strcmp(number, t->owner)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Owner wasn't founded" << endl;
	else {
		cout << endl;
		cout << "Car brand:" << t->car_brand << endl;
		cout << "Car color:" << t->car_color << endl;
		cout << "Factory number:" << t->factory_number << endl;
		cout << "Release year:" << t->release_year << endl;
		cout << "Body type:" << t->body_type << endl;
		cout << "Last inspection date:" << t->last_inspection_date;
		cout << "owner:" << t->owner << endl;
		cout << endl;
	}
	
}
void countlist(address** phead, address** plast)
{
	address* t = *phead;
	int i = 0;
	while (t != NULL)
	{
		i++;
		t = t->next;
	}
	cout << "Amount of elements=" << i << endl;
}
void delall(address** phead, address** plast)
{
	address* t = *phead;
	while (t != NULL)
	{

		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		t = t->next;
		delete t;
	}
	cout << "List is cleaned!" << endl;
}
int main()
{
	address* head = NULL;
	address* last = NULL;
	setlocale(LC_CTYPE, "rus");
	int choice;
	char s[80]; int c;
	cout << endl;
	cout << "1. enter an element" << endl;
	cout << "2. display elements" << endl;
	cout << "3. search" << endl;
	cout << "4. amount of elements" << endl;
	cout << "5. clean the list" << endl;
	cout << "6. exit" << endl;
	cout << endl;
	for (;;)
	{
		cout << "Your choise: ";
		cin >> choice;
		switch (choice)
		{
		case 1: insert(setelement(), &head, &last);
			break;
		case 2: outputlist(&head, &last);
			break;
		case 3: { char owner_to_search[NAME_SIZE];
			cout << "Enter the owner to search: ";
			cin.get();
			cin.getline(owner_to_search, NAME_SIZE);
			find(owner_to_search, &head);
		}
			  break;
		case 4: {

			countlist(&head, &last);
		}
			  break;
		case 5: {
			delall(&head, &last);
		}
			  break;
		case 6: exit(0);
		default: exit(1);
		}
	}
 return 0;
}
