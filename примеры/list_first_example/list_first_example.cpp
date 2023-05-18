#include<iostream>
using namespace std;

class Spisok
{
private:
    struct node
    {
        int elem;
        node* sled;
    } *phead; //Указатель на начало списка.
public:
    Spisok() { phead = new (node); (*phead).sled = NULL; } //Конструктор.
    ~Spisok() { delete phead; } //Деструктор.
    void POSTROENIE();
    void VYVOD();
    void OCHISTKA();
};

void main()
{
    setlocale(LC_ALL, "Rus");
    Spisok A;

    A.POSTROENIE();
    A.VYVOD();
    A.OCHISTKA();

    cout << "\n";
    system("PAUSE");
}

void Spisok::POSTROENIE()
//Построение однонаправленного списка с заглавным звеном.
// phead - указатель на заглавное звено списка.
{
    node* t;
    int el;
    t = phead;
    cout << "Вводите элементы списка: ";
    cin >> el;
    while (el != 0)
    {
        (*t).sled = new (node);
        t = (*t).sled; (*t).elem = el; (*t).sled = NULL;
        cin >> el;
    }
}

void Spisok::VYVOD()
//Вывод содержимого однонаправленного линейного списка
//с заглавным звеном.
// phead - указатель на заглавное звено списка.
{
    node* t;
    t = (*phead).sled;
    cout << "Список: ";
    while (t != NULL)
    {
        cout << (*t).elem << " ";
        t = (*t).sled;
    }
    cout << endl;
}

void Spisok::OCHISTKA()
//Удаление однонаправленного списка из памяти.
// phead - указатель на заглавное звено списка.
{
    node* q, * q1;// Рабочие указатели.

    q = phead;
    q1 = (*q).sled; // Указатель q1 "опережает" указатель q.
    while (q1 != NULL)
    {
        q = q1; q1 = (*q1).sled; delete q;
    }
}
