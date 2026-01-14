#include "bits/stdc++.h"
using namespace std;

int len;

int solve(vector<int>& vals) {
    int n = vals.size();
    int left, right;
    for (int i = 0; i < n; i++) {
        if (vals[i] == n) {
            left = i;
            right = i;
        }
    }
    int next = n - 1;
    while (true) {
        if (left == 0 && right == n - 1) {
            return true;
        }
        if (left > 0 && vals[left - 1] == next) {
            left--;
            next--;
        } else if (right < n - 1 && vals[right + 1] == next) {
            right++;
            next--;
        } else {
            return false;
        }
    }
}
int main() {
    cin >> len;
    for (int i = 0; i < len; i++) {
        vector<int> vals;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            vals.push_back(val);
        }
        bool result = solve(vals);
        if (result == false) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    

    return 0;
}