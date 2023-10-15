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


struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find_set(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    bool union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            return true;
        } else {
            return false;
        }
    }
};


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        edges[i] = {u, v, w};
    }
    sort(edges.begin(), edges.end(), [&] (const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    ll ans = 0;
    DSU d = DSU(n);
    for (auto e: edges) {
        if (d.union_set(e[0], e[1])) {
            ans += e[2];
        }
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
