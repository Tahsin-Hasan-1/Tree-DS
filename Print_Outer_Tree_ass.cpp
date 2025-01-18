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


void print_boundary(node* root) {
    if (!root) return;
    vector<int> res;

    if (!root->left && !root->right) {
        cout << root->val;
        return;
    }

    if (root->right) {
        vector<int> rightPath;
        node* n = root->right;
        while (n) {
            rightPath.push_back(n->val);
            if (n->right)
                n = n->right;
            else if (n->left)
                n = n->left;
            else
                break;
        }

        for (int i = rightPath.size() - 1; i >= 0; i--) {
            res.push_back(rightPath[i]);
        }
    }

    res.push_back(root->val);

    if (root->left) {
        node* n = root->left;
        while (n) {
            res.push_back(n->val);
            if (n->left)
                n = n->left;
            else if (n->right)
                n = n->right;
            else         //tahsin hasan
                break;
        }
    }

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
}

int main() {
    node* root = input_tree();
    print_boundary(root);
    return 0;
}