#include "bits/stdc++.h"
using namespace std;

long long solve(vector<int>& prices, vector<int>& discounts, long long total) {
    sort(prices.begin(), prices.end());
    sort(discounts.begin(), discounts.end());
    long long discount = 0;
    int currPrice = prices.size() - 1;
    for (int i = 0; i < discounts.size(); i++) {
        if (currPrice - discounts[i] + 1 < 0) {
            break;
        }
        discount += prices[currPrice - discounts[i] + 1];
        currPrice = currPrice - discounts[i];
    }
    return total - discount;
}
int main() {
    int t;
    cin >> t;
    string output;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> prices;
        vector<int> discounts;
        long long total = 0;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            total += val;
            prices.push_back(val);
        }
        for (int i = 0; i < k; i++) {
            int val;
            cin >> val;
            discounts.push_back(val);
        }
        long long singleOutput = solve(prices, discounts, total);
        output += to_string(singleOutput) + '\n';
    }
    cout << output;
    return 0;
}