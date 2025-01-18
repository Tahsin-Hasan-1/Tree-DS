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

        int l, r;  // tahsin hasan
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
int sum_out_leaf(node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;

    return root->val + sum_out_leaf(root->left) + sum_out_leaf(root->right);
}

int main() {
    node* root = input_tree();

    int k = sum_out_leaf(root);
    cout << k;
    return 0;
}