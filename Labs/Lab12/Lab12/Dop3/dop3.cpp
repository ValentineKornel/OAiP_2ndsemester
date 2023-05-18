#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <stack>
using namespace std;

class node {

public:

    int key;

    node* left;
    node* right;
    node* parent;

    bool color;

    node(int k, bool c = true) //a node is default created as red
    {
        key = k;
        left = NULL;
        right = NULL;
        color = c; //true=red and false=black
        parent = NULL;
    }
};

class rbtree {

public:

    node* root; //notice pointer!

    rbtree()
    {
        root = NULL;
    }

    void ins(int); //wrapper
    void ins(int, node*);
    void insfixup(node*);

    void leftrotate(node*);
    void rightrotate(node*);

    node* insuccessor(node*);

    void del(int);
    void del(node*);
    void delfixup(node*, bool flag = false);

    int count_red_on_path_to_leaf();

    node* searchh(int);
    node* searchh(int, node*);

};


void rbtree::ins(int k)
{
    if (root == NULL)
    {
        root = new node(k, false);
        return;
    }
    else
        ins(k, root);
}

void rbtree::ins(int k, node* cur)
{
    if (root == NULL)
    {
        root = new node(k, false);
        return;
    }

    if (cur->key < k)
    {
        if (cur->right == NULL)
        {
            cur->right = new node(k);
            cur->right->parent = cur;

            insfixup(cur->right);
        }
        else
            ins(k, cur->right);
    }
    else if (cur->key > k)
    {
        if (cur->left == NULL)
        {
            cur->left = new node(k);
            cur->left->parent = cur;

            insfixup(cur->left);
        }
        else
            ins(k, cur->left);
    }
}

int dfs(node* cur, int count)
{
    //если текущая вершина - лист, вернуть 0 или 1, если она красная
    if (cur == NULL)
        return count;
    if (cur->left == NULL && cur->right == NULL)
        return cur->color ? count + 1 : count;

    //рекурсивно вызываем функцию для левого и правого поддерева
    int left = dfs(cur->left, cur->color ? count + 1 : count);
    int right = dfs(cur->right, cur->color ? count + 1 : count);

    //возвращаем минимальное количество красных вершин на пути к листу
    return min(left, right);
}

int rbtree::count_red_on_path_to_leaf()
{
    return dfs(root, 0);
}


void rbtree::insfixup(node* z)
{
    node* uncle = NULL;
    node* parent = NULL;
    node* grandparent = NULL;

    if (z->parent != NULL)
        parent = z->parent;

    if (parent != NULL)
        grandparent = parent->parent;

    //z always points to a red node. violations exists as long as parent is red also
    while (parent != NULL && parent->color) //red=true
    {
        if (parent == grandparent->left)
            uncle = grandparent->right;

        else
            uncle = grandparent->left;

        if (uncle != NULL && uncle->color) //if uncle is red, just recolor
        {
            uncle->color = false;
            parent->color = false;
            grandparent->color = true;

            z = grandparent; //to continue the loop
        }

        else //uncle is black, either because it is NULL or it is actually a node with color black
        {
            if (z == parent->left)
            {
                if (uncle == grandparent->right) //line case
                {
                    rightrotate(grandparent);
                    parent->color = false;
                    grandparent->color = true;
                }
                else //triangle case, which will reduce to line case
                {
                    rightrotate(parent);
                    z = parent;
                }
            }

            else
            {
                if (uncle == grandparent->right) //triangle case
                {
                    leftrotate(parent);
                    z = parent;
                }
                else //line case
                {
                    leftrotate(grandparent);
                    parent->color = false; //or parent->color = !parent->color
                    grandparent->color = true;
                }
            }
        }

        //to continue the loop. by now, the new z for the next iteration has been set
        parent = z->parent;

        if (parent != NULL)
            grandparent = parent->parent;
    }

    //root case
    if (root->color)
        root->color = false;
}


void rbtree::leftrotate(node* x)
{
    node* y = x->right;

    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL) //that is, x was the root
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}


void rbtree::rightrotate(node* x)
{
    node* y = x->left;

    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;
    x->parent = y;
}


node* rbtree::insuccessor(node* cur)
{
    if (cur == NULL)
        return NULL;
    if (cur->left == NULL) //the node we need
        return cur;
    else
        return insuccessor(cur->left);
}


