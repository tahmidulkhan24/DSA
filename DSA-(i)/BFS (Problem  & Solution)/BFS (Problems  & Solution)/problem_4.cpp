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

class BST
{
public:
    Node *root;

    BST()
    {
        this->root = NULL;
    }

    void insert(int val)
    {
        if (root == NULL)
        {
            root = new Node(val);
            return;
        }

        Node *slow = NULL;
        Node *fast = root;

        while (fast != NULL)
        {
            slow = fast;

            if (val < fast->key)
                fast = fast->left;
            else
                fast = fast->right;
        }

        if (val < slow->key)
            slow->left = new Node(val);
        else
            slow->right = new Node(val);
    }

    void bfs(Node *src, map<Node *, bool> &vis, map<Node *, int> &level, map<int, vector<int>> &level_list)
    {
        if (src == NULL)
            return;

        queue<Node *> q;
        q.push(src);
        vis[src] = true;
        level[src] = 0;

        while (!q.empty())
        {
            Node *par = q.front();
            q.pop();
            level_list[level[par]].push_back(par->key);

            // left child
            if (par->left != NULL and vis[par->left] == false)
            {
                q.push(par->left);
                vis[par->left] = true;
                level[par->left] = level[par] + 1;
            }

            // right child
            if (par->right != NULL and vis[par->right] == false)
            {
                q.push(par->right);
                vis[par->right] = true;
                level[par->right] = level[par] + 1;
            }
        }
    }
};

int main()
{
    BST b;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        b.insert(x);
    }

    map<Node *, bool> vis;
    map<Node *, int> level;
    map<int, vector<int>> level_list;

    b.bfs(b.root, vis, level, level_list);

    // print BST level wise
    for (auto [x, y] : level_list)
    {
        for (int val : y)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}

/*
INPUT:
-----
8 
4 5 2 7 1 3 8 9

OUTPUT:
------
4 
2 5 
1 3 7 
8
9

*/