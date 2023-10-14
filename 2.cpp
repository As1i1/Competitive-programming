//
// Created by asi1i on 10/9/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

int n = 6;



int F_count(vector<vector<int>> g) {
    int ans = 0;
    vector<vector<char>> used(n);
    for (int i = 0; i < n; ++i)
        used[i].resize(g[i].size());
    for (int i = 0; i < n; ++i)
        for (size_t j = 0; j < g[i].size(); ++j)
            if (!used[i][j]) {
                used[i][j] = true;
                int v = g[i][j], pv = i;
                vector<int> facet;
                for (;;) {
                    facet.push_back(v);
                    auto it = find(g[v].begin(), g[v].end(), pv);
                    if (++it == g[v].end())
                        it = g[v].begin();
                    if (used[v][it - g[v].begin()])
                        break;
                    used[v][it - g[v].begin()] = true;
                    pv = v, v = *it;
                }
                ans++;
            }
    return ans;
}

void print_g(vector<vector<int>> g) {
    cout << "-------------------\n";
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-------------------";
}

void solve() {
    vector<vector<vector<int>>> res;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.emplace_back(i, j);
        }
    }
    for (int i = 0; i < (1 << edges.size()); ++i) {
        vector<vector<int>> g(n, vector<int>(n, 0));
        int cnt = 0;
        for (int j = 0; j < edges.size(); ++j) {
            if (i & (1 << j)) {
                auto [u, v] = edges[j];
                g[u][v] = 1;
                g[v][u] = 1;
                cnt++;
            }
        }
        if (n - cnt + F_count(g) + 1 != 2) {
            continue;
        }
        print_g(g); cout << endl;
    }
    cout << res.size();
    for (auto g: res) {
        print_g(g);
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

