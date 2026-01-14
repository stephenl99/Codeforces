#include "bits/stdc++.h"
using namespace std;

int n;
int main() {
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        string curr;
        cin >> curr;
        if (curr[0] == '+' || curr[2] == '+') {
            count++;
        } else {
            count--;
        }
    }
    cout << count << endl;
    return 0;
}