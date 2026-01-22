#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>


vector<int> solve(string input) {
    int last = 0;
    bool sorted = true;
    int count1 = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '0' && last == 1) {
            sorted = false;
        } else if (input[i] == '1') {
            last = 1;
            count1++;
        }
    }
    vector<int> answer;
    if (sorted) {
        return answer;
    }
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '1' && i < input.size() - count1) {
            answer.push_back(i);
        }
        if (input[i] == '0' && i >= input.size() - count1) {
            answer.push_back(i);
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<vector<int>> output;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string temp;
        cin >> temp;
        output.push_back(solve(temp));
    }
    for (vector<int> num : output) {
        if (num.size() == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
            cout << num.size() << endl;
            for (int numm : num) {
                cout << numm + 1 << ' ';
            }
            cout << endl;
        }
    }


    
    return 0;
}