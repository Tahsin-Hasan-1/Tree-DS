#include <bits/stdc++.h>
using namespace std;

class S {
   public:
    string n;
    int r;
    int m;

    S(string a, int b, int c) {
        n = a;
        r = b;
        m = c;
    }
};

class C {
   public:
    bool operator()(const S& a, const S& b) {
        if (a.m != b.m)
            return a.m < b.m;
        return a.r > b.r;
    }
};

int main() {
    int a;
    cin >> a;

    priority_queue<S, vector<S>, C> h;

    for (int i = 0; i < a; i++) {
        string b;
        int c, d;
        cin >> b >> c >> d;
        h.push(S(b, c, d));
    }

    int e;
    cin >> e;

    while (e--) {
        int f;
        cin >> f;

        if (f == 0) {
            string b;
            int c, d;
            cin >> b >> c >> d;
            h.push(S(b, c, d));

            if (h.empty())
                cout << "Empty" << endl;
            else {
                S g = h.top();
                cout << g.n << " " << g.r << " " << g.m << endl;
            }
        } else if (f == 1) {
            if (h.empty())
                cout << "Empty" << endl;
            else {
                S g = h.top();
                cout << g.n << " " << g.r << " " << g.m << endl;
            }
        } else if (f == 2) {
            if (h.empty())
                cout << "Empty" << endl;  // tahsin hasan
            else {
                h.pop();
                if (h.empty())
                    cout << "Empty" << endl;
                else {
                    S g = h.top();
                    cout << g.n << " " << g.r << " " << g.m << endl;
                }
            }
        }
    }

    return 0;
}
