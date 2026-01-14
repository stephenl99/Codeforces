#include "bits/stdc++.h"
using namespace std;

#define debug(x) cerr << #x << " = " << x << '\n';

int solve(int n, string input) {
    int maxx = 0;
    int start = 0;
    while (input[start] == '0') {
        maxx++;
        start++;
    }
    int end = n - 1;
    while (input[end] == '0') {
        end--;
        maxx++;
    }
    int curr = 0;
    for (int i = start; i < n; i++) {
        if (input[i] == '1') {
            curr = 0;
        } else {
            curr++;
            maxx = max(maxx, curr);
        }
    }
    return maxx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string temp;
        cin >> temp;
        cout << solve(n, temp) << endl;
    }

    return 0;
}