#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *root = NULL;

// Function to insert a node into the BST
void insert(int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }

    Node *slow = root, *fast = root;
    while (fast != NULL) {
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

// Function for Level Order Traversal (BFS)
void bfs(Node *src) {
    if (src == NULL) return;
    
    queue<Node *> q;
    q.push(src);
    
    while (!q.empty()) {
        // int size = q.size(); // Number of nodes at the current level
        
        // // Loop through all nodes at this level
        // for (int i = 0; i < size; i++) {
        //     Node *par = q.front();
        //     q.pop();
            
        //     cout << par->key;  // Print the current node's value
            
        //     // Print space if it's not the last node in this level
        //     if (i < size - 1) {
        //         cout << " ";
        //     }

        Node *par = q.front();
        q.pop();

        cout<<par->key<<" ";


            // Push left and right children to the queue
            if (par->left) q.push(par->left);
            if (par->right) q.push(par->right);


        

        // Print a new line after every level
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        insert(a);
    }
    bfs(root);
    return 0;
}
