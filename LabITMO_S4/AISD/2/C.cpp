//
// Created by aas1i1 on 4/20/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;


void solve() {
    struct Edge {
        int to, capacity, flow;
    };

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;t--;
    vector<Edge> edges(2 * m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        edges[2 * i] = {v, 1, 0};
        edges[2 * i + 1] = {u, 0, 0};
        g[u].push_back(2 * i);
        g[v].push_back(2 * i + 1);
    }

    vector<int> dist(n);
    vector<int> ind(n);
    function<bool()> bfs = [&]() {
        queue<int> queue;
        queue.push(s);
        fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            for (auto i: g[u]) {
                Edge e = edges[i];
                if (e.flow < e.capacity)
                    if (dist[e.to] == -1) {
                        dist[e.to] = dist[u] + 1;
                        queue.push(e.to);
                    }
            }
        }
        return dist[t] != -1;
    };

    function<int(int, int)> dfs = [&](int u, int flow_dfs) {
        if (flow_dfs == 0 || u == t)
            return flow_dfs;
        while (ind[u] < g[u].size()) {
            int i = g[u][ind[u]];
            Edge e = edges[i];
            if (dist[u] + 1 != dist[e.to]) {
                ind[u]++;
                continue;
            }
            int flow_dfs2 = min(flow_dfs, e.capacity - e.flow);
            flow_dfs2 = dfs(e.to, flow_dfs2);
            if (flow_dfs2 != 0) {
                edges[i].flow += flow_dfs2;
                edges[i ^ 1].flow -= flow_dfs2;
                return flow_dfs2;
            }
            ind[u]++;
        }
        return 0;
    };

    int flow = 0;
    while (bfs() && flow < 2) {
        fill(ind.begin(), ind.end(), 0);
        int f;
        while ((f = dfs(s, INF)))
            flow += f;
    }
    if (flow < 2) {
        cout << "NO";
        return;
    }

    vector<Edge*> path;
    function<bool(int)> find_path = [&](int v) {
        if (v == t) {
            return true;
        }
        for (auto i: g[v]) {
            if (edges[i].flow > 0) {
                path.push_back(&edges[i]);
                edges[i].flow -= 1;
                if (find_path(edges[i].to)) {
                    return true;
                }
                edges[i].flow += 1;
                path.pop_back();
            }
        }
        return false;
    };
    vector<bool> used(n, false);
    find_path(s);
    vector<Edge*> path1, path2;
    for (auto&& e: path) {
        if (used[e->to]) {
            while (path1.back()->to != e->to) {
                path1.back()->flow += 1;
                path1.pop_back();
            }
        }
        used[e->to] = true;
        path1.push_back(e);
    }
    used = vector<bool>(n, false);
    path = vector<Edge*>();
    find_path(s);
    for (auto&& e: path) {
        if (used[e->to]) {
            while (path2.back()->to != e->to) {
                path2.back()->flow += 1;
                path2.pop_back();
            }
        }
        used[e->to] = true;
        path2.push_back(e);
    }
    cout << "YES\n" << s + 1 << " ";
    for (auto p: path1) {
        cout << p->to + 1 << " ";
    }
    cout << "\n" << s + 1 << " ";
    for (auto p: path2) {
        cout << p->to + 1 << " ";
    }
    cout << "\n";
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


