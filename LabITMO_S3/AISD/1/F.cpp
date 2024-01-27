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


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), g_t(n);
    vector<int> color(n, 0), ans;
    vector<bool> used(n, false);

    function<void(int)> dfs;
    function<void(int, int)> c;
    dfs = [&] (int v) {
        used[v] = true;
        for (auto u: g[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
        ans.push_back(v);
    };


    c = [&] (int v, int clr) {
        used[v] = true;
        color[v] = clr;
        for (auto u: g_t[v]) {
            if (!used[u]) {
                c(u, clr);
            }
        }
    };

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g_t[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    used.assign(n, false);
    int cur = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (!used[ans[i]]) {
            c(ans[i], cur++);
        }
    }
    used.assign(n, false);
    vector<set<int>> g_c(cur);
    function<void(int)> dfs2 = [&] (int v) {
        used[v] = true;
        for (auto u: g[v]) {
            if (color[u] != color[v]) {
                g_c[color[v]].insert(color[u]);
                if (!used[u]) {
                    dfs2(u);
                }
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs2(i);
        }
    }
    int ans_size = 0;
    for (int i = 0; i < cur; ++i) {
        ans_size += g_c[i].size();
    }
    cout << ans_size;
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
