#include<iostream>
using namespace std;

struct nodeVis
{
    int elem; //�������������� ���� ����� ��������.
    nodeVis* vniz;//��������� �� ����� ��������.
};
struct nodeGir
{
    int elem;//�������������� ���� ����� ��������.
    nodeVis* vniz;//��������� �� ����� ��������.
    nodeGir* sled;//��������� �� ����� ��������.
};

class GirVis {
private:
    nodeGir* phead;//������ ��������.
    nodeVis* pheadVis;//������ ��������.
    void VisVyvod();
public:
    GirVis() { phead = new (nodeGir); }
    ~GirVis() { delete phead; }
    nodeVis* VisPostr();
    nodeVis* VisPoisk(int);
    void SetpheadVis(nodeVis* r) { pheadVis = r; } //����������� ������ ��������.
    void VisVstav(nodeVis*, int);
    void Vis1Vstav(nodeVis*, int);
    void  VisUdale(nodeVis*);
    void Vis1Udale(nodeVis*);
    void GirPostr();
    void GirVyvod();
    nodeGir* GirPoisk(int);
    void OCHISTKA();
    void OCHISTKA1();
};

void main()
{
    setlocale(LC_ALL, "Rus");
    GirVis A;
    int el, elGir, elVis;
    nodeGir* Res; //������� ���������.
    nodeVis* ResVis; //��������� �� ����� ��������.

    A.GirPostr();
    A.GirVyvod();
    cout << "\n������� ������� ����� ��������, ";
    cout << "��� �������� ����� ��������:\n";
    cin >> elGir;
    cout << "\n������� ������� ����� ��������, ����� �������� ";
    cout << "�������������� �������:\n";
    cin >> elVis;
    cout << "\n������� ����������� �������:\n";
    cin >> el;
    //����� �������� elGir � ��������.
    Res = A.GirPoisk(elGir);
    if (Res != NULL)
    {
        //����� �������� elVis � ��������.
        A.SetpheadVis((*Res).vniz);
        ResVis = A.VisPoisk(elVis);
        if (ResVis != NULL)
            A.VisVstav(ResVis, el);
        else  cout << "�������� � �������� ���!\n";
    }
    else  cout << "�������� � �������� ���\n";
    A.GirVyvod();

    cout << "\n������� ������� ��������, ��� �������� ����� ��������:\n";
    cin >> elGir;
    cout << "������� ������� ��������, ����� ������� ";
    cout << "�������������� �������:\n";
    cin >> elVis;
    cout << "������� ����������� �������:\n";
    cin >> el;
    //����� �������� elGir � ��������.
    Res = A.GirPoisk(elGir);
    if (Res != NULL)
    {
        //����� �������� elVis � ��������.
        A.SetpheadVis((*Res).vniz);
        ResVis = A.VisPoisk(elVis);
        if (ResVis != NULL)
            A.Vis1Vstav(ResVis, el);
        else  cout << "�������� � �������� ���!\n";
    }
    else  cout << "�������� � �������� ���!\n";
    A.GirVyvod();

    cout << "\n������� ������� ��������, ��� �������� ����� ��������:\n";
    cin >> elGir;
    cout << "������� ������� ��������, ����� �������� ����� �������:\n";
    cin >> elVis;
    //����� �������� elGir � ��������.
    Res = A.GirPoisk(elGir);
    if (Res != NULL)
    {
        //����� �������� elVis � ��������.
        A.SetpheadVis((*Res).vniz);
        ResVis = A.VisPoisk(elVis);
        if ((ResVis != NULL) && ((*ResVis).vniz != NULL))
            A.VisUdale(ResVis);
        else  cout << "�������� � �������� ���!\n";
    }
    else  cout << "�������� � �������� ���!\n";
    A.GirVyvod();

    cout << "\n������� ������� ��������, ��� �������� ����� ��������:\n";
    cin >> elGir;
    cout << "������� ������� ��������, ������� ���������:\n";
    cin >> elVis;
    //����� �������� elGir � ��������.
    Res = A.GirPoisk(elGir);
    if (Res != NULL)
    {
        //����� �������� elVis � ��������.
        A.SetpheadVis((*Res).vniz);
        ResVis = A.VisPoisk(elVis);
        if ((ResVis != NULL) && ((*ResVis).vniz != NULL))
            A.Vis1Udale(ResVis);
        else  cout << "�������� � �������� ��� ��� �� ���������!\n";
    }
    else  cout << "�������� � �������� ���!\n";
    A.GirVyvod();
    A.OCHISTKA();

    cout << "\n";
    system("PAUSE");
}

void GirVis::OCHISTKA()
{
    nodeGir* q, * q1;//������� ���������.
    q = phead;
    q1 = (*q).sled; //��������� q1 "���������" ��������� q.

    while (q1 != NULL)  // ���� ������ �� ������.
    {
        q = q1; q1 = (*q1).sled;
        pheadVis = (*q).vniz;
        OCHISTKA1(); //������� ��������.
        delete q;
    }
}

void GirVis::OCHISTKA1()
{
    nodeVis* q, * q1;
    q = pheadVis;
    //������� ������ �������� �� �������.
    q1 = (*q).vniz;
    while (q1 != NULL)
    {
        q = q1; q1 = (*q1).vniz;
        delete q;
    }
}

