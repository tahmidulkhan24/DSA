#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, level;
    Node *left, *right, *parent;
};

class BST
{
public:
    Node *root;

    void insert(int val)
    {
        if (root == NULL)
        {
            Node *tmp = (Node *)malloc(sizeof(Node));
            tmp->key = val;
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
            if (fast->key > val)
            {
                fast = fast->left;
            }
            else
                fast = fast->right;
        }
        Node *fast = (Node *)malloc(sizeof(Node));
        fast->key = val;
        fast->left = NULL;
        fast->right = NULL;
        if (fast->key > slow->key)
        {
            slow->right = fast;
        }
        else
            slow->left = fast;
    }

    Node *findNode(int val)
    {
        Node *tmp = root;
        while (tmp != NULL)
        {

            if (tmp->key > val)
            {
                tmp = tmp->left;
            }
            else
                tmp = tmp->right;
            if (tmp->key == val)
            {
                return tmp;
            }
        }
        return NULL;
    }

    Node *findMaximum(Node *node)
    {
        Node *tmp = root;
        if (tmp == NULL)
            return NULL;
        while (tmp->right != NULL)
        {
            findMaximum(tmp->right);
        }
        return tmp;
    }

    Node *findMinimum(Node *node)
    {
        Node *tmp = root;
        if (tmp == NULL)
            return NULL;
        while (tmp->left != NULL)
        {
            findMaximum(tmp->left);
        }
        return tmp;
    }

    void inOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }

private:
    Node *findSuccessor(Node *node)
    {
    }

    void delete0Child(Node *node)
    {
        
    }

    void delete1Child(Node *node)
    {
    }

    void delete2Child(Node *node)
    {
    }

public:
    bool deleteNode(int val)
    {
    }

    int height(Node *node)
    {
        if (node == NULL)
        {
            return -1;
        }
        int l = height(node->left);
        int r = height(node->right);
        if (l > r)
        {
            return l + 1;
        }
        else
        {
            return r + 1;
        }
    }

    Node *search(Node *tmp, int val)
    {
        if (tmp == NULL)
            return NULL;
        if (tmp->key == val)
            return tmp;
        if (val < tmp->key)
            return search(tmp->left, val);
        else
            return search(tmp->right, val);
    }

    int size(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int l = size(node->left);
        int r = size(node->right);
        return l + r + 1;
    }
    bool balanced(Node *node)
    {
        if (node == NULL)
        {
            return true;
        }
        int l = height(node->left);
        int r = height(node->right);
        int bf = abs(l - r);
        if (bf > 1)
        {
            return false;
        }
        bool x = balanced(node->left);
        bool y = balanced(node->right);
        return x && y;
    }

    void bfs()
    {
        queue<Node *> q;
        root->level = 0;
        int level = root->level;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->level > level)
            {
                cout << endl;
                level++;
            }
            cout << temp->key << " ";
            if (temp->left != NULL)
            {
                if (temp->left != root)
                    temp->left->level = temp->level + 1;
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                if (temp->right != root)
                    temp->right->level = temp->level + 1;
                q.push(temp->right);
            }
        }
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
            if (b.search(y) == 0)
                cout << y << " not found in the list." << endl;
            else
                cout << y << " found in the list." << endl;
        }
        else if (x == 9)
        {
            cout << "Size of the tree is: " << b.size() << endl;
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
