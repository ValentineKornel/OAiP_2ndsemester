#include<iostream>
using namespace std;

struct node
{
    int  elem;
    node* sled;
};

class Spisok
{
private:
    node* phead; //��������� �� ��������� ����� ������.
    node* Res; //��������� �� ��������� ����� ������.
public:
    Spisok() { phead = new(node); (*phead).sled = NULL; Res = NULL; }
    ~Spisok() { delete phead; }
    void POSTROENIE();
    void VYVOD();
    node* POISK(int);
    void VSTAV(int);
    void VSTAV1(int);
    void OCHISTKA();
};

void main()
{
    setlocale(LC_ALL, "Rus");
    Spisok A;
    int  el, el1;

    A.POSTROENIE();
    A.VYVOD();
    cout << "\n������� ������� �����, ����� �������� ";
    cout << "�������������� �������:\n";
    cin >> el;
    cout << "������� ������� ������������ �����:\n";
    cin >> el1;
    if (A.POISK(el) != NULL)
    {
        A.VSTAV(el1); A.VYVOD();
    }
    else  cout << "����� � �������� ��������� � ������ ���!";
    cout << "\n������� ������� �����, ����� �������  ";
    cout << "�������������� �������:\n";
    cin >> el;
    cout << " ������� ������� ������������ �����:\n";
    cin >> el1;
    if (A.POISK(el) != NULL)
    {
        A.VSTAV1(el1); A.VYVOD();
    }
    else  cout << " ����� � �������� ��������� � ������ ���!";
    A.OCHISTKA();

    cout << "\n";
    system("PAUSE");
}

void Spisok::POSTROENIE()
// ���������� ����������������� ������ � ��������� ������.
// phead - ��������� �� ��������� ����� ������         
{
    node* t;
    int   el;
    t = phead;
    cout << "������� �������� ������� ������: ";
    cin >> el;
    while (el != 0)
    {
        (*t).sled = new (node);
        t = (*t).sled; (*t).elem = el; (*t).sled = NULL;
        cin >> el;
    }
}

void Spisok::VYVOD()
// ����� ����������� ����������������� ������ �
// ��������� ������.  phead - ��������� �� ��������� ����� ������.
{
    node* t;

    t = (*phead).sled;
    cout << "������: ";
    while (t != NULL)
    {
        cout << (*t).elem << " "; t = (*t).sled;
    }
    cout << endl;
}

node* Spisok::POISK(int el)
//����� ����� � ��������� el � ������, �������� ����������
//phead. � ������ ��������� ������ � Res ��������� �����
//����� ������, ����������� ������� el, � ������  ��������
//� Res ���������� NULL.
{
    node* t;

    Res = NULL; t = (*phead).sled;
    while (t != NULL && Res == NULL)
        if ((*t).elem == el)
            Res = t;
        else  t = (*t).sled;

    return Res;
}

void Spisok::VSTAV(int el)
// ��������� �����  �  �������������� �����  el
// ����� �����, �� ������� ��������� ������ Res.
{
    node* q;

    q = new(node);
    (*q).elem = el;
    (*q).sled = (*Res).sled; (*Res).sled = q;
}

void Spisok::VSTAV1(int el)
// ��������� ����� � �������������� ����� el
// ����� ������, ��  �������  ���������  Res.
{
    node* q;

    q = new (node);
    (*q).elem = (*Res).elem; (*q).sled = (*Res).sled;
    (*Res).elem = el; (*Res).sled = q;
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
