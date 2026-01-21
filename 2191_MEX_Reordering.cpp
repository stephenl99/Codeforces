#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


string solve(vector<int> input) {
    int n = input.size();
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[input[i]]++;
    }
    if (freq[0] == 0) {
        return "NO";
    }
    if (freq[0] == 1) {
        return "YES";
    }
    if (freq[1] >= 1) {
        return "YES";
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<string> output;
    for (int i = 0; i < t; i++) {
        int n;
        vector<int> input;
        cin >> n;
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            input.push_back(temp);
        }
        output.push_back(solve(input));
    }
    for (string num : output) {
        cout << num << endl;
    }


    
    return 0;
}