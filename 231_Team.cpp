#include "bits/stdc++.h"
using namespace std;

int n;
int main() {
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x + y + z >= 2) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}