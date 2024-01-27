//
// Created by Dubinin Dmitrii on 10/30/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = static_cast<const ll>(1e20);
mt19937 gen;
vector<vector<int>> g;
vector<bool> used;


void dfs(int v) {
    used[v] = true;
    for (auto u: g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}


void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<ll> dist(n, ll_INF);
    dist[s] = 0;
    vector<tuple<int, int, ll>> edges;
    g.assign(n, {});
    used.assign(n, false);
    for (int i = 0; i < m; ++i) {
        ll c;
        int u, v;
        cin >> v >> u >> c;
        u--;
        v--;
        edges.push_back({v, u, c});
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        for (auto [v, u, c]: edges) {
            if (dist[v] != ll_INF) {
                dist[u] = min(dist[u], dist[v] + c);
            }
        }
    }
    for (auto [v, u, c]: edges) {
        if (dist[v] != ll_INF && (dist[u] > dist[v] + c) && !used[v]) {
            dfs(v);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dist[i] == ll_INF) {
            cout << "*\n";
        } else if (used[i]) {
            cout << "-\n";
        } else {
            cout << dist[i] << "\n";
        }
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
