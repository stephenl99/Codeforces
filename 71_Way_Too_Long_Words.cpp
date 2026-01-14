#include "bits/stdc++.h"
using namespace std;


int n;
vector<string> words;

int main() {
    cin >> n;
    string x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        words.push_back(x);
    }
    for (string word : words) {
        if (word.size() > 10) {
            int len = word.size() - 2;
            cout << word[0] + to_string(len) + word[word.size() - 1] << endl;
        } else {
            cout << word << endl;
        }
    }
    return 0;
}