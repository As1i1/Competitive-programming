//
// Created by aas1i1 on 2/23/24.
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
    int n, n_;
    cin >> n >> n_;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        while (v != 0) {
            v--;
            g[i].push_back(v);
            cin >> v;
        }
    }

    vector<int> match(n_, -1);
    vector<bool> used(n, false);
    function<bool(int)> dfs = [&](int v) {
        if (used[v]) {
            return false;
        }
        used[v] = true;
        for (auto u: g[v]) {
            if (match[u] == -1 || dfs(match[u])) {
                match[u] = v;
                return true;
            }
        }
        return false;
    };

    for (int i = 0; i < n; ++i) {
        dfs(i);
        used.assign(n, false);
    }
    int sz = 0;
    for (int i = 0; i < n_; ++i) {
        if (match[i] != -1) {
            sz++;
        }
    }
    cout << sz << "\n";
    for (int i = 0; i < n_; ++i) {
        if (match[i] != -1) {
            cout << match[i] + 1  <<  " " << i + 1 << "\n";
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


