#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '';

using namespace std;

int main() {
    int minn = 101;
    int maxx = -1;
    int temp;
    vector<int> ints;
    for (int i = 0; i < 3; i++) {
        cin >> temp;
        minn = min(minn, temp);
        maxx = max(maxx, temp);
        ints.push_back(temp);
    }
    sort(ints.begin(), ints.end());
    if (maxx - minn >= 10) {
        cout << "check again" << endl;
    } else {
        cout << "final " << ints[1] << endl;
    }
    return 0;
}