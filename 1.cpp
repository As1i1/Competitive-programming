#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
const int N = 7;
const int FACT = 5040;
vector<vector<vector<int>>> graphs;


bool check_sv(int index) {
    vector<bool> used(N, false);
    function<void(int)> f;
    f = [&] (int v) {
        used[v] = true;
        for (int i = 0; i < N; ++i) {
            if (!used[i] && graphs[index][v][i] == 1) {
                f(i);
            }
        }
    };
    f(0);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) return false;
//        int cnt = 0;
//        for (int j = 0; j < N; ++j) {
//            cnt += graphs[index][i][j];
//        }
//        if (cnt < ((N + 1) / 2) - 1) return false;
    }
    return true;
}


bool check_cls(vector<vector<int>> a, vector<vector<int>> b) {
    vector<int> per = {0, 1, 2, 3, 4, 5, 6};
    vector<bool> used = vector<bool>(N, false);
    bool ans = true;
    function<void(int, int)> f;
    f = [&] (int v, int v2) {
        used[v] = true;
        for (int i = 0; i < N; ++i) {
            if (a[v][i] == 1 && b[per[v2]][per[i]] == 1){
                if (!used[v]) {
                    f(i, i);
                }
            } else if (a[v][i] != b[per[v2]][per[i]]) {
                ans = false;
                return;
            }
        }
    };
    for (int i = 0; i < FACT; i++) {
        used = vector<bool>(N, false);
        ans = true;
        f(0, 0);
        next_permutation(per.begin(), per.end());
        if (ans) {
            return true;
        }
    }
    return false;
}


bool check_e(int index) {
    vector<bool> used(N, false);
    function<void(int)> f;
    f = [&] (int v) {
        used[v] = true;
        for (int i = 0; i < N; ++i) {
            if (!used[i] && graphs[index][v][i] == 1) {
                f(i);
            }
        }
    };
    f(0);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) return false;
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            cnt += graphs[index][i][j];
        }
        if (cnt % 2 != 0) return false;
    }
    return true;
}


void print_g(vector<vector<int>> g) {
    cout << "-------------------\n";
    for (int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-------------------";
}


void solve() {
    vector<pair<int, int>> edges;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            edges.emplace_back(i, j);
        }
    }
    for (int i = 0; i < (1 << edges.size()); ++i) {
        vector<vector<int>> g(N, vector<int>(N, 0));
        int cnt = 0;
        for (int j = 0; j < edges.size(); ++j) {
            if (i & (1 << j)) {
                auto [u, v] = edges[j];
                g[u][v] = 1;
                g[v][u] = 1;
                cnt++;
            }
        }
        if (cnt != 7) {
            continue;
        }
        graphs.push_back(g);
        if (!check_sv(graphs.size() - 1)) {
            graphs.pop_back();
            continue;
        }
        int a;
        for (int j = 0; j < graphs.size() - 1; ++j) {
            if (check_cls(graphs[j], g)) {
                graphs.pop_back();
                goto l;
                break;
            }
        }
    }
    cout << graphs.size();
    for (auto g: graphs) {
    print_g(g);
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
//    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
    solve();
    return 0;
}
