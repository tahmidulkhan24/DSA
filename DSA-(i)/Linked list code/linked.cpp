#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int key;
    node *next;
    node(int key)
    {
        this->key = key;
        this->next = next;
    }
};
node *head, *tail;
void init()
{
    head = NULL;
    tail = NULL;
}
void insertHead(int v)
{
    node *tmp = new node(v);
    // tmp->key = v;
    tmp->next = head;
    head = tmp;
    if (tail == NULL)
    {
        tail = head;
    }
}
void insertTail(int v)
{
    node *tmp = new node(v);
    if (tail != NULL)
        tail->next = tmp;
    tail = tmp;
    tail->next = NULL;
    if (head == nullptr)
    {
        head = tail;
    }
}

void print()
{
    node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->key << " ";
        tmp = tmp->next;
    }
}
node *find(int v)
{
    node *tmp = head;
    while (tmp != NULL)
    {

        if (tmp->key == v)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return tmp;
}
int main()
{
    init();

    while (1)
    {
        cout << "1.Insert head\n2.Insert tail\n3.Print\n4.wanna find?" << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "enter the value";
            int v;
            cin >> v;
            insertHead(v);
        }
        if (x == 2)
        {
            cout << "enter value:";
            int v;
            cin >> v;
            insertTail(v);
        }
        if (x == 3)
        {
            print();
        }
        if (x == 4)
        {
            cout << "enter value:";
            int v;
            cin >> v;
            node *found = find(v);
            if (found == NULL)
            {
                cout << v << " Not found" << endl;
            }
            else
            {
                cout << "found" << endl;
            }
        }
        cout << endl
             << endl;
    }

    return 0;
}