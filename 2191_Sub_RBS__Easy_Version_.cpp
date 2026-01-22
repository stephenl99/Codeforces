#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

int solve(string input) {
    int n = input.size();
    int numF = 0;
    int lastF = -1;
    int minn = -1;
    for (int i = input.size() - 1; i >= 0; i--) {
        if (input[i] == '(') {
            if (lastF == -1) {
                numF++;
                lastF = i;
                continue;
            }
            numF++;
            lastF = i;
        } else if (lastF != -1) {
            if (numF > lastF - i) {
                minn = max(minn, n - (2*(lastF - i)));
            }
        }
    }
    return minn;
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
        string input;
        cin >> input;
        output.push_back(solve(input));
    }
    for (int num : output) {
        cout << num << endl;
    }


    
    return 0;
}