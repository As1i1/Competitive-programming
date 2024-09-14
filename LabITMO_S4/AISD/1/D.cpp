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

vector<int> parsoch(int n, int n_, vector<vector<int>> &g) {
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
    return match;
}


ld delta(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return (a.second - b.second) * 1.0 / 60;
    } else {
        if (a.first < b.first) {
            int minus = 60 - a.second;
            return -(b.first - a.first - 1) - (b.second + minus) * 1.0 / 60;
        } else {
            int minus = 60 - b.second;
            return (a.first - b.first - 1) + (a.second + minus) * 1.0 / 60;
        }
    }
}


void solve() {
    int n, v;
    cin >> n >> v;
    vector<tuple<pair<int, int>, ll, ll>> vertex(n);
    for (int i = 0; i < n; ++i) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        vertex[i] = {{h, m}, x, y};
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            ld cur_delta = delta(get<0>(vertex[i]), get<0>(vertex[j]));
            if (cur_delta > 0) {
                ld dist = sqrtl((get<1>(vertex[i]) - get<1>(vertex[j])) * (get<1>(vertex[i]) - get<1>(vertex[j])) +
                               (get<2>(vertex[i]) - get<2>(vertex[j])) * (get<2>(vertex[i]) - get<2>(vertex[j])));
                ld time = dist / v;
                if (time < cur_delta || abs(time - cur_delta) < eps) {
                    g[j].push_back(i);
                }
            }
        }
    }
    vector<int> match = parsoch(n, n, g);
    vector<int> r_match = vector<int>(n, -1);
    for (int i = 0; i < n; ++i) {
        if (match[i] != -1) {
            r_match[match[i]] = i;
        }
    }
    vector<bool> used(n, false);
    function<void(int, int, bool)> dfs = [&](int v, int p, bool flag) {
        if (p != v) dfs(v, v, !flag);
        if (flag) {
            used[v] = true;
            if (r_match[v] != -1 && r_match[v] != p) dfs(r_match[v], v, !flag);
        } else {
            if (match[v] != -1 && match[v] != p) dfs(match[v], v, !flag);
        }
    };
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i])  {
            dfs(i, -1, true);
            cnt++;
        }
    }
    cout << cnt;
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


