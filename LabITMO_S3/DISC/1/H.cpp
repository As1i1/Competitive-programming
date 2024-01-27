//
// Created by asi1i on 10/21/23.
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
struct poly {
    vector<ll> kf;
};

vector<pair<int, int>> st(int v /* max */, int u /* min */, vector<pair<int, int>> edges) {
    vector<pair<int, int>> g;
    for (auto [v1, u1]: edges) {
        int x = max(v1, u1);
        int y = min(v1, u1);
        if (x == v && y == u) continue;
        if (x != v && x != u && y != v && y != u) {
            g.push_back({x, y});
        } else {
            if (x == u) {
                x = v;
            }
            if (y == u) {
                y = v;
            }
            int x_ = max(x, y);
            int y_ = min(x, y);
            if (find(g.begin(), g.end(), make_pair(x_, y_)) == g.end()) {
                g.push_back({x_, y_});
            }
        }
    }
    return g;
}

poly rec(vector<pair<int, int>> g, int vertex_count) {
    if (g.size() == 0) {
        vector<ll> kf(n + 1, 0);
        kf[vertex_count] = 1;
        return {kf};
    }
    auto [u, v] = g.back();
    g.pop_back();
    poly a = rec(g, vertex_count);
    vector<pair<int, int>> g2 = st(max(u, v), min(u, v), g);

    poly b = rec(g2, vertex_count - 1);

    for (int i = 0; i <= n; ++i) {
        a.kf[i] -= b.kf[i];
    }
    return a;
}

void solve(){
    int m;
    cin >> n >> m;
    vector<pair<int, int>> g;
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        v--;u--;
        g.push_back({u, v});
    }
    poly res = rec(g, n);
    cout << n << "\n";
    for (int i = n; i >= 0; --i) {
        cout << res.kf[i] << " ";
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
    while(t--){
        solve();
    }
    return 0;
}
