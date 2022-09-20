//
// Created by AMD on 01.03.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<set<int>> g;
vector<int> used, colors;


void dfs(int v, int color){
    used[v] = color;
    for (auto u: g[v]){
        if (!used[u]) dfs(u, color);
    }
}



void solve(){
    int m, n, q;
    cin >> m >> n >> q;
    g.resize(q);
    used.resize(q, 0);
    vector<vector<vector<int>>> stocks(m);
    int v = 0;
    for (int i = 0; i < m; ++i){
        int k, s = 0; cin >> k;
        for (int j = 0; j < k; ++j){
            int x; cin >> x;
            stocks[i].push_back({s, s + x, v});
            v++;
            s += x;
        }
    }
    for (int i = 0; i < m - 1; ++i){
        int k1 = 0;
        for (int j = 0; j < stocks[i].size(); ++j){
            while (k1 < stocks[i + 1].size()){
                int l1 = stocks[i][j][0], r1 = stocks[i][j][1], l2 = stocks[i + 1][k1][0], r2 = stocks[i + 1][k1][1];
                if (l1 >= r2 || l2 >= r1){
                    break;
                }
                else{
                    g[stocks[i][j][2]].insert(stocks[i + 1][k1][2]);
                    g[stocks[i + 1][k1][2]].insert(stocks[i][j][2]);
                    k1++;
                }
            }
        }
    }
    for (int i = 1; i < m; ++i){
        int k1 = 0;
        for (int j = 0; j < stocks[i].size(); ++j){
            while (k1 < stocks[i - 1].size()){
                int l1 = stocks[i][j][0], r1 = stocks[i][j][1], l2 = stocks[i - 1][k1][0], r2 = stocks[i - 1][k1][1];
                if (l1 >= r2 || l2 >= r1){
                    break;
                }
                else{
                    g[stocks[i][j][2]].insert(stocks[i - 1][k1][2]);
                    g[stocks[i - 1][k1][2]].insert(stocks[i][j][2]);
                    k1++;
                }
            }
        }
    }
    int color = 1;
    for (int i = 0; i < q; ++i){
        if (!used[i]){
            dfs(i, color);
            color++;
        }
    }
    colors.resize(color);
    for (int i = 0; i < q; ++i){
        colors[used[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < color; ++i){
        ans = max(ans, colors[i]);
    }
    cout << ans;
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
