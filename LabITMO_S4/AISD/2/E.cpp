//
// Created by aas1i1 on 4/21/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e6, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;


bool check(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}


int get_vertex_no(int i, int j, int n) {
    return i * n + j;
}


pair<int, int> vertex_no_decode(int v, int n) {
    return {v / n, v % n};
}


void solve() {
    struct Edge {
        int to, capacity, flow;
    };

    int field_size_x, field_size_y;
    cin >> field_size_x >> field_size_y;
    int area = field_size_y * field_size_x;
    int s = -1, t = -1;
    vector<vector<char>> field(field_size_x, vector<char>(field_size_y));
    for (int i = 0; i < field_size_x; ++i) {
        for (int j = 0; j < field_size_y; ++j) {
            cin >> field[i][j];
            if (field[i][j] == 'A') {
                s = get_vertex_no(i, j, field_size_y);
            }
            if (field[i][j] == 'B') {
                t = get_vertex_no(i, j, field_size_y);
            }
        }
    }

    vector<pair<int, int>> d = {{1, 0},
                                {0, 1}};
    vector<Edge> edges;
    vector<vector<int>> g(field_size_x * field_size_y * 2);

    function<void(int, int, int)> add_vertex = [&](int v, int u, int flow) {
        edges.push_back(Edge{u, flow, 0});
        g[v].push_back(edges.size() - 1);
        edges.push_back(Edge{v, 0, 0});
        g[u].push_back(edges.size() - 1);
    };

    int constexpr INF_FLOW = 10000;
    int n = g.size();
    for (int i = 0; i < field_size_x; ++i) {
        for (int j = 0; j < field_size_y; ++j) {
            if (field[i][j] == '#') continue;
            int real_vertex = get_vertex_no(i, j, field_size_y);
            int need_flow = 1;
            if (field[i][j] == '-' || field[i][j] == 'A' || field[i][j] == 'B') {
                need_flow = INF_FLOW;
            }
            // In, Out
            add_vertex(real_vertex, real_vertex + area, need_flow);

            {
                int new_x = i + 1;
                int new_y = j;
                if (check(new_x, new_y, field_size_x, field_size_y) && field[new_x][new_y] != '#') {
                    int new_real_vertex = get_vertex_no(new_x, new_y, field_size_y);
                    add_vertex(new_real_vertex + area, real_vertex, INF_FLOW); // TODO 1?
                    add_vertex(real_vertex + area, new_real_vertex, INF_FLOW);
                }
            }

            {
                int new_x = i;
                int new_y = j + 1;
                if (check(new_x, new_y, field_size_x, field_size_y) && field[new_x][new_y] != '#') {
                    int new_real_vertex = get_vertex_no(new_x, new_y, field_size_y);
                    add_vertex(new_real_vertex + area, real_vertex, INF_FLOW); // TODO 1?
                    add_vertex(real_vertex + area, new_real_vertex, INF_FLOW);
                }
            }
        }
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
    if (flow >= INF_FLOW) {
        cout << -1;
        return;
    }
    bfs();
    set<int> answer;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i] != -1 && dist[j] == -1) {
                for (auto &&i_e: g[i]) {
                    if (edges[i_e].to == j && edges[i_e].capacity > 0) {
                        answer.insert(min(i, j));
                        break;
                    }
                }
            }
        }
    }
    for (auto v: answer) {
        auto [vx, vy] = vertex_no_decode(v, field_size_y);
        field[vx][vy] = '+';
    }
    cout << answer.size() << "\n";
    for (int i = 0; i < field_size_x; ++i) {
        for (int j = 0; j < field_size_y; ++j) {
            cout << field[i][j];
        }
        cout << "\n";
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