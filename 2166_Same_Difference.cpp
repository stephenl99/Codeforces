#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


int solve(string input) {
    char c = input[input.size() - 1];
    int count = 1;
    for (int i = input.size() - 2; i >= 0; i--) {
        if (input[i] == c) {
            count++;
        }
    }
    return input.size() - count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> output;
    for (int i = 0; i < t; i++) {
        int n;
        string input;
        cin >> n;
        cin >> input;
        output.push_back(solve(input));
    }
    for (int num : output) {
        cout << num << endl;
    }
    return 0;
}