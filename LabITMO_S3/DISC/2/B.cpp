//
// Created by asi1i on 12/11/23.
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
    DSU(int n) : size(n, 1), parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    vector<int> size;
    vector<int> parent;
};


void solve() {
    int n, m;
    ll s;
    cin >> n >> m >> s;
    vector<tuple<int, int, ll, int>> edges;
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        ll w;
        cin >> w;
        edges.emplace_back(u, v, w, i + 1);
    }

    sort(edges.begin(), edges.end(),
         [&](tuple<int, int, ll, int> a, tuple<int, int, ll, int> b) { return get<2>(a) > get<2>(b); });
    vector<int> used(m, 0);
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int v = get<0>(edges[i]);
        int u = get<1>(edges[i]);
        if (dsu.find_set(v) != dsu.find_set(u)) {
            dsu.union_sets(u, v);
            used[i] = 1;
        }
    }

    int cnt = 0;
    vector<int> ans;
    for (int i = m - 1; i >= 0; --i) {
        if (used[i] == 0 && get<2>(edges[i]) <= s) {
            cnt++;
            s -= get<2>(edges[i]);
            ans.push_back(get<3>(edges[i]));
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << "\n";
    for (auto i: ans) {
        cout << i << " ";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
 freopen("destroy.in", "r", stdin);
 freopen("destroy.out", "w", stdout);
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
