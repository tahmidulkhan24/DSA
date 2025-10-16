#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    Node *next;
    Node *pre;
    Node(int key)
    {
        this->key = key;
        this->next = NULL;
        this->pre = NULL;
    }
};
Node *head;
Node *tail;
int sz = 0;
void init()
{
    head = NULL;
    tail = NULL;
}
void insertHead(int val)
{
    Node *tmp = new Node(val);
    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
        return;
    }
    tmp->next = head;
    tmp->pre = NULL;
    head->pre = tmp;
    head = tmp;
}
void insertTail(int val)
{
    Node *tmp = new Node(val);
    if (tail == NULL)
    {
        head = tmp;
        tail = tmp;

        return;
    }
    tmp->pre = tail;
    tmp->next = NULL;
    tail->next = tmp;
    tail = tmp;
}
void print(Node *tmp)
{
    if (tmp == NULL)
    {
        return;
    }
    cout << tmp->key << " ";
    print(tmp->next);
}
void print_rev(Node *tmp)
{

    if (tmp == NULL)
    {
        return;
    }
    print_rev(tmp->next);
    cout << tmp->key << " ";
}
Node *find(int val)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->key == val)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return tmp;
}
void insertAtPos(int val, int pos)
{
    if (pos < 0 || pos > sz)
    {
        cout << "invalid" << endl;
        return;
    }
    if (pos == 0)
    {
        insertHead(val);
        return;
    }
    if (pos == sz)
    {
        insertTail(val);
        return;
    }
    Node *newnode = new Node(val);
    Node *tmp = head;
    for (int i = 0; i < pos; i++)
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
    if (head == NULL)
    {
        return;
    }
    Node *tmp = head;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    else
        head->pre = NULL;
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
    Node *tmp = tail;
    tail = tail->pre;
    tail->next = nullptr;

    free(tmp);
}
bool deleteByPos(int pos)
{
    if (pos < 0 || pos >= sz) {
        cout << "Invalid position!" << endl;
        return false;
    }

    if (pos == 0) {
        deleteHead();
        return true;
    }

    if (pos == sz - 1) {
        deleteTail();
        return true;
    }

    Node *tmp = head;
    for (int i = 0; i < pos; i++) {
        tmp = tmp->next;
    }

    tmp->pre->next = tmp->next;
    tmp->next->pre = tmp->pre;
    free(tmp);
    return true;
}
Node *find_first_occ(int val)
{
    Node *tmp=head;
    while(tmp!=NULL)
    {
        if(tmp->key==val)
        {
            return tmp;
        }
        tmp=tmp->next;
    }
    return tmp;
}
Node *find_last_occ(int val)
{
    Node *tmp=tail;
    while(tmp!=NULL)
    {
        if(tmp->key==val)
        {
            return tmp;
        }
        tmp=tmp->pre;
    }
    return tmp;
}
void insertAfterAny(Node *curr, int val) {
    if (curr == NULL) return;  // Safety check

    Node *newnode = new Node(val);
    newnode->next = curr->next;
    newnode->pre = curr;

    if (curr->next != NULL)  // Only update if next exists
        curr->next->pre = newnode;

    curr->next = newnode;

    // Optional: if curr was tail, update global tail pointer
    if (curr == tail)
        tail = newnode;

    sz++;
}
void deleteanyocc(Node *curr)
{
     curr->next->pre=curr->pre;
     curr->pre->next=curr->next;
     free(curr);
}
bool deleteDuplicate()
{
    for(Node *i=head;i!=NULL;i=i->next)
    {
        int key=i->key;
        for(Node *j=i->next;j!=NULL;j=j->next)
        {
            if(j->key==key)
            {
                Node *tmp=j;
                j=j->next;
                if(tmp==tail) deleteTail();
                else deleteanyocc(tmp);
            }
            if(j==NULL) break;
      
        }
        if(i==tail) break;
    }
}
void booble_sort()
{
    for (Node *i = head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->key > j->key)
            {
                int temp = i->key;
                i->key = j->key;
                j->key = temp;
            }
        }
    }
    print(head);
}
Node *find_kth(int k)
{
    Node *tmp=head;
    int cnt=1;
    while(cnt!=k)
    {
        tmp=tmp->next;
        cnt++;
    }
    return tmp;
}
int find_middle()
{
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        if(fast!=NULL) slow=slow->next;
    }
    return slow->key;
}
void cut_paste(int k)
{
    Node *fast=head;
    Node *last=find_kth(k);
    last->next->pre=NULL;
    last->next=head;
    last->next=NULL;
    tail->next=fast;
    fast->pre=tail;
    tail=last;

}
int main()
{
    init();
    while (1)
    {
        cout << "1.Insert head\n2.Insert tail\n3.Print\n4.wanna find?\n5.print reverse?\n6.insert at pos\n"
             << "7.size?\n8.delete head\n9.delete tail\n10.delete any?" << endl
             << "11. find first occurance" << endl
             << "12. find last occurance" << endl
             << "13. insert after first or last occurance" << endl
             << "14. delete first occurance" << endl
             << "15. delete last occurance" << endl
             << "16. delete duplicate" << endl
             << "17. sort and print" << endl
             << "18. find kth node" << endl
             << "19. cut paste" << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "enter the value";
            int v;
            cin >> v;
            insertHead(v);
            sz++;
        }
        if (x == 2)
        {
            cout << "enter value:";
            int v;
            cin >> v;
            insertTail(v);
            sz++;
        }
        if (x == 3)
        {
            print(head);
        }
        if (x == 4)
        {
            cout << "enter value:";
            int v;
            cin >> v;
            Node *found = find(v);
            if (found == NULL)
            {
                cout << v << " Not found" << endl;
            }
            else
            {
                cout << "found,value is:" << found->key << endl;
            }
        }
        if (x == 5)
        {
            print_rev(head);
        }
        if (x == 6)
        {
            int pos, val;
            cin >> pos >> val;
            insertAtPos(val, pos);
            sz++;
        }
        if (x == 7)
        {
            cout << sz << endl;
        }
        if (x == 8)
        {
            deleteHead();
            sz--;
        }
        if (x == 9)
        {
            deleteTail();
            sz--;
        }
        if (x == 10)
        {
            int pos;
            cin >> pos;
            if(deleteByPos(pos))
            {
                cout<<"succesfully delete"<<endl;
            }
            else
            {
                cout<<"not delete"<<endl;
            }
            sz--;
        }
        if (x == 11)
        {
            int val;
            cin >> val;
           Node *fn=find_first_occ( val);
           if(fn==NULL)
           {
            cout<<"not found"<<endl;
           }
           else
           {
            cout<<"found"<<endl;
            sz++;
           } 
        }
        if (x == 12)
        {
            int val;
            cin >> val;
           Node *fn=find_last_occ( val);
           if(fn==NULL)
           {
            cout<<"not found"<<endl;
           }
           else
           {
            cout<<"found"<<endl;
            sz++;
           } 
        }
        if (x == 13)
        {
            int key, val;
            cin >> key >> val;
            Node *curr=find_first_occ(key);
            if(curr!=NULL)
            {
                insertAfterAny(curr,val);
               sz++;
            }
        }
        if (x == 14)
        {
            int  val;
            cin >>  val;
            Node *curr=find_first_occ(val);
            if(curr==NULL)
            {
               cout<<"not possible"<<endl;
            }
            else if(curr==head) deleteHead();
            else if(curr==tail) deleteTail();
            else  deleteanyocc(curr);
            if(curr!=NULL) sz++;
        }
        if (x == 15)
        {
            int  val;
            cin >>  val;
            Node *curr=find_last_occ(val);
            if(curr==NULL)
            {
               cout<<"not possible"<<endl;
            }
            else if(curr==head) deleteHead();
            else if(curr==tail) deleteTail();
            else  deleteanyocc(curr);
            if(curr!=NULL) sz++;
        }
        if (x == 16)
        {
            if(deleteDuplicate())
            {
                cout<<"success"<<endl;
            }
            
        }
        if(x==17)
        {
            booble_sort();
        }
        if (x == 18)
        {
            int n;
            cin>>n;
            Node *kth=find_kth(n);
            if(kth!=NULL) cout<<kth->key<<endl;
            else cout<<"not find"<<endl;
        }
        if(x==19)
        {
            int k;
            cout << "Cut first k nodes from the begining and paste it at the end." << endl << "Enter k : ";
            cin >> k;

            if(head == NULL) cout << endl << "List is empty!" << endl;
            else if(k <= 0 or k > sz) cout << endl << "Invalid input" << endl;
            else if(k == sz) continue;
            else cut_paste(k);
        }
        cout << endl
             << endl;
    }
    return 0;
}