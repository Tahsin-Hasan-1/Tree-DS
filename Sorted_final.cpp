#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int N;
        cin >> N; 

        list<int> t; 

       while(N--) {
            int x;
            cin >> x;
            t.push_back(x);
        }

        t.sort();
        t.unique();   //tahsin hasan

        for (const int &num : t) {
            cout << num << " ";
        }
        cout << endl; 
    }

    return 0;
}
