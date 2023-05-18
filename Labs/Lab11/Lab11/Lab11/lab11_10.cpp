#include <iostream>
#include <stdlib.h>
using namespace std;
struct Tree  //������
{
	int key; //����
	char text[10]; //����� - �� ����� 4 ����
	Tree* Left, * Right;
};

float sum2 = 0;

Tree* makeTree(Tree* Root);       //�������� ������
Tree* list(int i, char* s);       //�������� ������ ��������
Tree* insertElem(Tree* Root, int key, char* s);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
void view(Tree* t, int level);    //����� ������ 
void delAll(Tree*& t);             //������� ������
float sum(Tree* t, int level);
Tree* vershinyk(Tree* t, int key);

int number_of_odd_tops = 0;
int amount_of_elements = 1;
int lev = 1;
Tree* Root = NULL; 	//��������� �����

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

Tree* makeTree(Tree* Root)    //�������� ������
{
	int key; char s[10];
	cout << "to finig input enter any negative nubmer\n\n";
	if (Root == NULL)	// ���� ������ �� �������
	{
		cout << "Input the key: "; cin >> key;
		cout << "Input the element: "; cin >> s;
		Root = list(key, s);	// ��������� ��������� �� ������
	}
	while (1)                //���������� ���������
	{
		cout << "\nInput the key: "; cin >> key;
		if (key < 0) break; //������� ������ (���� < 0) 
		if (key % 2 == 0) { number_of_odd_tops++; }
		cout << "Input the element: ";  cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}

Tree* list(int i, char* s)     //�������� ������ ��������
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < 5; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, char* s)  //���������� ������ ��������
{
	Tree* Prev = new Tree[sizeof(Tree)]; // Prev - ������� ����� �������
	int find = 0;        // ������� ������
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
		{
			find = 1;	   //����� ������ ���� ���������
			cout << "INCORRECT KEY!!!" << endl;
		}
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //������� ����� � ������� Prev
	{
		amount_of_elements++;
		t = list(key, s);           //��������� ����� ���� 
		if (key < Prev->key) {
			// � �������������� ���� 
			Prev->Left = t;    //������� �� ����� �����,
			lev++;
		}
		else
			Prev->Right = t;   // ���� �� ������ 
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\nThe key wasn't founded");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� ����� 
		else
			Prev_Del->Right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\nThe key of the deleted element is " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //����� �������� �� ����� 
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


float sum(Tree* t, int level) //�������
{
	float sum1;
	if (t)
	{
		sum(t->Right, level + 1);	//����� ������� ���������	
		sum1 = atof(t->text);
		sum2 += sum1;
		sum(t->Left, level + 1);	//����� ������ ���������
	}
	return sum2;
}


void view(Tree* t, int level) //����� ������ 
{
	if (t == nullptr) {
		return;
	}
	if (t)
	{
		view(t->Right, level + 1);	//����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << '(' << tm << ')' << ' ';
		puts(t->text);
		view(t->Left, level + 1);	//����� ������ ���������
	}
}

void delAll(Tree*& t) //������� ������
{
	if (t)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
		t = nullptr;
	}
}