#include <iostream>
#include <stdlib.h>
using namespace std;
struct Tree  //дерево
{
	int key; //ключ
	char text[10]; //текст - не более 4 букв
	Tree* Left, * Right;
};

float sum2 = 0;

Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i, char* s);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key, char* s);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
void delAll(Tree*& t);             //Очистка дерева
float sum(Tree* t, int level);
Tree* vershinyk(Tree* t, int key);

int number_of_odd_tops = 0;
int amount_of_elements = 1;
int lev = 1;
Tree* Root = NULL; 	//указатель корня

void main()
{
	int key = 0, choice, n;
	Tree* rc; char s[10], letter;

	for (;;)
	{
		if (Root != NULL)
			view(Root, 0);
		else
			cout << "The tree is empty" << endl;
		cout << endl;
		cout << "1 - to create a tree\n";
		cout << "2 - to add an element\n";
		cout << "3 - serach by the key\n";
		cout << "4 - to delete an element\n";
		cout << "5 - 10 variant: count the summ of all the elements of the tree\n";
		cout << "6 - 12 variant: count number of the odd tops\n";
		cout << "7 - 14 varinat: count the average of all the elements of the tree\n";
		cout << "8 - 5 variant : count numer of the left daughter tops (not including the root)\n";
		cout << "9 - to clean the tree\n";
		cout << "0 - exit\n";
		cout << "Your choise?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1: {
			Root = makeTree(Root);
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			cout << "\nInput the key: "; cin >> key;
			if (key % 2 == 0) { number_of_odd_tops++; }
			cout << "Input the element: "; cin >> s;
			insertElem(Root, key, s);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "\nInput the key: ";  cin >> key;
			rc = search(Root, key);
			cout << "Founed element = ";
			puts(rc->text);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "\nInput key of the element to delete: "; cin >> key;
			Root = delet(Root, key);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			sum2 = 0;
			cout << "Sum of all the elements: " << sum(Root, 0) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			cout << "Amount of elements with odd tops " << number_of_odd_tops << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			sum2 = 0;
			float aver = sum(Root, 0) / amount_of_elements;
			sum2 = 0;
			cout << "Sum: " << sum(Root, 0) << endl;
			cout << "Amount: " << amount_of_elements << endl;
			cout << "Average of all the elements of the tree : " << aver << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: {
			cout << "Number of the left dougther tops (not includeing the root): " << (lev - 1) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 9:  delAll(Root); break;
		case 0:  exit(0);
		}
	}
}

Tree* makeTree(Tree* Root)    //Создание дерева
{
	int key; char s[10];
	cout << "to finig input enter any negative nubmer\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Input the key: "; cin >> key;
		cout << "Input the element: "; cin >> s;
		Root = list(key, s);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "\nInput the key: "; cin >> key;
		if (key < 0) break; //признак выхода (ключ < 0) 
		if (key % 2 == 0) { number_of_odd_tops++; }
		cout << "Input the element: ";  cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}

Tree* list(int i, char* s)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < 5; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, char* s)  //Добавление нового элемента
{
	Tree* Prev = new Tree[sizeof(Tree)]; // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
		{
			find = 1;	   //ключи должны быть уникальны
			cout << "INCORRECT KEY!!!" << endl;
		}
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		amount_of_elements++;
		t = list(key, s);           //создается новый узел 
		if (key < Prev->key) {
			// и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
			lev++;
		}
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nThe key wasn't founded");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nThe key of the deleted element is " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "The element wasn't founded\n";
	return rc;
}


float sum(Tree* t, int level) //задание
{
	float sum1;
	if (t)
	{
		sum(t->Right, level + 1);	//вывод правого поддерева	
		sum1 = atof(t->text);
		sum2 += sum1;
		sum(t->Left, level + 1);	//вывод левого поддерева
	}
	return sum2;
}


void view(Tree* t, int level) //Вывод дерева 
{
	if (t == nullptr) {
		return;
	}
	if (t)
	{
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << '(' << tm << ')' << ' ';
		puts(t->text);
		view(t->Left, level + 1);	//вывод левого поддерева
	}
}

void delAll(Tree*& t) //Очистка дерева
{
	if (t)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
		t = nullptr;
	}
}