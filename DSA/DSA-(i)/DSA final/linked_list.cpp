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
void insertHead(v)
{
    
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