#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


vector<int> solve(int n, int l, int r) {
    vector<int> output(n);
    vector<int> p(n + 1);
    for (int i = 0; i < p.size(); i++) {
        if (i == r) {
            p[i] = p[l - 1];
        } else {
            p[i] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        output[i] = p[i + 1] ^ p[i];
    }
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
        int l;
        int r;
        cin >> n;
        cin >> l;
        cin >> r;
        output.push_back(solve(n, l, r));
    }
    for (vector<int> nums : output) {
        for (int num : nums) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}