void GirVis::GirPostr()
//���������� ����������������� ������ � ��������� ������,
//��������� ���������� phead (���������� ��������).
{
    nodeGir* t;
    int el;
    t = phead; (*t).sled = NULL;
    cout << "������� ������� ��������: \n";
    cin >> el;
    while (el != 0)
    {
        (*t).sled = new (nodeGir);
        t = (*t).sled; (*t).elem = el; (*t).sled = NULL;
        (*t).vniz = VisPostr();
        cout << " ������� ������� ��������: \n";
        cin >> el;
    }
}

// ������� VisPostr() ������ ���������������� ������ ��� ��������, 
// ������� � ���������� ����� pheadVis.
nodeVis* GirVis::VisPostr()
{
    nodeVis* t;
    int el;
    // ������� ��������� ����� ������.
    pheadVis = new (nodeVis);
    t = pheadVis;
    (*t).vniz = NULL;
    cout << "������� �������� ������� ��������: \n";
    cin >> el;
    // ������ �������� ������� � ��������� �� � ������.
    while (el != 0)
    {
        (*t).vniz = new (nodeVis);
        t = (*t).vniz;
        (*t).elem = el;
        (*t).vniz = NULL;
        cin >> el;
    }
    return pheadVis;
}

// ������� GirVyvod() ������� ���������� ��������, 
// ������� ���������� �������� ������� �����.
void GirVis::GirVyvod()
{
    nodeGir* t;
    // �������� � ������� ����� ����� ����������.
    t = phead;
    t = (*t).sled;
    cout << "��������: ";
    // ������� ���������� ������� ����� � ��� ��������.
    while (t != NULL)
    {
        cout << (*t).elem << " ";
        pheadVis = (*t).vniz;
        VisVyvod();
        t = (*t).sled;
    }
}

// ������� GirPoisk() ������������ ����� �������� el � ������ ��������.
// ���������� ����� � ������� �������� ����� ���������� �����.
// ���� ������� ������, ���������� ����� ����� ������, ����������� ������� el.
// ���� ������� �� ������, ���������� NULL.

nodeGir* GirVis::GirPoisk(int el) {
    // ������� ��� ��������� �� ������ ������
    nodeGir* t, * r;
    r = NULL; // �������������� r ��������� NULL
    t = phead; // t ��������� �� ��������� ����� ��������
    t = (*t).sled; // t ������ ��������� �� ������ ������� �������� (����� ����������)

    // �������� �� ���� ��������� ��������
    while (t != NULL && r == NULL) {
        if ((*t).elem == el) { // ���� ����� ������ �������
            r = t; // ���������� ����� �����, ����������� ������� el
        }
        else {
            t = (*t).sled; // ����� ��������� � ���������� �����
        }
    }
    return r; // ���������� ����� �����, ����������� ������� el (��� NULL, ���� ������� �� ������)
}

// ������� VisVyvod() ������� ���������� ����������������� ������ ��� ��������,
// ��������� ���������� pheadVis. ��������� ���������� �������� � �������.
void GirVis::VisVyvod() {
    nodeVis* t;
    t = pheadVis; // t ��������� �� ��������� ����� ������ ��� ��������
    t = (*t).vniz; // t ������ ��������� �� ������ ������� ������ ��� ��������

    cout << "(";
    while (t != NULL) { // ���� �� �������� ����� ������
        cout << (*t).elem << " "; // ������� �������� ��������
        t = (*t).vniz; // ��������� � ���������� ����� ������
    }
    cout << ")";
}


// ������� VisPoisk() ������������ ����� �������� el � ������ ��� ��������,
// �������� ���������� pheadVis. ���� ������� ������, ���������� ����� ����� ������,
// ����������� ������� el. ���� ������� �� ������, ���������� NULL.
nodeVis* GirVis::VisPoisk(int el) {
    nodeVis* t, * r;
    r = NULL;
    t = pheadVis;
    t = (*t).vniz;

    while (t != NULL && r == NULL) {
        if ((*t).elem == el) {
            r = t;
        }
        else {
            t = (*t).vniz;
        }
    }
    return r;
}

void GirVis::VisVstav(nodeVis* r, int el)
//��������� ����� � �������������� ����� el
//����� �����, �� ������� ��������� r
//(��������� ����� � ��������).
{
    nodeVis* q;

    q = new (nodeVis);
    (*q).elem = el; (*q).vniz = (*r).vniz; (*r).vniz = q;
}

void GirVis::Vis1Vstav(nodeVis* r, int el)
//��������� ����� � �������������� ����� el
//����� ������, �� ������� ��������� r
//(��������� ����� � ��������).
{
    nodeVis* q;

    q = new (nodeVis);
    (*q).elem = (*r).elem; (*q).vniz = (*r).vniz;
    (*r).elem = el; (*r).vniz = q;
}

void GirVis::VisUdale(nodeVis* r)
//�������� �����, �������������� ����� �����,
//�� ������� ��������� ������ r
//(�������� ����� ��������).
{
    nodeVis* q;
    q = (*r).vniz;
    if ((*r).vniz != NULL)
    {
        (*r).vniz = (*(*r).vniz).vniz; delete q;
    }
    else  cout << "����� � �������� ��������� - ���������!\n";
}

void GirVis::Vis1Udale(nodeVis* r)
//�������� �����, �� ������� ��������� ������ r
//(�������� ����� ��������).
{
    nodeVis* g;

    if ((*r).vniz != NULL)
    {
        g = (*r).vniz;
        (*r).elem = (*(*r).vniz).elem;
        (*r).vniz = (*(*r).vniz).vniz;
        delete g;
    }
    else  cout << "�� ���� ������� ��������� �����!\n";
}
