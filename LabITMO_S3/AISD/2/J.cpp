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
    for (int i = 0; i < m; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        g[v].push_back(u);
    }
    vector<int> dp(n, -1);
    function<void(int)> dfs = [&] (int v) {
        set<int> ke;
        int cur = 0;
        for (auto u: g[v]) {
            if (dp[u] == -1) dfs(u);
            ke.insert(dp[u]);
            while (ke.find(cur) != ke.end()) {
                cur++;
            }
        }
        dp[v] = cur;
    };
    for (int i = 0; i < n; ++i) {
        if (dp[i] == -1) {
            dfs(i);
        }
        cout << dp[i] << "\n";
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
