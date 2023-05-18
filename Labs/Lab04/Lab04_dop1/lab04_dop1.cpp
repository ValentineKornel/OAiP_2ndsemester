#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/* Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля : ФИО студента,
число экзаменов, полученные оценки.Определить функции для обработки отдельного объекта(например, для проверки,
сданы ли все экзамены на 4 и 5).Написать функцию для обработки массива структур.В результате обработки требуется
вычислить характеристику успеваемости студентов, то есть отношение числа студентов,
сдавших экзамены на 4 и 5, к общему числу студентов, в процентах.*/

struct exams {
	string fio;
	int numberOfExams;
	pair <string, int> ExamsAndMarks[100];
};
exams exam[100];
int k = 0;
void fileread() {
	ifstream file_to_write("fileA.txt");

	int count;
	string check;
	getline(file_to_write, check);
	count = stoi(check);
	for (int i = 0; i < count; i++) {
		getline(file_to_write, exam[k].fio);
		getline(file_to_write, check);
		exam[k].numberOfExams = stoi(check);
		for (int i = 0; i < exam[k].numberOfExams; i++) {
			getline(file_to_write, exam[k].ExamsAndMarks[i].first);
			getline(file_to_write, check);
			exam[k].ExamsAndMarks[i].second = stoi(check);
		}
		k++;
	}
}
void show() {
	for (int i = 0; i < k; i++) {
		cout << "Struct number-" << i + 1 << endl << "--------------------------------" << endl;
		cout << "FIO:" << exam[i].fio << endl;
		cout << "Number of exams:" << exam[i].numberOfExams << endl;
		cout << "Exams and marks:" << endl << "===============" << endl;
		for (int j = 0; j < exam[i].numberOfExams; j++) {
			cout << "Exam:" << exam[i].ExamsAndMarks[j].first << " " << "Mark:" << exam[i].ExamsAndMarks[j].second << endl;
		}
		cout << "===============" << endl;
	}
}
bool check(int n) {
	n -= 2;
	cout << exam[n].fio << ' ';
	for (int j = 0; j < exam[n].numberOfExams; j++)
		if (exam[n].ExamsAndMarks[j].second < 4 || exam[n].ExamsAndMarks[j].second > 5)
			return false;

	return true;
}
int statistics() {
	int count = 0;
	bool a = true;
	for (int i = 0; i < k; i++) {
		a = true;
		for (int j = 0; j < exam[i].numberOfExams; j++)
			if (exam[i].ExamsAndMarks[j].second < 4 || exam[i].ExamsAndMarks[j].second > 5)
				a = false;
		if (a)
			count++;
	}

	return count * 100 / k;
}
int main()
{
	fileread();
	show();
	int n;
	cin >> n;
	n++;
	if (check(n))
		cout << "All marks are 4 or 5\n";
	else
		cout << "Not all marks are 4 or 5\n";
	cout << statistics() << "%";
}