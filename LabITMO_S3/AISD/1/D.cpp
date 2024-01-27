//
// Created by asi1i on 10/15/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
int n, m;
vector<map<int, int>> g;
vector<int> tin, fup;
vector<pair<int, int>> ans;
vector<bool> used;
int t;


void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = t;
    fup[v] = t;
    t++;
    for (auto [u, cnt] : g[v]) {
        if (u == p) continue;
        if (used[u]) {
            fup[v] = min(fup[v], tin[u]);
        } else {
            dfs(u, v);
            fup[v] = min(fup[v], fup[u]);
            if (fup[u] > tin[v] && cnt == 1) {
                ans.emplace_back(v, u);
            }
        }
    }
}


void solve(){
    cin >> n >> m;
    g.resize(n);
    tin.resize(n, INF);
    fup.resize(n, INF);
    used.resize(n, false);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (v == u) continue;
        if (g[u].find(v) != g[u].end()) {
            g[u][v]++;
            g[v][u]++;
        } else {
            g[u][v] = 1;
            g[v][u] = 1;
        }
    }
    t = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    for (auto [u, v]: ans) {
        g[u].erase(v);
        g[v].erase(u);
    }

    used.assign(n, false);
    vector<int> color(n);
    function<void(int, int)> c = [&] (int v, int clr) {
        used[v] = true;
        color[v] = clr;
        for (auto [u, cnt]: g[v]) {
            if (!used[u]) {
                c(u, clr);
            }
        }
    };
    int cur = 1;
    for (int i = 0;i < n; ++i) {
        if (!used[i]) c(i, cur++);
    }
    cout << cur - 1 << "\n";
    for (int i = 0; i < n; ++i) {
        cout << color[i] << " ";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
//    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
//    while(t--){
    solve();
//    }
    return 0;
}
