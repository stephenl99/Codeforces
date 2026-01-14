#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


long long solve(int n, vi a, vi b) {
    long long currMax = 0;
    long long currMin = 0;
    for (int i = 0; i < n; i++) {
        long long newcurrMax = max({currMax - a[i], currMin - a[i], b[i] - currMax, b[i] - currMin});
        currMin = min({currMax - a[i], currMin - a[i], b[i] - currMax, b[i] - currMin});
        currMax = newcurrMax;
    }
    return currMax;
}
 //d
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<ll> output;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a;
        vector<int> b;
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            cin >> temp;
            b.push_back(temp);
        }
        output.push_back(solve(n, a, b));
    }
    for (ll num : output) {
        cout << num << endl;
    }


    
    return 0;
}