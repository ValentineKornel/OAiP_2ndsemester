#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class MobileOperator {
public:
    struct Node {
        std::string name;
        std::string phone;
        std::string tariff;
        Node* left;
        Node* right;

        Node(const std::string& name, const std::string& phone, const std::string& tariff)
            : name(name), phone(phone), tariff(tariff), left(nullptr), right(nullptr) {}
    };

    MobileOperator() : root(nullptr) {}

    ~MobileOperator() {
        clear(root);
    }

    void add(const std::string& name, const std::string& phone, const std::string& tariff) {
        root = addRecursive(root, name, phone, tariff);
    }

    void display() {
        displayRecursive(root, 0);
    }

    Node* findOwner(const std::string& phone) {
        Node* current = root;
        while (current != nullptr) {
            if (current->phone == phone) {
                return current;
            }
            else if (phone < current->phone) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return nullptr;
    }

    std::string mostPopularTariff() {
        std::unordered_map<std::string, int> tariffCount;
        countRecursive(root, tariffCount);

        std::string mostPopular;
        int maxCount = 0;

        for (const auto& pair : tariffCount) {
            if (pair.second > maxCount) {
                mostPopular = pair.first;
                maxCount = pair.second;
            }
        }

        return mostPopular;
    }

    void countRecursive(Node* node, std::unordered_map<std::string, int>& tariffCount) {
        if (node) {
            countRecursive(node->left, tariffCount);
            tariffCount[node->tariff]++;
            countRecursive(node->right, tariffCount);
        }
    }


private:
    Node* root;

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    Node* addRecursive(Node* node, const std::string& name, const std::string& phone, const std::string& tariff) {
        if (!node) {
            node = new Node(name, phone, tariff);
        }
        else if (phone < node->phone) {
            node->left = addRecursive(node->left, name, phone, tariff);
        }
        else if (phone > node->phone) {
            node->right = addRecursive(node->right, name, phone, tariff);
        }
        return node;
    }

    void displayRecursive(Node* node, int level) {
        if (node) {
            displayRecursive(node->right, level + 1);
            std::cout << std::string(level * 4, ' ') << node->name << " (+" << node->phone << ") - " << node->tariff << std::endl;
            displayRecursive(node->left, level + 1);
        }
    }
};

int main() {
    MobileOperator mobileOperator;
    int choice;

    while (1)
    {
        int numRight = 0;
        cout << "\n";
        cout << "1 - Add element;\n";
        cout << "2 - Display the tree;\n";
        cout << "3 - To search by the phone;\n";
        cout << "4 - The most popular tariff;\n";
        cout << "0 - exit;\n";
        cout << "Your choise: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
        {
            string name, number, tariff;
            cout << "Enter name: ";
            cin.get();
            getline(cin, name);
            bool flag = false;
            while (!flag) {
                flag = true;
                cout << "\nEnter number: " << "+";
                getline(cin, number);
                for (int i = 0; i < number.size(); i++) {
                    if (number[i] > '9' or number[i] < '0' or number.size() > 12) {
                        cout << "Incorrect input" << endl;
                        flag = false;
                        break;
                    }
                }
            }
            cout << "\nEnter tafir: ";
            getline(cin, tariff);
            mobileOperator.add(name, number, tariff);
            break;
        }

        case 2:
        {
            mobileOperator.display();
            break;
        }

        case 3:
        {
            string phone;
            cout << "Enter the phone number to search: +";
            cin.get();
            getline(cin, phone);
            MobileOperator::Node* owner = mobileOperator.findOwner(phone);
            if (owner) {
                std::cout << "Owner of phone +" << phone << ": " << owner->name << std::endl;
            }
            else {
                std::cout << "Phone +" << phone << " is not registered with the mobile operator." << std::endl;
            }
            break;
        }

        case 4:
        {
            cout << "The most popular tariff is " << mobileOperator.mostPopularTariff();
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }

        default:
        {
            cout << "Incorrect input. Your chouise?.\n";
            break;
        }

        }
    }
    return 0;
}