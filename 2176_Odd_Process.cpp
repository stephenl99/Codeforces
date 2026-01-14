#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';
using namespace std;

vector<long long> solve(vector<int>& input) {
    vector<long long> output(input.size(), 0);
    priority_queue<int> pq;
    int maxOdd = 0;
    for (int num : input) {
        if (num % 2 == 1) {
            maxOdd = max(num, maxOdd);
        } else {
            pq.push(num);
        }
    }
    if (maxOdd == 0) {
        return output;
    }
    int numEven = pq.size();
    int numOdd = input.size() - pq.size();
    long long sum = 0;
    vector<long long> prefix(numEven + 1, 0);
    for (int i = 1; i < prefix.size(); i++) {
        sum += pq.top();
        pq.pop();
        prefix[i] = sum;
    }
    output[0] = maxOdd;
    for (int i = 1; i < output.size(); i++) {
        if (i <= numEven) {
            output[i] = maxOdd + prefix[i];
        } else {
            int oddNeeded = i + 1 - numEven;
            if (oddNeeded % 2 == 0) {
                if (numEven == 0 || oddNeeded + 1 > numOdd) {
                    output[i] = 0;
                } else {
                    output[i] = maxOdd + prefix[numEven - 1];
                }
            } else {
                output[i] = maxOdd + prefix[numEven];
            }
        }
    }
    return output;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<vector<long long>> output;
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
    for (vector<long long> vector : output) {
        for (long long num : vector) {
            cout << num << ' ';
        }
        cout << endl;
    }


    
    return 0;
}