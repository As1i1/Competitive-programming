//
// Created by Dubinin Dmitrii on 10/31/23.
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
    int n, r;
    cin >> n >> r;
    r--;
    vector<vector<int>> g(n);
    map<pair<int, int>, int> edges;
    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
        edges[make_pair(min(u, v), max(u, v))] = i;
    }
    vector<int> dp(n, -1);
    function<void(int, int)> dfs = [&] (int v, int p) {
        int cur = 0;
        for (auto u: g[v]) {
            if (u == p) continue;
            if (dp[u] == -1) dfs(u, v);
            cur ^= (dp[u] + 1);
        }
        dp[v] = cur;
    };
    dfs(r, -1);
    if (dp[r] != 0) {
        pair<int, int> ans = {-1, -1};
        function<void(int, int, int)> dfs_dubinin = [&](int v, int p, int _xor) {
            for (auto u: g[v]) {
                if (u == p) continue;
                int tmp = dp[v] ^ (dp[u] + 1);
                if (tmp == _xor) {
                    ans = {min(v, u), max(u, v)};
                    return;
                }
                dfs_dubinin(u, v, (tmp ^ _xor) - 1);
                if (ans != make_pair(-1, -1)) return;
            }
        };
        dfs_dubinin(r, -1, 0);
        assert(ans.first != -1 && ans.second != -1);
        cout << "1\n" << edges[ans] + 1;
    } else {
        cout << "2";
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
    while (t--) {
        solve();
    }
    return 0;
}
