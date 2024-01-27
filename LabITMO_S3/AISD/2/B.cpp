//
// Created by Dubinin Dmitrii on 10/30/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    vector<ll> dist(n, ll_INF);
    for (int i = 0; i < m; ++i) {
        int v, u, c; cin >> v >> u >> c; v--;u--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    set<pair<ll, int>> s;
    dist[0] = 0;
    s.insert({0, 0});
    while(!s.empty()) {
        auto [c, v] = *s.begin();
        s.erase(s.begin());
        if (dist[v] != c) continue;
        for (auto [u, u_c] : g[v]) {
            if (dist[u] > c + u_c) {
                dist[u] = c + u_c;
                s.insert({dist[u], u});
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << dist[i] << " ";
        }
        cout << "\n";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
