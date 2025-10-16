#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *next;
    Node(int key)
    {
        this->key = key;
        this->next = NULL;
    }
};

class Mystack
{
public:
    Node *head = NULL;
    int sz = 0;

    void push(int val)
    {
        Node *tmp = new Node(val);
        tmp->next = head; // Insert at the head for stack behavior
        head = tmp;
        sz++;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "stack empty" << endl;
            return;
        }
        Node *tmp = head;
        head = head->next;
        delete tmp; // Correctly deallocate memory
        sz--;
    }

    void top()
    {
        if (head == NULL)
        {
            cout << "stack empty" << endl;
            return;
        }
        cout << head->key << endl;
    }
};

int main()
{
    Mystack s;
    int n;
    while (1)
    {
        cout << "1.push\n2.pop\n3.top\n4.exit" << endl;
        cin >> n;
        if (n == 1)
        {
            int val;
            cin >> val;
            s.push(val);
        }
        else if (n == 2)
        {
            s.pop();
        }
        else if (n == 3)
        {
            s.top();
        }
        else
        {
            break;
        }
    }
    return 0;
}