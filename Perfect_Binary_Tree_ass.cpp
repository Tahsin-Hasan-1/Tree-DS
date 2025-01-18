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

int count_nodes(node* root) {
    if (root == NULL)
        return 0;
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l + r + 1;
}

int max_depth(node* root) {
    if (root == NULL)
        return 0;

    // tahsin hasan
    if (root->left == NULL && root->right == NULL)
        return 1;

    int l = max_depth(root->left);
    int r = max_depth(root->right);

    return max(l, r) + 1;
}

int main() {
    node* root = input_tree();
    int t = max_depth(root);
    int n = count_nodes(root);
    int k = pow(2, t) - 1;
    if (n == k)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
