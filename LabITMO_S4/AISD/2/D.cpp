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

        int field_size;
        cin >> field_size;
        vector<vector<char>> field(field_size, vector<char>(field_size));
        for (int i = 0; i < field_size; ++i) {
            for (int j = 0; j < field_size; ++j) {
                cin >> field[i][j];
            }
        }
        vector<int> expected(field_size);
        for (int i = 0; i < field_size; ++i) {
            cin >> expected[i];
        }
        vector<Edge> edges;
        vector<vector<int>> g(field_size + field_size * (field_size - 1) / 2 + 5);
        int s = g.size() - 2;
        int t = g.size() - 1;
        int current_number = field_size;
        for (int i = 0; i < field_size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (field[i][j] == '.') {
                    edges.push_back(Edge{ i, 3, 0});
                    g[current_number].push_back(edges.size() - 1);
                    edges.push_back(Edge{ current_number, 0, 0});
                    g[i].push_back(edges.size() - 1);

                    edges.push_back( Edge{j, 3, 0});
                    g[current_number].push_back(edges.size() - 1);
                    edges.push_back( Edge{current_number, 0, 0});
                    g[j].push_back(edges.size() - 1);
                    current_number++;
                } else if (field[i][j] == 'W') {
                    expected[i] -= 3;
                } else if (field[i][j] == 'w') {
                    expected[i] -= 2;
                    expected[j] -= 1;
                } else if (field[i][j] == 'L') {
                    expected[j] -= 3;
                } else if (field[i][j] == 'l') {
                    expected[j] -= 2;
                    expected[i] -= 1;
                }
            }
        }

        for (int i = 0; i < field_size; ++i) {
            edges.push_back( Edge{t, expected[i], 0});
            g[i].push_back(edges.size() - 1);
            edges.push_back(Edge{i, 0, 0});
            g[t].push_back(edges.size() - 1);
        }
        for (int i = field_size; i < current_number; ++i) {
            edges.push_back(Edge{i, 3, 0});
            g[s].push_back(edges.size() - 1);
            edges.push_back(Edge{s, 0, 0});
            g[i].push_back(edges.size() - 1);
        }

        int n = g.size();
        vector<int> dist(n);
        vector<int> ind(n);
        vector<bool> used(n, false);
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
        for (int i = field_size; i < current_number; ++i) {
            Edge t1 = edges[g[i][0]];
            Edge t2 = edges[g[i][1]];
            if (t1.flow == 3) {
                field[t1.to][t2.to] = 'W';
                field[t2.to][t1.to] = 'L';
            } else if (t1.flow == 2) {
                field[t1.to][t2.to] = 'w';
                field[t2.to][t1.to] = 'l';
            } else if (t1.flow == 1) {
                field[t1.to][t2.to] = 'l';
                field[t2.to][t1.to] = 'w';
            } else if (t1.flow == 0) {
                field[t1.to][t2.to] = 'L';
                field[t2.to][t1.to] = 'W';
            }
        }

        for (int i = 0; i < field_size; ++i) {
            for (int j = 0; j < field_size; ++j) {
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


