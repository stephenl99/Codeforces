#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


string solve(vector<int> input) {
    vector<pair<int, int>> newVector;
    for (int i = 0; i < input.size(); i++) {
        newVector.push_back({input[i], i % 2});
    }
    std::sort(newVector.begin(), newVector.end(),
          [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
              return a.first < b.first;
          });
    int prev = -1;
    for (pair<int, int> p : newVector) {
        if (prev == p.second) {
            return "NO";
        }
        prev = p.second;
    }
    return "YES";
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