//
// Created by aas1i1 on 5/11/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;
#define int ll

struct Edge {
    int v;
    int to;
    int capacity;
    int cost;
    int flow;
};


vector<int> FordBellman(vector<Edge> &edges, int s, int t, int n) {
    vector<ll> d(n, ll_INF);
    vector<int> p(n, -1);
    d[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            ll v = edges[j].v, u = edges[j].to, c = edges[j].capacity, w = edges[j].cost, f = edges[j].flow;
            if (d[v] != ll_INF && c != f) {
                if (d[v] + w < d[u]) {
                    d[u] = min(d[u], d[v] + w);
                    p[u] = j;
                }
            }
        }
    }
    if (d[t] == ll_INF) {
        return {};
    }
    vector<int> path;
    for (int cur = p[t]; cur != -1; cur = p[edges[cur].v]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int s = 0, t = n - 1;
    vector<Edge> edges(2 * m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        Edge e{};
        cin >> e.v >> e.to >> e.capacity >> e.cost;
        e.v--;
        e.to--;
        edges[2 * i] = e;
        edges[2 * i + 1] = {e.to, e.v, 0, -e.cost, 0};
        g[e.v].push_back(2 * i);
        g[e.to].push_back(2 * i + 1);
    }

    while (true) {
        vector<int> path = FordBellman(edges, s, t, n);
        if (path.empty()) {
            break;
        }
        int mn_f = INF;
        for (auto &&cur: path) {
            mn_f = min(edges[cur].capacity - edges[cur].flow, mn_f);
        }
        if (mn_f == 0) {
            break;
        }
        for (auto &&cur: path) {
            edges[cur].flow += mn_f;
            edges[cur ^ 1].flow -= mn_f;
        }
    }

    ll res = 0;
    for (int i = 0; i < m; ++i) {
        res += edges[2 * i].cost * edges[2 * i].flow;
    }
    cout << res;
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


