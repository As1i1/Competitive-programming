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

    int n, m;
    cin >> n >> m;
    int s = 0, t = n - 1;
    vector<Edge> edges(2 * m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;v--;
        edges[2 * i] = {v, c, 0};
        edges[2 * i + 1] = {u, c, 0};
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
    while (bfs()) {
        fill(ind.begin(), ind.end(), 0);
        int f;
        while ((f = dfs(s, INF)))
            flow += f;
    }
    bfs();
    set<int> answer;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i] != -1 && dist[j] == -1) {
                for (auto&& i_e: g[i]) {
                    if (edges[i_e].to == j) {
                        answer.insert(i_e / 2 + 1);
                        break;
                    }
                }
            }
        }
    }
    cout << answer.size() << " ";
    cout << flow << "\n";
    for (auto a: answer) {
        cout << a << " ";
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
    while (t--) {
        solve();
    }
    return 0;
}


