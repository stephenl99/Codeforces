#include "bits/stdc++.h"
using namespace std;

#define debug(x) cerr << #x << " = " << x << '\n';

int solve(vector<int>& input) {
    int maxx = 0;
    int count = 0;
    for (int num : input) {
        if (num < maxx) {
            count++;
        }
        maxx = max(maxx, num);
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> input(n);
        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }
        cout << solve(input) << '\n';
    }

    return 0;
}