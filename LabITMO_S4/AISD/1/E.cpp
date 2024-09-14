//
// Created by aas1i1 on 2/23/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

int parsoch(int n, int n_, vector<vector<int>>& g) {
    vector<int> match(n_, -1);
    vector<bool> used(n, false);
    function<bool(int)> dfs = [&](int v) {
        if (used[v]) {
            return false;
        }
        used[v] = true;
        for (auto u: g[v]) {
            if (match[u] == -1 || dfs(match[u])) {
                match[u] = v;
                return true;
            }
        }
        return false;
    };

    for (int i = 0; i < n; ++i) {
        dfs(i);
        used.assign(n, false);
    }
    int sz = 0;
    for (int i = 0; i < n_; ++i) {
        if (match[i] != -1) {
            sz++;
        }
    }
    return sz;
}

void solve() {
    int n, m;
    ll a, b;
    cin >> n >> m >> a >> b;
    int n1 = 0, n2 = 0, cnt = 0;
    vector<vector<char>> field(n, vector<char>(m));
    map<pair<int, int>, int> mapping;
    vector<vector<int>> gL;
    for (int i = 0; i < n; ++i) {
        for (int j = 0;j < m; ++j) {
            cin >> field[i][j];
            if (field[i][j] == '*') {
                cnt++;
            }
        }
    }
    if (2 * b <= a) {
        cout << cnt * b;
        return;
    }
    vector<vector<bool>> used(n, vector<bool>(m, false));
    function<void(int, int, bool)> dfs = [&] (int i, int j, bool flag) {
        static vector<pair<int, int>> dxy = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        used[i][j] = true;
        if (field[i][j] == '.') {
            return;
        }
        if (mapping.find({i, j}) == mapping.end()) {
            mapping[{i, j}] = flag ? n1 : n2;
        }
        int v = flag ? n1 : n2;
        if (flag) {
            gL.emplace_back();
            n1++;
        } else {
            n2++;
        }
        for (auto [dx, dy]: dxy) {
            if (i + dx < n && i + dx >= 0 && j + dy < m && j + dy >= 0) {
                if (!used[i + dx][j + dy]) {
                    dfs(i + dx, j + dy, !flag);
                }
                if (mapping.find({i + dx, j + dy}) != mapping.end()) {
                    int u = mapping[{i + dx, j + dy}];
                    if (flag) {
                        gL[v].push_back(u);
                    } else {
                        gL[u].push_back(v);
                    }
                }
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j])
                dfs(i, j, true);
        }
    }
    int sz = parsoch(n1, n2, gL);
    cout << sz * a + (cnt - 2 * sz) * b;

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