node* rbtree::searchh(int k)
{
    return(searchh(k, this->root));
}



node* rbtree::searchh(int k, node* cur)
{
    if (cur == NULL)
    {
        cout << "The element wasn't founded" << endl;
        return NULL;
    }

    if (cur->key == k)
    {
        
        cout << "founded element is ";
        cout << cur->key << endl;
        return cur;
    }

    else if (cur->key < k)
    {
        return searchh(k, cur->right);
    }

    else return searchh(k, cur->left);
}



void rbtree::del(int k)
{
    node* cur = searchh(k);
    del(cur);
}


void rbtree::del(node* cur)
{
    node* x = nullptr; //double-black kid


    if (cur == NULL)
    {
        return;
    }

    if (cur->left != NULL && cur->right != NULL)
    {
        node* succ = insuccessor(cur->right);
        cur->key = succ->key;

        cur = succ; //so succ is to be deleted now
    }

    bool flag = cur->color;
    //above case can also fall into the below cases
    if (cur->left == NULL && cur->right == NULL)
    {

        if (!flag)
            x = NULL;

        if (cur == root)
            root = NULL;
        else
        {
            if (cur == cur->parent->left)
                cur->parent->left = NULL;
            else
                cur->parent->right = NULL;
        }
    }

    else if (cur->left == NULL)
    {
        if (!flag) //doubleblack kid is needed only if a black node is being deleted.
            x = cur->right;

        cur->right->parent = cur->parent;

        if (cur == root)
            root = cur->right;
        else
        {
            if (cur == cur->parent->left)
                cur->parent->left = cur->right;
            else
                cur->parent->right = cur->right;
        }
    }
    else
    {
        if (!flag)
            x = cur->left;

        cur->left->parent = cur->parent;

        if (cur == root)
            root = cur->left;
        else
        {
            if (cur == cur->parent->left)
                cur->parent->left = cur->left;
            else
                cur->parent->right = cur->left;
        }
    }

    node* parent = cur->parent;
    delete(cur);

    if (!flag) //if node deleted was black
    {
        if (x == NULL)
            delfixup(parent, true); //note which parameter is being sent
        else
            delfixup(x);
    }
}



void rbtree::delfixup(node* x, bool flag) //flag to check if doubleblack is a null node or not
{
    //x will always point to a double black node except when flag is true
    //loop runs as long as double-black node exists
    //break out of loop for terminating cases

    node* sibling = NULL;
    node* parent = NULL;

    if (flag)
    {
        parent = x;
        x = NULL;  //update
    }
    else
        parent = x->parent;

    //if the doubleblack node is NULL => flag is true. if doubleblack node is not NULL, usual conventions follow - x is doubleblack and parent is x->parent
    while (x != root)
    {
        //update parent when x is updated. if x is not being updated, parent doesn't need to either, so no need of a parent update at the beginning of every while loop
        if (x == parent->left)
        {
            sibling = parent->right;

            if (sibling != NULL && sibling->color) //sibling is red
            {
                parent->color = true;
                sibling->color = false;

                leftrotate(parent);
            }

            else //sibling is black
            {
                if (sibling->right != NULL && sibling->right->color) //sibling's right child is red
                {
                    leftrotate(parent);

                    //swap colors of parent and sibling
                    bool temp;
                    temp = parent->color;
                    parent->color = sibling->color;
                    sibling->color = temp;

                    sibling->right->color = false;

                    break; //terminating case
                }

                else if (sibling->left != NULL && sibling->left->color) //sibling's left child is red and right child is black
                {
                    //recolor
                    sibling->color = true;
                    sibling->left->color = false;

                    rightrotate(sibling);
                }

                else //sibling's both kids are black
                {
                    sibling->color = true;

                    if (parent->color)
                    {
                        parent->color = false;
                        break; //terminating case
                    }
                    else
                    {
                        x = parent; //continue to solve violation
                        parent = x->parent;

                        flag = false; //update! x is no longer NULL
                    }
                }
            }
        }

        else
        {
            sibling = parent->left;

            if (sibling != NULL && sibling->color) //sibling is red
            {
                parent->color = true;
                sibling->color = false;

                rightrotate(parent);
            }

            else //sibling is black
            {
                if (sibling->left != NULL && sibling->left->color) //sibling's left child is red
                {
                    rightrotate(parent);

                    //swap colors of parent and sibling
                    bool temp;
                    temp = parent->color;
                    parent->color = sibling->color;
                    sibling->color = temp;

                    sibling->left->color = false;

                    break; //terminating case
                }

                else if (sibling->right != NULL && sibling->right->color) //sibling's right child is red and left child (existing or NULL) is black
                {
                    //recolor
                    sibling->color = true;
                    sibling->right->color = false;

                    leftrotate(sibling);
                }

                else //sibling's both kids are black
                {
                    sibling->color = true;

                    if (parent->color) //if parent is red
                    {
                        parent->color = false;
                        break; //terminating case
                    }
                    else
                    {
                        x = parent; //continue to solve violation; doubleblack is propagated upwards
                        parent = x->parent;

                        flag = false;
                    }
                }
            }
        }
    }//end of while

    //root case
    if (x == root && x != NULL)
        x->color = false;
}

