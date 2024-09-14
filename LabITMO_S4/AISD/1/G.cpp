//
// Created by aas1i1 on 3/14/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

vector<int> khun(int n, int n_, vector<vector<int>> &g) {
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
    return match;
}


void solve() {
    int m, k, n;
    cin >> m >> k >> n;
    if (n > k || n > m) {
        cout << "NO";
        return;
    }
    int t;
    cin >> t;
    vector<bool> alone_green(m, false), alone_yellow(k, false);
    set<pair<int, int>> loveless_dragons;
    while (t--) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        loveless_dragons.emplace(v, u - m);
    }
    int q;
    cin >> q;
    while (q--) {
        int v;
        cin >> v;
        v--;
        if (v >= m) {
            alone_yellow[v - m] = true;
        } else {
            alone_green[v] = true;
        }
    }
    vector<vector<int>> g(m + k - n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            if (loveless_dragons.find({i, j}) != loveless_dragons.end()) continue;
            g[i].push_back(j);
        }
        if (alone_green[i]) continue;
        for (int j = k; j < k + m - n; ++j) {
            g[i].push_back(j);
        }
    }
    for (int i = m; i < m + k - n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (alone_yellow[j]) continue;
            g[i].push_back(j);
        }
    }
    vector<int> match = khun(m + k - n, k + m - n, g);
    vector<pair<int, int>> ans;
    for (int i = 0; i < k; ++i) {
        if (match[i] == -1) {
            cout << "NO";
            return;
        }
        if (match[i] < m) {
            ans.emplace_back(match[i], i + m);
        }
    }
    for (int i = k; i < k + m - n; ++i) {
        if (match[i] == -1) {
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    for (auto [f, s]: ans) {
        cout << f + 1 << " " << s + 1 << "\n";
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


