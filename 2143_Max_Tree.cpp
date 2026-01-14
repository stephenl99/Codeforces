#include "bits/stdc++.h"
#define debug(x) cerr << #x << " = " << x << '\n';

using namespace std;

vector<int> solve(vector<vector<int>> children, vector<int> parentCount) {
    int n = parentCount.size();
    vector<int> answer(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (parentCount[i] == 0) {
            q.push(i);
        }
    }
    int currPriority = n;
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        for (int child : children[index]) {
            parentCount[child]--;
            if (parentCount[child] == 0) {
                q.push(child);
            }
        }
        answer[index] = currPriority;
        currPriority--;
    }
    return answer;
}

int main() {
    int t;
    cin >> t;
    vector<vector<int>> answer;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<vector<int>> children(n, vector<int>(0));
        vector<int> parentCount(n, 0);
        for (int j = 0; j < n - 1; j++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            u--;
            v--;
            if (x > y) {
                children[u].push_back(v);
                parentCount[v]++;
            } else {
                children[v].push_back(u);
                parentCount[u]++;
            }
        }
        vector<int> sol = solve(children, parentCount);
        answer.push_back(sol);
    }
    for (vector<int> sol : answer) {
        bool first = true;
        for (int i : sol) {
            if (!first) {
                cout << ' ';
            }
            first = false;
            cout << i;
        }
        cout << '\n';
    }
    return 0;
}