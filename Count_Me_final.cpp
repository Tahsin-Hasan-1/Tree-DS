#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();  

    for (int t = 0; t < T; ++t) {
        string S;
        getline(cin, S);

        vector<string> words;
        vector<int> counts;

        stringstream ss(S);
        string word;
        while (ss >> word) {
            auto it = find(words.begin(), words.end(), word);
            if (it != words.end()) {
                int index = distance(words.begin(), it);
                counts[index]++;
            } else {
                words.push_back(word);
                counts.push_back(1);
            }
        }

        int max_count = 0;
        string result;
        for (size_t i = 0; i < words.size(); ++i) {
            if (counts[i] > max_count) {
                max_count = counts[i];
                result = words[i];
            }
        }

        cout << result << " " << max_count << endl;
    }

    return 0;
}
