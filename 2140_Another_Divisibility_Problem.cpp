#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


int solve(int n) {
    return 2* n;
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
        int temp;
        output.push_back(solve(n));
    }
    for (int num : output) {
        cout << num << endl;
    }


    
    return 0;
}