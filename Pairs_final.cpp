#include<bits/stdc++.h>
using namespace std;


bool compare(pair<string, int>& a, pair<string, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second; 
    }
    return a.first < b.first;
}

int main() {
    int N;
    cin >> N;

    list<pair<string, int>> v;

    while(N--) {
        string S;
        int I;
        cin >> S >> I;
        v.push_back({S, I});
    }

    
    v.sort(compare);   //tahsin hasan

   
    for (auto& p : v) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
