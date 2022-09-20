//
// Created by Dima on 30.08.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<int> g;
vector<bool> used;
int n;

int dfs(int v, int d = 0){
    if (used[v]) return -1;
    if (v == n - 1) return d;
    used[v] = true;
    return dfs(g[v], d + 1);
}


void solve(){
    cin >> n;
    g.resize(n);
    used.assign(n, false);
    for (int i = 0; i < n; ++i){
        int a; cin >> a; a--;
        g[i] = a;
    }
    int ans = dfs(0);
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
 //   cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
