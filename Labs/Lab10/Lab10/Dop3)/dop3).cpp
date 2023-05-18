#include <iostream>

using namespace std;

// Структура для элемента списка
struct Node {
    string data;
    Node* next;
};

// Функция для добавления нового элемента в список
void addToCircularList(Node*& head, string data) {
    Node* newNode = new Node;
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        head->next = head;
    }
    else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
}

// Функция для вывода элементов списка
void printCircularList(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

// Функция для прохода по кольцевому списку на заданное количество шагов
void traverseCircularList(Node* head, int steps) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (steps == 0) {
        cout << head->data;
        return;
    }
    traverseCircularList(head->next, steps - 1);
}

// Функция для очистки памяти, занимаемой списком
void clearCircularList(Node*& head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    while (current->next != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete current;
    head = NULL;
}

// Главная функция
int main() {
    Node* head = NULL;
    int n;
    string data;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        addToCircularList(head, data);
    }
    cout << "Circular list: ";
    printCircularList(head);
    int steps;
    cout << "Enter n: ";
    cin >> steps;
    cout << "Elements after " << 26 + steps << " steps is ";
    traverseCircularList(head, 25 + steps);
    clearCircularList(head);
    return 0;
}