void tester(node* cur, int level)
{
    if (cur == nullptr) {
        return;
    }
    if (cur) {
        tester(cur->right, level + 1);
        for (int i = 0; i < level; i++)
            cout << " -";
        cout << cur->key << '(' << cur->color << ')' << endl;
        tester(cur->left, level + 1);
    }
}


void addLeavesToVector(node* cur, vector<int>& leaves)
{
    if (cur == NULL) {
        return;
    }

    if (cur->right == NULL and cur->left == NULL)
        leaves.push_back(cur->key);
    addLeavesToVector(cur->right, leaves);
    addLeavesToVector(cur->left, leaves);
}

int number_of_red_tops = 0;

int countRedTops(int k, node* cur)
{
    if (cur == NULL)
    {
        cout << "The element wasn't founded" << endl;
        return NULL;
    }

    if (cur->key == k)
    {
        if (cur->color == 1)
            number_of_red_tops++;

        cout << "The leaf: ";
        cout << cur->key << endl;
        return number_of_red_tops;
    }

    else if (cur->key < k)
    {
        if (cur->color == 1)
            number_of_red_tops++;
        return countRedTops(k, cur->right);
    }

    else { 
        if (cur->color == 1)
            number_of_red_tops++;
        return countRedTops(k, cur->left);
    }
}

rbtree T1;

void search_and_print_path(int k) {
    stack<int> path; // стек для хранения пути до элемента
    node* cur = T1.searchh(k); // ищем элемент
    if (cur == NULL) {
        cout << "Element " << k << " not found in the tree." << endl;
        return;
    }
    while (cur != NULL) { // пока не дойдем до корня
        path.push(cur->key); // кладем ключ в стек
        cur = cur->parent;
    }
    cout << "Path to element " << k << ": ";
    while (!path.empty()) { // выводим путь из стека
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}


int main()
{
    

    int option1 = 0;

    int val;

    while (option1 != 7)
    {
        std::system("cls");
        tester(T1.root, 0);
        cout << "Pick an option\n\n" << "1 - to add an element\n2 - to delete\n3 - to serch\n4 - task\n0 - to exit\nYour choise? ";
        cin >> option1;

        switch (option1)
        {
        case 1: cout << "\n\nEnter key to insert: ";
            cin >> val;
            T1.ins(val);
            break;

        case 2: { cout << "\n\nEnter key to delete: ";
            cin >> val;
            T1.del(val);
            break;
        }
        case 3:
            int el;
            cout << "Input the element to search ";
            cin >> el;
            T1.searchh(el);
            break;
        case 4:
        {
            int min_number_of_red_tops = 999;
            int current_number_of_red_tops = 0;
            int needed_element;
            vector<int> leaves;

            addLeavesToVector(T1.root, leaves);
            cout << endl;
            for (int i = 0; i < leaves.size(); i++) {
                number_of_red_tops = 0;
                int current_number_of_red_tops = countRedTops(leaves[i], T1.root);
                cout << "Number of red tops: " << current_number_of_red_tops << endl;
                if (current_number_of_red_tops < min_number_of_red_tops)
                {
                    min_number_of_red_tops = current_number_of_red_tops;
                    needed_element = leaves[i];
                }
            }
            cout << "Element with the smallest number of red tops is " << needed_element << " and the number of red tops is " << min_number_of_red_tops;
            cout << endl;
            search_and_print_path(needed_element);
            cout << endl;

            break;
        }
        case 0:
            exit(0);
        default: break;
        }
        std::system("pause");
    }
    return 0;
}