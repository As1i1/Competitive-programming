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
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    s--;
    vector<tuple<int, int, ll>> edges;
    vector<ll> d(n, ll_INF);
    vector<ll> d_(n, ll_INF);
    for (int i = 0; i < m; ++i) {
        ll c;
        int v, u; cin >> v >> u >> c;
        u--;v--;
        edges.push_back({v, u, c});
    }
    d[s] = 0;
    for (int i = 0; i < k; ++i) {
        for (auto [v, u, c] : edges) {
            if (d[v] != ll_INF) d_[u] = min(d_[u], d[v] + c);
        }
        d = d_;
        d_ = vector<ll>(n, ll_INF);
    }
    for (int i = 0; i < n; ++i) {
        cout << ((d[i] == ll_INF) ? -1 : d[i]) << "\n";
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
