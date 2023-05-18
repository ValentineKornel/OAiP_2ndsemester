#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
/* Описать структуру с именем TRAIN, содержащую поля: названия пункта назначения, номер поезда, время
отправления. Написать программу, выполняющую ввод с клавиатуры данных в массив, состоящий из восьми элементов типа
TRAIN (записи должны быть размещены в алфавитном порядке по названиям пунктов назначения); вывод на экран
информации о поездах, отправляющихся после введенного с клавиатуры времени (если таких поездов нет, то вывести
сообщение об этом).*/


struct TRAIN {
	string pointOfDestination;
	int trainNumber;
	int departureTime;
};

TRAIN shedule[8];
int k = 0;

void fileread() {
	ifstream fin("fileA.txt");

	int count;
	string check;
	getline(fin, check);
	count = stoi(check);
	for (int i = 0; i < count; i++) {
		getline(fin, shedule[k].pointOfDestination);
		getline(fin, check);
		shedule[k].trainNumber = stoi(check);
		getline(fin, check);
		shedule[k].departureTime = stoi(check);
		k++;
	}
}
void show() {
	string tmp;
	for (int i = 0; i < k; i++) {
		tmp = to_string(shedule[i].departureTime);
		if (tmp > "2359")
			continue;
		cout << "--------------------------------" << endl;
		cout << "Point of destination:" << shedule[i].pointOfDestination << endl;
		cout << "Train number:" << shedule[i].trainNumber << endl;
		tmp = to_string(shedule[i].departureTime);
		if (tmp.size() == 4)
			cout << "Departure time-> " << tmp[0] << tmp[1] << ":" << tmp[2] << tmp[3] << endl;
		else
			cout << "Departure time-> " << tmp[0] << ":" << tmp[1] << tmp[2] << endl;
	}
}
void timesearch(int time) {
	int b = true;
	string tmp;
	for (int i = 0; i < k; i++) {
		if (shedule[i].departureTime > time) {
			b = false;
			cout << "--------------------------------" << endl;
			cout << "Point of destination:" << shedule[i].pointOfDestination << endl;
			cout << "Train number:" << shedule[i].trainNumber << endl;
			tmp = to_string(shedule[i].departureTime);
			if (tmp > "2359")
				cout << "Departure time->" << "8:00" << endl;
			else if (tmp.size() == 4)
				cout << "Departure time-> " << tmp[0] << tmp[1] << ":" << tmp[2] << tmp[3] << endl;
			else
				cout << "Departure time-> " << tmp[0] << ":" << tmp[1] << tmp[2] << endl;
		}
	}
	if (b)
		cout << "No trains after this time";
}
bool comp(TRAIN a, TRAIN b) {
	return a.pointOfDestination < b.pointOfDestination;
}

int main()
{
	fileread();
	show();
	sort(shedule, shedule + 8, comp);
	cout << endl << endl << endl;
	show();
	int time;
	cin >> time;
	system("CLS");
	timesearch(time);
}