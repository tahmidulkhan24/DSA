#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int key;
    Node *left, *right;
    Node(int val)
    {
        this->key = val;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node *root;
    void insert(int x)
    {
        Node *tmp = new Node(x);
        if (root == NULL)
        {

            tmp->key = x;
            tmp->left = NULL;
            tmp->right = NULL;
            root = tmp;
            return;
        }
        Node *slow, *fast;
        slow = NULL;
        fast = root;
        while (fast != NULL)
        {

            slow = fast;
            if (fast->key > x)
                fast = fast->left;
            else
                fast = fast->right;
        }

        tmp->key = x;
        tmp->left = NULL;
        tmp->right = NULL;
        if (slow->key > tmp->key)
            slow->left = tmp;
        else
            slow->right = tmp;
        free(fast);
    }
    int i = 0;
    void kth_val(Node *node, int k)
    {
        if (node == NULL)
        {
            return;
        }
        kth_val(node->right, k);
        i++;
        if (i == k)
            cout << node->key << endl;
        kth_val(node->left, k);
    }
    void print(Node *node)
    {
        node = root;
        if (node == NULL)
        {
            return;
        }
        print(node->left);
        cout << node->key << " ";
        print(node->right);
    }
};
int main()
{
    BST b;
    b.root = NULL;
    int n;
    while (1)
    {
        cout << "1.insert\n2.finding kth max val\n";

        cin >> n;
        if (n == 1)
        {
            int v;
            cin >> v;
            b.insert(v);
            
        }
        else if (n == 2)
        {

            int k;
            cin >> k;
            b.kth_val(b.root, k);
        }
        else
            break;
    }
    b.print(b.root);
}
