//
// Created by AMD on 13.01.2022.
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
vector<ll> a;


ll dfs(int v, int p = -1){
    if (a[v] < 0)
        return 0;
    ll ans = a[v];
    for (auto u: g[v]){
        if (u == p) continue;
        ans = (ans + dfs(u, v)) % MOD;
    }
    return ans;
}


void solve(){
    int n, c = 1;
    cin >> n;
    g.resize(n);
    a.resize(n);
    for (int i = 1; i < n; ++i){
        int p;
        cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        c *= (i + 1);
    }
    vector<ll> a1 = a;
    ll ans = dfs(0);
    next_permutation(a.begin(), a.end());
    int cnt = 1;
    map<int, int> cnt2;
    while (c != cnt){
        cnt++;
        ll t = dfs(0);
        cnt2[t]++;
        ans = (ans + t) % MOD;
        next_permutation(a.begin(), a.end());
    }
    for (auto p: cnt2){
        cout << p.first << " " << p.second << "\n";
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
