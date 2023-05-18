#include<iostream>
using namespace std;

struct nodeVis
{
    int elem; //Информационное поле звена висюльки.
    nodeVis* vniz;//Указатель на звено висюльки.
};
struct nodeGir
{
    int elem;//Информационное поле звена гирлянды.
    nodeVis* vniz;//Указатель на звено висюльки.
    nodeGir* sled;//Указатель на звено гирлянды.
};

class GirVis {
private:
    nodeGir* phead;//Голова гирлянды.
    nodeVis* pheadVis;//Голова висюльки.
    void VisVyvod();
public:
    GirVis() { phead = new (nodeGir); }
    ~GirVis() { delete phead; }
    nodeVis* VisPostr();
    nodeVis* VisPoisk(int);
    void SetpheadVis(nodeVis* r) { pheadVis = r; } //Определение головы висюльки.
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
    nodeGir* Res; //Рабочий указатель.
    nodeVis* ResVis; //Указатель на звено висюльки.

    A.GirPostr();
    A.GirVyvod();
    cout << "\nВведите элемент звена гирлянды, ";
    cout << "чьи висюльки будем изменять:\n";
    cin >> elGir;
    cout << "\nВведите элемент звена висюльки, после которого ";
    cout << "осуществляется вставка:\n";
    cin >> elVis;
    cout << "\nВведите вставляемый элемент:\n";
    cin >> el;
    //Поиск элемента elGir в гирлянде.
    Res = A.GirPoisk(elGir);
    if (Res != NULL)
    {
        //Поиск элемента elVis в висюльке.
        A.SetpheadVis((*Res).vniz);
        ResVis = A.VisPoisk(elVis);
        if (ResVis != NULL)
            A.VisVstav(ResVis, el);
        else  cout << "Элемента в висюльке нет!\n";
    }
    else  cout << "Элемента в гирлянде нет\n";
    A.GirVyvod();

    cout << "\nВведите элемент гирлянды, чью висюльку будем изменять:\n";
    cin >> elGir;
    cout << "Введите элемент висюльки, перед которым ";
    cout << "осуществляется вставка:\n";
    cin >> elVis;
    cout << "Введите вставляемый элемент:\n";
    cin >> el;
    //Поиск элемента elGir в гирлянде.
    Res = A.GirPoisk(elGir);
    if (Res != NULL)
    {
        //Поиск элемента elVis в висюльке.
        A.SetpheadVis((*Res).vniz);
        ResVis = A.VisPoisk(elVis);
        if (ResVis != NULL)
            A.Vis1Vstav(ResVis, el);
        else  cout << "Элемента в висюльке нет!\n";
    }
    else  cout << "Элемента в гирлянде нет!\n";
    A.GirVyvod();

    cout << "\nВведите элемент гирлянды, чью висюльку будем изменять:\n";
    cin >> elGir;
    cout << "Введите элемент висюльки, после которого нужно удалить:\n";
    cin >> elVis;
    //Поиск элемента elGir в гирлянде.
    Res = A.GirPoisk(elGir);
    if (Res != NULL)
    {
        //Поиск элемента elVis в висюльке.
        A.SetpheadVis((*Res).vniz);
        ResVis = A.VisPoisk(elVis);
        if ((ResVis != NULL) && ((*ResVis).vniz != NULL))
            A.VisUdale(ResVis);
        else  cout << "Элемента в висюльке нет!\n";
    }
    else  cout << "Элемента в гирлянде нет!\n";
    A.GirVyvod();

    cout << "\nВведите элемент гирлянды, чью висюльку будем изменять:\n";
    cin >> elGir;
    cout << "Введите элемент висюльки, который удаляется:\n";
    cin >> elVis;
    //Поиск элемента elGir в гирлянде.
    Res = A.GirPoisk(elGir);
    if (Res != NULL)
    {
        //Поиск элемента elVis в висюльке.
        A.SetpheadVis((*Res).vniz);
        ResVis = A.VisPoisk(elVis);
        if ((ResVis != NULL) && ((*ResVis).vniz != NULL))
            A.Vis1Udale(ResVis);
        else  cout << "Элемента в висюльке нет или он последний!\n";
    }
    else  cout << "Элемента в гирлянде нет!\n";
    A.GirVyvod();
    A.OCHISTKA();

    cout << "\n";
    system("PAUSE");
}

void GirVis::OCHISTKA()
{
    nodeGir* q, * q1;//Рабочие указатели.
    q = phead;
    q1 = (*q).sled; //Указатель q1 "опережает" указатель q.

    while (q1 != NULL)  // Пока список не пустой.
    {
        q = q1; q1 = (*q1).sled;
        pheadVis = (*q).vniz;
        OCHISTKA1(); //Очистка висюльки.
        delete q;
    }
}

void GirVis::OCHISTKA1()
{
    nodeVis* q, * q1;
    q = pheadVis;
    //Удаляем звенья висюльки по очереди.
    q1 = (*q).vniz;
    while (q1 != NULL)
    {
        q = q1; q1 = (*q1).vniz;
        delete q;
    }
}

