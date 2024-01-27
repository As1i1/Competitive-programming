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
    int n;
    cin >> n;
    vector<bool> used(n, false);
    vector<vector<int>> g(n);
    vector<tuple<int, int, ll>> edges(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll c; cin >> c;
            if (c != 100'000) {
                edges.emplace_back(j, i, c);
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    function<void(int)> dfs = [&](int v) {
        used[v] = true;
        for (auto u: g[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
    };

    function<bool(int)> bellman = [&](int start) {
        int circle_v = -1;
        vector<ll> d(n, ll_INF);
        vector<int> p(n, -1);
        d[start] = 0;
        for (int i = 0; i < n; ++i) {
            circle_v = -1;
            for (auto [v, u, c]: edges) {
                if (d[u] > d[v] + c) {
                    d[u] = max(-ll_INF, d[v] + c);
                    p[u] = v;
                    circle_v = u;
                }
            }
        }
        if (circle_v == -1) {
            return false;
        } else {
            int v = circle_v;
            for (int i = 0; i < n; ++i) {
                v = p[v];
            }
            vector<int> path;
            for (int i = v;; i = p[i]) {
                path.push_back(i);
                if (i == v && path.size() > 1) {
                    break;
                }
            }
            cout << "YES\n" << path.size() - 1 << "\n";
            path.pop_back();
            for (auto u: path) {
                cout << u + 1 << " ";
            }
            return true;
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
            if (bellman(i)) return;
        }
    }
    cout << "NO";
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
