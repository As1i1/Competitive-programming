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

vector<int> parsoch(int n, int n_, vector<vector<int>>& g) {
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> g_c(n);
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        while (v != 0) {
            v--;
            g[i].push_back(v);
            cin >> v;
        }
    }
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if (find(g[i].begin(), g[i].end(), j) == g[i].end()) {
                g_c[i].push_back(j);
            }
        }
    }
    vector<int> match = parsoch(n, m, g_c);
    vector<int> match_left = vector<int>(n, -1);
    g = vector<vector<int>>(n + m);
    for (int i = 0; i < n; ++i) {
        for (auto u : g_c[i]) {
            if (match[u] == i) {
                match_left[i] = u;
                g[u + n].push_back(i);
            } else {
                g[i].push_back(u + n);
            }
        }
    }

    vector<bool> used(n + m, false);
    function<void(int)> dfs = [&] (int v) {
        used[v] = true;
        for (auto u: g[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (match_left[i] == -1) {
            dfs(i);
        }
    }

    int all = 0, jun = 0, mad = 0;
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            all++;
            jun++;
        }
    }
    for (int i = n; i < n + m; ++i) {
        if (!used[i]) {
            all++;
            mad++;
        }
    }
    cout << all << "\n" << jun << " " << mad << "\n";
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    for (int i = n; i < n + m; ++i) {
        if (!used[i]) {
            cout << i - n + 1 << " ";
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


