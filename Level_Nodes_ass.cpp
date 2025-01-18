#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node* input_tree() {
    int val;
    cin >> val;
    node* root;
    if (val == -1)
        root = NULL;
    else
        root = new node(val);
    queue<node*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        node *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

void nodeLevel(node* root, int x) {
    int b = 0;
    queue<pair<node*, int>> q;
    if (root)
        q.push({root, 0});

    while (!q.empty()) {
        pair<node*, int> parent = q.front();
        q.pop();

        node* node = parent.first;
        int level = parent.second;

        if (level == x) {
            cout << node->val << " ";
            b = 1;
        }
        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    if (b == 0)
        cout << "Invalid";

    return;
}

int main() {
    node* root = input_tree();
    int x;
    cin >> x;
    nodeLevel(root, x);

    // tahsin hasan

    return 0;
}
