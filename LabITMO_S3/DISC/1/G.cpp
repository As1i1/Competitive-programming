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
vector<vector<int>> g;
vector<int> colors;
set<int> clrs;

void dfs(int v) {
    set<int> d(clrs);
    for (auto u: g[v]) {
        if (colors[u] != -1) {
            d.erase(colors[u]);
        }
    }
    colors[v] = *d.begin();
    d.clear();
    for (auto u: g[v]) {
        if (colors[u] == -1) {
            dfs(u);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    g.assign(n, {});
    colors.assign(n, -1);
    for (int i = 0; i < m; ++i){
        int v, u; cin >> v >> u;
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int mx = 0;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        mx = max((int)g[i].size(), mx);
        v.push_back(i);
    }
    if (mx % 2 == 0) mx++;
    for (int i = 0; i < mx; i++) clrs.insert(i);
    shuffle(v.begin(), v.end(), gen);
    for (int i = 0; i < n; ++i) {
        if (colors[v[i]] == -1) {
            dfs(v[i]);
        }
    }

    cout << mx << "\n";
    for (int i = 0; i < n; ++i) {
        cout << colors[i] + 1 << "\n";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

