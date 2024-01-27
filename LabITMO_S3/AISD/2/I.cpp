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
    vector<vector<int>> g(n);
    vector<vector<int>> g_(n);
    vector<bool> used(n, false);
    vector<int> cnt(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        cnt[u]++;
        g_[v].push_back(u);
    }
    set<int> q;
    vector<int> mid_or_feed(n, -1);
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 0) {
            mid_or_feed[i] = 0;
            q.insert(i);
        }
    }
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        if (mid_or_feed[v] == 0) {
            for (auto u: g_[v]) {
                if (mid_or_feed[u] == -1) {
                    mid_or_feed[u] = 1;
                    q.insert(u);
                }
            }
        } else {
            for (auto k: g_[v]) {
                cnt[k]--;
                if (cnt[k] == 0 && mid_or_feed[k] == -1) {
                    mid_or_feed[k] = 0;
                    q.insert(k);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (mid_or_feed[i] == -1) {
            cout << "DRAW\n";
        } else if (mid_or_feed[i] == 1) {
            cout << "FIRST\n";
        } else {
            cout << "SECOND\n";
        }
    }
    cout << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
