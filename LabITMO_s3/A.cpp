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
    vector<vector<int>> g(n);
    vector<int> color(n, 0), ans;
    vector<bool> used(n, false);
    function<void(int)> dfs;
    function<void(int)> c;
    dfs = [&] (int v) {
        used[v] = true;
        for (auto u: g[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
        ans.push_back(v);
    };

    bool circle = false;
    c = [&] (int v) {
        color[v] = 1;
        for (auto u: g[v]) {
            if (color[u] == 1) {
                circle = true;
                return;
            } else if (color[u] == 0) {
                c(u);
            }
        }
        color[v] = 2;
    };

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            c(i);
        }
    }
    if (circle) {
        cout << -1;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto u: ans) {
        cout << u + 1 << " ";
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
