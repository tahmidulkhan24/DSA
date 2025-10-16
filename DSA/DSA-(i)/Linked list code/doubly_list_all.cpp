#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node *pre;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
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
    if (head == NULL)
    {
        head = tmp;
        tail = tmp;

        return;
    }
    tmp->next = head;
    head->pre = tmp;
    tmp->pre = NULL;
    head = tmp;
}
void insertTail(int v)
{
    node *tmp = new node(v);
    if (tail == NULL)
    {
        head = tmp;
        tail = tmp;

        return;
    }
    tmp->pre = tail;
    tail->next = tmp;
    tail = tmp;
    tail->next = NULL;
}
void print()
{
    node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
bool find(int v)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->val == v)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}
void insertAtPos(int v, int pos)
{
    node *newnode = new node(v);
    node *tmp = head;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }
    newnode->pre = tmp;
    newnode->next = tmp->next;
    newnode->next->pre = newnode;
    tmp->next = newnode;
}
void deleteHead()
{
    if(head==NULL)
    {
        return;
    }
    node *tmp = head;
    head = head->next;
    head->pre = nullptr;
    free(tmp);
}
void deleteTail()
{
    if (tail == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteHead();
    }
    node *tmp=tail;
    tail=tail->pre;
    tail->next=NULL;
    free(tmp);
    
}

bool deleteAny(int v)
{
    if(find(v)==false)
    {
        return false;
    }
    if(head->val==v)
    {
        deleteHead();
        return true;
    }
    if(tail->val==v)
    {
        deleteTail();
        return true;
    }
    node *slow=NULL;
    node *fast=head;
    while(fast->val!=v)
    {
        slow=fast;
        fast=fast->next;
    }
    slow->next=fast->next;
    fast->next->pre=slow;
    free(fast);
    return true;
}
int main()
{
    init();

    while (1)
    {
        cout << "1.Insert head\n2.Insert tail\n3.Print\n4.wanna find?\n5.inser at pos\n6.delete head?\n7.detete tail?\n8.Delete any val?" << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "enter the value: ";
            int v;
            cin >> v;
            insertHead(v);
        }
        if (x == 2)
        {
            cout << "enter value: ";
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
            cout << "enter value: ";
            int v;
            cin >> v;

            if (find(v))
            {
                cout << v << " found" << endl;
            }
            else
            {
                cout << " Not found" << endl;
            }
        }
        if (x == 5)
        {
            cout << "enter value and pos: ";
            int v, pos;
            cin >> v >> pos;
            if (pos == 0)
            {
                insertHead(v);
            }
            insertAtPos(v, pos);
        }
        if (x == 6)
        {
            deleteHead();
        }
         if (x == 7)
        {
            deleteTail();
        }
        if (x == 8)
        {
            cout << "enter value which want to delete: ";
            int v;
            cin >> v;
            if(deleteAny(v))
            {
                cout<<"delete done"<<endl;
                print();
            }
            else
            {
            cout<<"delete faild"<<endl;
            }
        }
        cout << endl
             << endl;
    }
    return 0;
}