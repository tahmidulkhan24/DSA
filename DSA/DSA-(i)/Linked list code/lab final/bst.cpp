#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};
class BST
{
public:
    Node *root;
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
            if (fast->key > val)
            {
                fast = fast->left;
            }
            else
            {
                fast = fast->right;
            }
        }
        fast = new Node(val);
        if (fast->key > slow->key)
        {
            slow->right = fast;
        }
        else
            slow->left = fast;
    }
    Node *insert_rec(Node *tmp, int val)
    {
        if (tmp == NULL)
        {
            return new Node(val);
        }
        if (val < tmp->key)
            insert_rec(tmp->left, val);
        else
            insert_rec(tmp->right, val);
        return root;
    }
    Node *findNode(int val)
    {
        Node *tmp = root;
        while (tmp != NULL)
        {
            if (tmp->key == val)
                return tmp;
            else if (tmp->key > val)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        return NULL;
    }
    Node *findMaximum(Node *node)
    {
        if (node->right == NULL)
            return node;
        return findMaximum(node->right);
    }
    Node *findMinimum(Node *node)
    {
        if (node->left == NULL)
            return node;
        return findMinimum(node->left);
    }
    void inOrder(Node *node)
    {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }
    int height(Node *node)
    {
        if (node == NULL)
            return -1;
        return max(height(node->left), height(node->right)) + 1;
    }
    Node *search(Node *tmp, int val)
    {
        if (tmp == NULL)
            return;
        if (tmp->key == val)
            return tmp;
        if (val < tmp->key)
            return search(tmp->left, val);
        else
            return search(tmp->right, val);
    }
    int size(Node *tmp)
    {
        if (tmp == NULL)
            return 0;
        return size(tmp->left) + size(tmp->right) + 1;
    }
    bool balanced(Node *node)
    {
        if (node == NULL)
            return true;
        bool left = balanced(node->left);
        bool right = balanced(node->right);
        int lh = height(node->left);
        int rh = height(node->right);
        if (abs(lh - rh) > 1)
            return false;
        else
            return left && right;
    }
    void delete0child(Node *node)
    {
        if(node==root)
        {
            root=NULL;
            delete(node);
            return;
        }
        Node *slow=root;
        Node *fast=root;
        while(fast!=node)
        {
            slow=fast;
            if(node->key<fast->key) fast=fast->left;
            else fast=fast->right;
        }
        if(slow->left==node) slow->left=NULL;
        else slow->right=NULL;
        delete(node);
    }
    void delete1child(Node *node)
    {
        if(node==root)
        {
            if(node->left == NULL) root = node->right;
            else root = node->left;

            delete(node);
            return;
        }
        Node *slow=root;
        Node *fast=root;
        while(fast!=node)
        {
            slow=fast;
            if(node->key<fast->key) fast=fast->left;
            else fast=fast->right;
        }
        Node *nextnode;
        if(fast->left==NULL) nextnode=fast->right;
        else nextnode=fast->left;

        if(slow->left==node) slow->left=nextnode;
        else slow->right=nextnode;

        delete(node);
    }
    void delete2child(Node *node)
    {
        Node *ios=findMaximum(node->right);
        node->key=ios->key;
        if(ios->left==NULL && ios->right==NULL) delete0child(ios);
        else delete1child(ios);
    }
};
int main()
{
    BST b;
    b.root = NULL;

    while (1)
    {
        cout << "1. Insert    2. Sort      3. Level Order    4. Minimum\n5. Maximum   6. Delete    7. Height    8. Find    9. Size    10. Balanced?     11. End\n\n";
        int x;
        cin >> x;

        if (x == 1)
        {
            cout << "Insert Value: ";
            int y;
            cin >> y;
            b.insert(y);
            cout << y << " is inserted in the tree" << endl;
        }

        else if (x == 2)
        {
            cout << "Sorted List of the tree: ";
            b.inOrder(b.root);
            cout << endl;
        }

        else if (x == 3)
        {
            if (b.root == NULL)
            {
                cout << "Tree is empty" << endl;
                continue;
            }
            cout << "Level Wise Traversal of the tree:" << endl;
            b.bfs();
            cout << endl;
        }

        else if (x == 4)
        {
            if (b.root == NULL)
            {
                cout << "Tree is empty" << endl;
                continue;
            }
            cout << "Minimum of the tree: ";
            Node *min = b.findMinimum(b.root);
            cout << min->key << endl;
        }

        else if (x == 5)
        {
            if (b.root == NULL)
            {
                cout << "Tree is empty" << endl;
                continue;
            }
            cout << "Maximum of the tree: ";
            Node *max = b.findMaximum(b.root);
            cout << max->key << endl;
        }

        else if (x == 6)
        {
            if (b.root == NULL)
            {
                cout << "Tree is empty" << endl;
                continue;
            }
            cout << "Delete Value: ";
            int y;
            cin >> y;
            bool test = b.deleteNode(y);
            if (test)
                cout << y << " is deleted from the tree" << endl;
            else
                cout << y << " is not found in the tree" << endl;
        }
        else if (x == 7)
        {
            cout << "Height of the tree: " << b.height(b.root) << endl;
        }
        else if (x == 8)
        {
            cout << "Enter value: ";
            int y;
            cin >> y;

            if (b.search(b.root, y) == NULL)
                cout << y << " not found in the list." << endl;
            else
                cout << y << " found in the list." << endl;
        }
        else if (x == 9)
        {
            cout << "Size of the tree is: " << b.size(b.root) << endl;
        }
        else if (x == 10)
        {
            if (b.balanced(b.root) == true)
                cout << "Balanced" << endl;
            else
                cout << "Not Balanced" << endl;
        }
        else if (x == 11)
            break;
        else
        {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }

    return 0;
}

/*
1
44

1
17

1
88

1
32

1
65

1
97

1
28

1
54

1
82

1
29

1
76

1
80
*/