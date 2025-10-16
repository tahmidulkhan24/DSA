#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *root = NULL;
void insert(int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }

    Node *slow = root;
    Node *fast = root;
    while (fast != NULL)
    {
        slow = fast;
        if (val < fast->key)
            fast = fast->left;
        else
            fast = fast->right;
    }

    fast = new Node(val);
    if (val < slow->key)
        slow->left = fast;
    else
        slow->right = fast;
}
int i = 0;
void inOrder(Node *node, int k)
{
    if (node == NULL)
        return;

    inOrder(node->right, k);
    i++;
    if (i == k)
    {
        cout << node->key << " "<<endl;
    }

    inOrder(node->left, k);
}
void print(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        print(node->left);
        cout << node->key << " ";
        print(node->right);
    }
int main()
{
    int n;
    
    while (1)
    {
        cin >> n;
        cout << "1.insert\n2.finding kth max val\n";

        if (n == 1)
        {
            int v;
            cin >> v;
            insert(v);
            
        }
        else if (n == 2)
        {

            int k;
            cin >> k;
            inOrder(root,k);
        }
        else
            break;
    }

    print(root);



    return 0;
}