#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
#define vi vector<int>;
#define vii vector<pair<int, int>>;
#define pii pair<int, int>;
#define ll long long;
#define pll pair<ll, ll>;
using namespace std;


int solve(vector<int> input) {
    set<int> colors;
    for (int num : input) {
        colors.insert(num);
    }
    int numColors = colors.size();
    auto it = colors.lower_bound(numColors);
    return *it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> output;
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
    for (int num : output) {
        cout << num << endl;
    }
    return 0;
}