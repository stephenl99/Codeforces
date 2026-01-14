#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


string solve(string& s, string& t) {
    vector<int> freqS(26, 0);
    vector<int> freqT(26, 0);
    for (char c : t) {
        freqT[c - 'a']++;
    }
    for (char c : s) {
        freqS[c - 'a']++;
        if (freqS[c - 'a'] > freqT[c - 'a']) {
            return "Impossible";
        }
    }
    string result = "";
    int index = 0;
    for (int i = 0; i < 26; i++) {
        while (index < s.size() && s[index] - 'a' <= i) {
            result += s[index];
            freqT[s[index] - 'a']--;
            freqS[s[index] - 'a']--;
            index++;
        }
        while (freqT[i] > 0 && freqT[i] > freqS[i]) {
            result += (char) (97 + i);
            freqT[i]--;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int te;
    cin >> te;
    vector<string> output;
    for (int i = 0; i < te; i++) {
        string s;
        string t;
        cin >> s;
        cin >> t;
        output.push_back(solve(s, t));
    }
    for (string num : output) {
        cout << num << endl;
    }
    return 0;
}