#include <bits/stdc++.h>
using namespace std;

class c {
   public:
    bool operator()(int a, int b) {
        return !(a < b);
    }
};

int main() {
    priority_queue<int, vector<int>, c> p;

    int x, y;
    cin >> y;

    while (y--) {
        cin >> x;
        p.push(x);
    }

    cin >> y;

    while (y--) {
        cin >> x;
        if (x == 0) {
            cin >> x;
            p.push(x);
            cout << p.top() << endl;
        } else if (x == 1) {
            if (p.empty())
                cout << "Empty" << endl;
            else
                cout << p.top() << endl;
        } else if (x == 2) {
            if (p.empty())
                cout << "Empty" << endl;
            else {
                p.pop();
                if (p.empty())
                    cout << "Empty" << endl;
                else
                    cout << p.top() << endl;
            }
        }
    }

    return 0;
}
