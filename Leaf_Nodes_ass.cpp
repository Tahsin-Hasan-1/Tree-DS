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
    if (val == -1) root = NULL;
    else root = new node(val);
    queue<node*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        node* p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        node *myLeft, *myRight;
        if (l == -1) myLeft = NULL;
        else myLeft = new node(l);
        if (r == -1) myRight = NULL;
        else myRight = new node(r);
        p->left = myLeft;
        p->right = myRight;
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
    return root;
}

void leaf(node* root, vector<int>& v) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        v.push_back(root->val);
        return;  // 
    }
    leaf(root->left, v);
    leaf(root->right, v);
}

int main() {
    node* root = input_tree();
    vector<int> v;
    leaf(root, v);
    sort(v.begin(), v.end(), greater<int>());  
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}