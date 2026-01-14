#include "bits/stdc++.h"
using namespace std;

vector<long double> solve(int length, int busSpeed, int walkSpeed, vector<vector<int>> buses, vector<vector<int>> people) {
    std::sort(buses.begin(), buses.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
          });
    std::sort(people.begin(), people.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
          });
    vector<long double> answer(people.size(), 0.0);
    int busIndex = 0;
    int personIndex = 0;
    stack<vector<int>> busStack;
    while (personIndex < people.size()) {
        int personStart = people[personIndex][0];
        int index = people[personIndex][1];
        while (!busStack.empty() && busStack.top()[1] <= personStart) {
            busStack.pop();
        }
        while (busIndex < buses.size() && buses[busIndex][0] <= personStart) {
            if (buses[busIndex][1] <= personStart) {
                busIndex++;
                continue;
            } else {
                long double cost = ((buses[busIndex][1] - buses[busIndex][0])/ (busSpeed * 1.0)) + ((length - buses[busIndex][1]) /(walkSpeed * 1.0));
                while (true) {
                    if (busStack.empty()) {
                        busStack.push(buses[busIndex]);
                        break;
                    } else {
                        long double oldCost = ((busStack.top()[1] - busStack.top()[0]) / (busSpeed * 1.0)) + ((length - busStack.top()[1]) / (walkSpeed * 1.0));
                        if (cost <= oldCost) {
                            busStack.pop();
                        } else {
                            break;
                        }
                    }
                }
                busIndex++;
            }
        }
        long double walkCost = (length - personStart) / (walkSpeed * 1.0);

        if (busStack.empty()) {
            answer[index] = walkCost;
        } else {
            long double busCost = ((busStack.top()[1] - busStack.top()[0]) / (busSpeed*1.0)) + ((length - busStack.top()[1]) / (walkSpeed*1.0));
            // cout << busCost << endl;
            // cout << index << endl;
            if (busCost >= walkCost) {
                busStack = {};
                answer[index] = walkCost;
            } else {
                answer[index] = busCost;
            }
        }
        personIndex++;
    }
    return answer;
}

int main() {
    int n;
    int m;
    int l;
    int x; 
    int y;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> l >> x >> y;
    vector<vector<int>> buses;
    for (int i = 0; i < n; i++) {
        int s;
        int t;
        cin >> s >> t;
        buses.push_back({s, t});
    }
    vector<vector<int>> people;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        people.push_back({p, i});
    }
    vector<long double> output = solve(l, x, y, buses, people);
    cout << fixed << setprecision(15);
    for (long double num : output) {
        cout << num << endl;
    }

    return 0;
}