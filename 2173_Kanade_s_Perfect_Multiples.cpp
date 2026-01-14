#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


vector<int> solve(int n, int k, vector<int> input) {
    sort(input.begin(), input.end());
    unordered_set<int> s;
    for (int i = n - 1; i >= 0; i--) {
        int t = 1;
        s.insert(input[i]);
        while (input[i] * t <= k) {
            if (s.find(input[i] * t) == s.end()) {
                return {};
            }
            t++;
        }
    }
    for (int num : input) {
        int t = 2;
        while (num * t <= k) {
            if (s.find(num * t) != s.end()){
                s.erase(num * t);
            }
            t++;
        }
    }
    vector<int> output;
    copy(s.begin(), s.end(), back_inserter(output));
    return output;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<vector<int>> output;
    for (int i = 0; i < t; i++) {
        int n;
        vector<int> input;
        cin >> n;
        int k;
        cin >> k;
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            input.push_back(temp);
        }
        output.push_back(solve(n, k, input));
    }
    for (vector<int> num : output) {
        if (num.size() == 0) {
            cout << -1 << endl;
        }
        else {
            cout << num.size() << endl;
            for (int n : num) {
                cout << n << ' ';
            }
            cout << endl;
        }
    }


    
    return 0;
}