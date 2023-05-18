#pragma once
using namespace std;
const unsigned int NAME_SIZE = 50;
const unsigned int CITY_SIZE = 40;

struct address
{
	char car_brand[NAME_SIZE];
	char car_color[NAME_SIZE];
	char factory_number[NAME_SIZE];
	int release_year;
	char body_type[NAME_SIZE];
	int last_inspection_date;
	char owner[NAME_SIZE];

	address* next;
	address* prev;
};
bool checkIfCorrectDate(int date, int current_y, int current_m, int current_d);
void insert(address* e, address** phead, address** plast);
address* setElement();
void outputList(address** phead, address** plast);
void find(char name[NAME_SIZE], address** phead);
void countList(address** phead, address** plast);
void delAll(address * *phead, address * *plast);
