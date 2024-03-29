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


void solve(){
    int n;
    cin >> n;
    vector<set<int>> g(n);
    set<int> lists;
    vector<int> ans;
    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> u >> v; u--;v--;
        g[v].insert(u);
        g[u].insert(v);
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            lists.insert(i);
        }
    }
    while (ans.size() != n - 2) {
        int v = *lists.begin();
        int u = *g[v].begin();
        g[u].erase(v);
        lists.erase(lists.begin());
        ans.push_back(u);
        if (g[u].size() == 1) {
            lists.insert(u);
        }
    }
    for (auto v: ans) {
        cout << v + 1 << " ";
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
