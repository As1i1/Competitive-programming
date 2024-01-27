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
vector<vector<int>> g;
vector<int> tin, fup, ans;
map<pair<int, int>, int> edges;
vector<bool> used;
int t;


void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = t;
    fup[v] = t;
    t++;
    for (auto u: g[v]) {
        if (u == p) continue;
        if (used[u]) {
            fup[v] = min(fup[v], tin[u]);
        } else {
            dfs(u, v);
            fup[v] = min(fup[v], fup[u]);
            if (fup[u] > tin[v]) {
                ans.push_back(edges[{max(v, u), min(v, u)}]);
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
        edges[{max(u, v), min(u, v)}] = i + 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    t = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto e: ans) {
        cout << e << "\n";
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
