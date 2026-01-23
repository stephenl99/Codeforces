#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


int solve(vector<int> input) {
    int a = input[0];
    int b = input[1];
    int n = input[2];
    double thresh = 1.0 * a / (1.0 * b);
    if ((a/n) > b) {
        return 1;
    }
    if (a == b) {
        return 1;
    }
    if (thresh > 1 && thresh < n) {
        return 2;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> output;
    for (int i = 0; i < t; i++) {
        vector<int> input;
        int temp;
        for (int i = 0; i < 3; i++) {
            cin >> temp;
            input.push_back(temp);
        }
        output.push_back(solve(input));
    }
    for (int num : output) {
        cout << num << endl;
    }


    
    return 0;
}