#include "bits/stdc++.h"
 
using namespace std;
 
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
 
const ll INF = 2e18;
const int MOD = 998244353;
 
struct Edge {
    int u, v;
    ll s;
    Edge(){}
    Edge(int u, int v, ll s) : u(u), v(v), s(s){}
    bool operator < (const Edge &other) const {
        return s < other.s;
    }
};
 
void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <vi> g(n);
    vector <Edge> edges;
 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        edges.push_back(Edge(u, v, a[u] + a[v]));
    }
 
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
 
    vector<map <ll, int>> sumdp(n);
 
    int ans = 0;
 
    for (auto e : edges) {
        int u = e.u;
        int v = e.v;
        ll s = e.s;
        //cout << u << " " << v << " " << s << endl;
        int curdp = sumdp[v][s];
        add(curdp, 1);
        add(sumdp[u][a[v]], curdp);
        add(ans, curdp);
    }
 
    cout << ans << "\n";
}
 
 
int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}