#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
#define int long long
using namespace std;
int inf = 1e9 + 7;

int solve(int n, int kk) {
    int original = __builtin_popcount(n);
    if (kk >= 32) {
        return kk + original - 1;
    }
    if (kk == 0) {
        return 0;
    }
    int nsize = 64;
    int ksize = 32;
    int dp[nsize + 2][ksize + 2][2];
    for (int i = 0; i <= nsize; i++) {
        for (int j = 0; j <= kk; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < nsize; i++) {
        for (int j = 0; j <= kk; j++) {
            for (int k = 0; k < 2; k++) {
                int dpval = dp[i][j][k];
                int val = (n >> i) % 2;
                if (dpval == inf) {
                    continue;
                }
                if (val + k == 0) {
                    dp[i + 1][j + 1][0] = min(dp[i + 1][j + 1][0], dpval + 1);
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dpval);
                }
                if (val + k == 1) {
                    dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dpval);
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dpval + 1);
                }
                if (val + k == 2) {
                    dp[i + 1][j][1] = min(dp[i + 1][j][1], dpval);
                    dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dpval + 1);
                }
            }
        }
    }
    int minn = inf;
    for (int j = 0; j <= kk; j++) {
        for (int k = 0; k < 2; k++) {
            minn = min(minn, dp[nsize][j][k] + k);
        }
    }
    return kk + original - minn;
}

signed main() {
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
        output.push_back(solve(n, k));
    }
    for (int num : output) {
        cout << num << endl;
    }


    
    return 0;
}