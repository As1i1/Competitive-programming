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
int n;
vector<vector<pair<int, ll>>> g;


vector<ll> dijs(int start) {
    vector<ll> dist(n, ll_INF);
    set<pair<ll, int>> s;
    dist[start] = 0;
    s.insert({0, start});
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
    }
    return dist;
}


void solve() {
    int m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        ll c;
        int v, u; cin >> v >> u >> c;
        v--;
        u--;
        g[v].push_back({u, c});
        g[u].push_back({v, c});
    }
    int a, b, c; cin >> a >> b >> c;a--;b--;c--;
    vector<ll> d_A = dijs(a);
    vector<ll> d_B = dijs(b);
    vector<ll> d_C = dijs(c);

    ll res = ll_INF;

    for (int i = 0; i < n; ++i) {
        if (d_A[i] != ll_INF && d_B[i] != ll_INF && d_C[i] != ll_INF) {
            ll mn = min({d_A[i], d_B[i], d_C[i]});
            if (mn == d_A[i]) {
                res = min(res, d_B[i] + d_C[i] + 2 * mn);
            } else if (mn == d_B[i]) {
                res = min(res, d_A[i] + d_C[i] + 2 * mn);
            } else {
                res = min(res, d_A[i] + d_B[i] + 2 * mn);
            }
        }
    }

    if (res == ll_INF) {
        cout << -1;
    } else {
        cout << res;
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
