#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *head, *tail;
int size = 0;

void init()
{
    head = NULL;
    tail = NULL;
}

void insert_at_empty_list(int val)
{
    Node * tmp = new Node(val);
    head = tmp;
    tail = tmp;
}

void insert_first(int val)
{
    Node * tmp = new Node(val);
    tmp->right = head;
    head->left = tmp;
    head = tmp;
}

void insert_last(int val)
{
    Node * tmp = new Node(val);
    tmp->left = tail;
    tail->right = tmp;
    tail = tmp;
}

Node * find_first_occurance(int val)
{
    Node * tmp = head;
    while(tmp != NULL)
    {
        if(tmp->val == val) return tmp;
        tmp = tmp->right;
    }

    return tmp;
}

Node * find_last_occurance(int val)
{
    Node * tmp = tail;
    while(tmp != NULL)
    {
        if(tmp->val == val) return tmp;
        tmp = tmp->left;
    }

    return tmp;
}

void insert_after_first_or_last_occurance(Node *ref_node, int val)
{
    Node *tmp = new Node(val);
    tmp->left = ref_node;
    tmp->right = ref_node->right;
    ref_node->right = tmp;
    tmp->right->left = tmp;
}

void delete_from_first()
{
    Node *tmp = head;
    head = head->right;
    if(head == NULL) tail = NULL;
    else head->left = NULL;

    delete tmp;
}

void delete_from_last()
{
    Node *tmp = tail;
    tail = tail->left;
    if(tail == NULL) head = NULL;
    else tail->right = NULL;

    delete tmp;
}

void delete_first_or_last_occurance(Node *ref_node)
{
    ref_node->left->right = ref_node->right;
    ref_node->right->left = ref_node->left;

    delete ref_node;
}

Node * find_kth_node(int k)
{
    Node *tmp = head;
    int current_position = 1;

    while(current_position != k)
    {
        tmp = tmp->right;
        current_position++;
    }

    return tmp;
}

int find_middle_element()
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->right != NULL)
    {
        fast = fast->right->right;
        if (fast != NULL) slow = slow->right;
    }

    return slow->val;
}

void cutPaste(int k)
{
    Node * first = head;

    // find k-th node
    Node * last = find_kth_node(k);

    head = last->right;
    first->left = tail;
    tail->right = first;
    tail = last;
    tail->right = NULL;
}

void print_list(Node * tmp)
{
    // base case
    if(tmp == NULL) return;

    cout << tmp->val << " ";
    print_list(tmp->right);
}

void print_reverse_list(Node * tmp)
{
    // base case
    if(tmp == NULL) return;

    print_reverse_list(tmp->right);
    cout << tmp->val << " ";
}

void deleteDuplicates()
{
    for(Node *i = head; i != tail; i = i -> right)
    {
        int key = i->val;

        for(Node *j = i->right; j != NULL; j = j->right)
        {
            if(j->val == key)
            {
                // storing j node for next iteration
                Node *del = j;
                j = j->right;

                if(del == tail) delete_from_last();
                else delete_first_or_last_occurance(del);
            }

            if(j == NULL) break;
        }

        if(i == tail) break;
    }
}

