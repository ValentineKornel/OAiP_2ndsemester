#include<iostream>
using namespace std;

class Spisok
{
private:
    struct node
    {
        int elem;
        node* sled;
    } *phead; //��������� �� ������ ������.
public:
    Spisok() { phead = new (node); (*phead).sled = NULL; } //�����������.
    ~Spisok() { delete phead; } //����������.
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
//���������� ����������������� ������ � ��������� ������.
// phead - ��������� �� ��������� ����� ������.
{
    node* t;
    int el;
    t = phead;
    cout << "������� �������� ������: ";
    cin >> el;
    while (el != 0)
    {
        (*t).sled = new (node);
        t = (*t).sled; (*t).elem = el; (*t).sled = NULL;
        cin >> el;
    }
}

void Spisok::VYVOD()
//����� ����������� ����������������� ��������� ������
//� ��������� ������.
// phead - ��������� �� ��������� ����� ������.
{
    node* t;
    t = (*phead).sled;
    cout << "������: ";
    while (t != NULL)
    {
        cout << (*t).elem << " ";
        t = (*t).sled;
    }
    cout << endl;
}

void Spisok::OCHISTKA()
//�������� ����������������� ������ �� ������.
// phead - ��������� �� ��������� ����� ������.
{
    node* q, * q1;// ������� ���������.

    q = phead;
    q1 = (*q).sled; // ��������� q1 "���������" ��������� q.
    while (q1 != NULL)
    {
        q = q1; q1 = (*q1).sled; delete q;
    }
}
