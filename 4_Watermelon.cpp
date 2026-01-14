#include "bits/stdc++.h"
using namespace std;

int weight;
int main() {
    scanf( "%d", &weight);
    if (weight == 2) {
        cout << "NO" << endl;
    }
    else if (weight % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
