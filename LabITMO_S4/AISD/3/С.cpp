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
    int r1, s1, p1;
    int r2, s2, p2;
    cin >> r1 >> s1 >> p1;
    cin >> r2 >> s2 >> p2;
    int n = 8;
    int m = 3 * 3 + 6; // 15
    int s = 0;
    int t = 7;
    vector<Edge> edges(2 * m);
    vector<vector<int>> g(n);

    edges[0] = {0, 1, r1, 0, 0};
    edges[1] = {1, 0, 0, 0, 0};

    edges[2] = {0, 2, s1, 0, 0};
    edges[3] = {2, 0, 0, 0, 0};

    edges[4] = {0, 3, p1, 0, 0};
    edges[5] = {3, 0, 0, 0, 0};

    edges[6] = {4, 7, r2, 0, 0};
    edges[7] = {7, 4, 0, 0, 0};

    edges[8] = {5, 7, s2, 0, 0};
    edges[9] = {7, 5, 0, 0, 0};

    edges[10] = {6, 7, p2, 0, 0};
    edges[11] = {7, 6, 0, 0, 0};

    edges[12] = {1, 4, INF, 0, 0}; // r1 -> r2
    edges[13] = {4, 1, 0, 0, 0};

    edges[14] = {1, 5, INF, 1, 0}; // r1 -> s2
    edges[15] = {5, 1, 0, -1, 0};

    edges[16] = {1, 6, INF, 0, 0}; // r1 -> p2
    edges[17] = {6, 1, 0, 0, 0};

    edges[18] = {2, 4, INF, 0, 0}; // s1 -> r2
    edges[19] = {4, 2, 0, 0, 0};

    edges[20] = {2, 5, INF, 0, 0}; // s1 -> s2
    edges[21] = {5, 2, 0, 0, 0};

    edges[22] = {2, 6, INF, 1, 0}; // s1 -> p2
    edges[23] = {6, 2, 0, -1, 0};

    edges[24] = {3, 4, INF, 1, 0}; // p1 -> r2
    edges[25] = {4, 3, 0, -1, 0};

    edges[26] = {3, 5, INF, 0, 0}; // p1 -> s2
    edges[27] = {5, 3, 0, 0, 0};

    edges[28] = {3, 6, INF, 0, 0}; // p1 -> p2
    edges[29] = {6, 3, 0, 0, 0};



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
    cout << max(res, 0ll);
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


