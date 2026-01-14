#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


int solve(int n, int k, string input) {
    int i = 0;
    int count = 0;
    int nextPossible = 0;
    while (i < n) {
        if (input[i] == '0') {
            if (i >= nextPossible) {
                count++;
            }
            i++;
        } else {
            nextPossible = i + k + 1;
            i++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> output;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        string binary;
        cin >> binary;
        output.push_back(solve(n, k, binary));
    }
    for (int num : output) {
        cout << num << endl;
    }


    
    return 0;
}