int main()
{
    init();

    while (1)
    {
        cout << endl
             << "1. Insert first" << endl
             << "2. Insert last" << endl
             << "3. Insert after first occurance" << endl
             << "4. Insert after last occurance" << endl
             << "5. Delete from first" << endl
             << "6. Delete from last" << endl
             << "7. Delete first occurance" << endl
             << "8. Delete last occurance" << endl
             << "9. Find first occurance" << endl
             << "10. Find last occurance" << endl
             << "11. Find k-th node" << endl
             << "12. Find middle element" << endl
             << "13. Cut Paste" << endl
             << "14. Print list" << endl
             << "15. Print list in reverse order" << endl
             << "16. Delete duplicates" << endl << endl;

        int choice;
        cout << "Enter your choice : ";
        cin >> choice;

        if(choice == -1) break;

        if(choice == 1)
        {
           int val;
           cout << "Enter the value : ";
           cin >> val;

           if(head == NULL) insert_at_empty_list(val);
           else insert_first(val);

           size++;
        }

        if(choice == 2)
        {
           int val;
           cout << "Enter the value : ";
           cin >> val;

           if(tail == NULL) insert_at_empty_list(val);
           else insert_last(val);

           size++;
        }

        if(choice == 3)
        {
           int ref_val, val;
           cout << "Enter the reference value : ";
           cin >> ref_val;
           cout << "Enter the value : ";
           cin >> val;

           // find the first occurance
           Node * ref_node = find_first_occurance(ref_val);

           if(ref_node == NULL) cout << endl << "Reference value not found!";
           else if(ref_node == tail) insert_last(val);
           else insert_after_first_or_last_occurance(ref_node, val);

           if(ref_node != NULL) size++;
        }

        if(choice == 4)
        {
           int ref_val, val;
           cout << "Enter the reference value : ";
           cin >> ref_val;
           cout << "Enter the value : ";
           cin >> val;

           // find the last occurance
           Node * ref_node = find_last_occurance(ref_val);

           if(ref_node == NULL) cout << endl << "Reference value not found!";
           else if(ref_node == tail) insert_last(val);
           else insert_after_first_or_last_occurance(ref_node, val);

           if(ref_node != NULL) size++;
        }

        if(choice == 5)
        {
            if(head == NULL) cout << endl << "List is already empty!" << endl;
            else
            {
                delete_from_first();
                size--;
            }
        }

        if(choice == 6)
        {
            if(tail == NULL) cout << endl << "List is already empty!" << endl;
            else 
            {
                delete_from_last();
                size--;
            }
        }

        if(choice == 7)
        {
            int val;
            cout << "Enter the value : ";
            cin >> val;

            // find first occurance
            Node * ref_node = find_first_occurance(val);

            if(ref_node == NULL) cout << endl << "Value not found!" << endl;
            else if(ref_node == head) delete_from_first();
            else if(ref_node == tail) delete_from_last();
            else delete_first_or_last_occurance(ref_node);

            if(ref_node != NULL) size--;
        }

        if(choice == 8)
        {
            int val;
            cout << "Enter the value : ";
            cin >> val;

            // find last occurance
            Node * ref_node = find_last_occurance(val);

            if(ref_node == NULL) cout << endl << "Value not found!" << endl;
            else if(ref_node == head) delete_from_first();
            else if(ref_node == tail) delete_from_last();
            else delete_first_or_last_occurance(ref_node);

            if(ref_node != NULL) size--;
        }

        if(choice == 9)
        {
            int val;
            cout << "Enter the value : ";
            cin >> val;

            // find first occurance
            Node *ref_node = find_first_occurance(val);

            if(ref_node == NULL) cout << endl << "Value not found!" << endl;
            else cout << endl << "Value found at memory address " << ref_node;
        }

        if(choice == 10)
        {
            int val;
            cout << "Enter the value : ";
            cin >> val;

            // find last occurance
            Node *ref_node = find_last_occurance(val);

            if(ref_node == NULL) cout << endl << "Value not found!" << endl;
            else cout << endl << "Value found at memory address " << ref_node;
        }

        if(choice == 11)
        {
            int k;
            cout << "Enter the position : ";
            cin >> k;

            if(k <= 0 or k > size) cout << endl << "Invalid position!" << endl;
            else cout << "Value of the desired node : " << find_kth_node(k)->val << endl;
        }

        if(choice == 12)
        {
            if(size == 0) cout << endl << "List is empty" << endl;
            else if(size == 1) cout << "Middle element : " << head->val << endl;
            else cout << "Middle element : " << find_middle_element() << endl;
        }

        if(choice == 13)
        {
            int k;
            cout << "Cut first k nodes from the begining and paste it at the end." << endl << "Enter k : ";
            cin >> k;

            if(head == NULL) cout << endl << "List is empty!" << endl;
            else if(k <= 0 or k > size) cout << endl << "Invalid input" << endl;
            else if(k == size) continue;
            else cutPaste(k);
        }

        if(choice == 14)
        {
            cout << endl << "List : ";
            print_list(head);
        }

        if(choice == 15)
        {
            cout << endl << "List : ";
            print_reverse_list(head);
        }

        if(choice == 16)
        {
            if(head == NULL) continue;
            else deleteDuplicates();
        }

        cout << endl;
    }

    return 0;
}