#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *L, *R;
};

Node *head, *tail;

void insertAtLast(int x)
{
    Node *n = (Node *)malloc(sizeof(Node));

    n->key = x;
    n->L = NULL;
    n->R = NULL;

    if (head == NULL)
    {
        head = n;
        tail = n;
        return;
    }

    tail->R = n;
    n->L = tail;
    tail = n;
}

void print()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->R;
    }

    cout << endl;
}

Node *findFirstOccurrence(int x)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->key == x)
            return temp;
        temp = temp->R;
    }

    return NULL;
}

void deleteHead()
{
    if (head == NULL)
        return;

    Node *tmp = head;
    head = head->R;

    if (head != NULL)
        head->L = NULL;
    else
        tail = NULL;

    free(tmp);
}

void deleteTail()
{
    if (tail == NULL)
        return;

    Node *tmp = tail;
    tail = tail->L;

    if (tail != NULL)
        tail->R = NULL;
    else
        head = NULL;

    free(tmp);
}

void deleteMax()
{
    Node *tmp = head;
    Node *tmp2 = head;
    Node *mx = NULL;
    int max = INT_MIN;
    while (tmp != NULL)
    {
        if (tmp->key > max)
        {
            max = tmp->key;
            mx = tmp;
        }
        tmp = tmp->R;
    }
    if (head->key == max)
    {
        deleteHead();
    }
    if (tail->key == max)
    {
        deleteTail();
    }

    Node *slow = NULL;
    Node *fast = head;
    while (fast != NULL)
    {
        if (fast->key != max)
        {
            slow = fast;
            fast = fast->R;
        }
        else
        {
            tmp2 = fast;
            fast = fast->R;
            slow->R = fast;
            fast->L = slow;
            free(tmp2);
        }
    }
}

void findAllPairs(int x)
{
    int vis[101] = {0};

    for (Node *i = head; i != NULL; i = i->R)
    {
        int v = x - i->key;

        if (v >= 0 && v <= 100 && vis[v] == 1)
        {
            cout << v << "," << i->key << endl;
            vis[v] = 0;
            vis[i->key] = 0;
        }
        else if (vis[i->key] == 0)
        {
            vis[i->key] = 1;
        }
    }
}

int main()
{

    head = NULL;
    tail = NULL;

    cout << "1. Insert at last" << endl
         << "2. Find first occurrence" << endl
         << "3. Print" << endl
         << "4. Delete Max" << endl
         << "5. Find all pair" << endl
         << endl;

    while (1)
    {
        int choice;
        cout << "Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter value: ";
            int x;
            cin >> x;
            insertAtLast(x);
            cout << x << " is inserted!" << endl;
        }
        else if (choice == 3)
        {
            print();
            cout << endl;
        }
        else if (choice == 4)
        {
            if (head == NULL)
                continue;
            else
                deleteMax();
            print();
        }
        else if (choice == 5)
        {
            cout << "Enter a number :";
            int num;
            cin >> num;

            findAllPairs(num);
        }
        else
        {
            break;
        }

        cout << endl;
    }
}

/*
Input
1 17
1 4
1 2
1 15
1 2
1 5
1 13
1 10
1 17
1 7
1 10
*/