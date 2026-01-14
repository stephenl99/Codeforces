#include "bits/stdc++.h"
// #define debug(x) cerr << #x << " = " << x << '' << endl;
using namespace std;

int euclid(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return euclid(b, a % b);
}

long long solve(vector<int> nums) {
    long long answer = 0;
    vector<int> right(nums.size(), 0);
    vector<int> left(nums.size(), 0);
    int gcd = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (gcd == 0) {
            gcd = nums[i];
        } else {
            gcd = euclid(max(gcd, nums[i]), min(gcd, nums[i]));
        }
        left[i] = gcd;
    }
    gcd = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (gcd == 0) {
            gcd = nums[i];
        } else {
            gcd = euclid(max(gcd, nums[i]), min(gcd, nums[i]));
        }
        right[i] = gcd;
    }
    for (int i = 0; i < nums.size() - 1; i++) {
        answer += min(right[i], left[i]);
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    long long answer = solve(nums);
    cout << answer << endl;
    return 0;
}