void GirVis::GirPostr()
//Построение однонаправленного списка с заглавным звеном,
//заданного указателем phead (построение гирлянды).
{
    nodeGir* t;
    int el;
    t = phead; (*t).sled = NULL;
    cout << "Вводите элемент гирлянды: \n";
    cin >> el;
    while (el != 0)
    {
        (*t).sled = new (nodeGir);
        t = (*t).sled; (*t).elem = el; (*t).sled = NULL;
        (*t).vniz = VisPostr();
        cout << " Вводите элемент гирлянды: \n";
        cin >> el;
    }
}

// Функция VisPostr() строит однонаправленный список для висюльки, 
// начиная с заглавного звена pheadVis.
nodeVis* GirVis::VisPostr()
{
    nodeVis* t;
    int el;
    // Создаем заглавное звено списка.
    pheadVis = new (nodeVis);
    t = pheadVis;
    (*t).vniz = NULL;
    cout << "Введите элементы звеньев висюльки: \n";
    cin >> el;
    // Вводим элементы звеньев и добавляем их в список.
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

// Функция GirVyvod() выводит содержимое гирлянды, 
// включая содержимое висюльки каждого звена.
void GirVis::GirVyvod()
{
    nodeGir* t;
    // Начинаем с первого звена после заглавного.
    t = phead;
    t = (*t).sled;
    cout << "Гирлянда: ";
    // Выводим содержимое каждого звена и его висюльки.
    while (t != NULL)
    {
        cout << (*t).elem << " ";
        pheadVis = (*t).vniz;
        VisVyvod();
        t = (*t).sled;
    }
}

// Функция GirPoisk() осуществляет поиск элемента el в списке гирлянды.
// Начинается поиск с первого элемента после заглавного звена.
// Если элемент найден, возвращает адрес звена списка, содержащего элемент el.
// Если элемент не найден, возвращает NULL.

nodeGir* GirVis::GirPoisk(int el) {
    // создаем два указателя на звенья списка
    nodeGir* t, * r;
    r = NULL; // инициализируем r значением NULL
    t = phead; // t указывает на заглавное звено гирлянды
    t = (*t).sled; // t теперь указывает на первый элемент гирлянды (после заглавного)

    // проходим по всем элементам гирлянды
    while (t != NULL && r == NULL) {
        if ((*t).elem == el) { // если нашли нужный элемент
            r = t; // запоминаем адрес звена, содержащего элемент el
        }
        else {
            t = (*t).sled; // иначе переходим к следующему звену
        }
    }
    return r; // возвращаем адрес звена, содержащего элемент el (или NULL, если элемент не найден)
}

// Функция VisVyvod() выводит содержимое однонаправленного списка для висюльки,
// заданного указателем pheadVis. Выводится содержимое висюльки в скобках.
void GirVis::VisVyvod() {
    nodeVis* t;
    t = pheadVis; // t указывает на заглавное звено списка для висюльки
    t = (*t).vniz; // t теперь указывает на первый элемент списка для висюльки

    cout << "(";
    while (t != NULL) { // пока не достигли конца списка
        cout << (*t).elem << " "; // выводим значение элемента
        t = (*t).vniz; // переходим к следующему звену списка
    }
    cout << ")";
}


// Функция VisPoisk() осуществляет поиск элемента el в списке для висюльки,
// заданном указателем pheadVis. Если элемент найден, возвращает адрес звена списка,
// содержащего элемент el. Если элемент не найден, возвращает NULL.
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
//Включение звена с информационным полем el
//после звена, на которое указывает r
//(включение звена в висюльку).
{
    nodeVis* q;

    q = new (nodeVis);
    (*q).elem = el; (*q).vniz = (*r).vniz; (*r).vniz = q;
}

void GirVis::Vis1Vstav(nodeVis* r, int el)
//Включение звена с информационным полем el
//перед звеном, на которое указывает r
//(включение звена в висюльку).
{
    nodeVis* q;

    q = new (nodeVis);
    (*q).elem = (*r).elem; (*q).vniz = (*r).vniz;
    (*r).elem = el; (*r).vniz = q;
}

void GirVis::VisUdale(nodeVis* r)
//Удаление звена, расположенного после звена,
//на которое указывает ссылка r
//(удаление звена висюльки).
{
    nodeVis* q;
    q = (*r).vniz;
    if ((*r).vniz != NULL)
    {
        (*r).vniz = (*(*r).vniz).vniz; delete q;
    }
    else  cout << "Звено с заданным элементом - последнее!\n";
}

void GirVis::Vis1Udale(nodeVis* r)
//Удаление звена, на которое указывает ссылка r
//(удаление звена висюльки).
{
    nodeVis* g;

    if ((*r).vniz != NULL)
    {
        g = (*r).vniz;
        (*r).elem = (*(*r).vniz).elem;
        (*r).vniz = (*(*r).vniz).vniz;
        delete g;
    }
    else  cout << "Не умею удалять последнее звено!\n";
}
