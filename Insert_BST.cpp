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
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
    return root;
}

void level_order(node* root) {
    if (root == NULL) {
        cout << "No Tree";
        return;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        // 1.  ber kore ana
        node* f = q.front();
        q.pop();

        // 2.  oi node ke niye kaj
        cout << f->val << " ";

        // 3.  children push kora
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

void insert(node*& root, int val) {
    if (root == NULL)
        root = new node(val);
    if (root->val > val) {
        if (root->val == NULL)
            root->left = new node(val);
        else
            insert(root->left, val);
    } else {
        if (root->val == NULL)
            root->left = new node(val);
        else
            insert(root->right, val);
    }
}
int main() {
    node* root = input_tree();
    int x;
    cin >> x;
    insert(root, x);
    level_order(root);

    return 0;
}