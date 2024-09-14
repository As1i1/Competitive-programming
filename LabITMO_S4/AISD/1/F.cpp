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

struct line {
    int x1, x2;
    int y1, y2;
};

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

void solve() {
    int n;
    cin >> n;
    vector<pair<line, int>> lines(n);
    map<int, int> vert, horz;
    for (int i = 0; i < n; ++i) {
        line &cur = lines[i].first;
        cin >> cur.x1 >> cur.y1 >> cur.x2 >> cur.y2;
        if (cur.x2 == cur.x1) {
            lines[i].second = 1;
            vert[i] = vert.size();
        } else {
            lines[i].second = 2;
            horz[i] = horz.size();
        }
    }
    vector<vector<int>> g(vert.size());
    for (int i = 0; i < n; ++i) {
        if (lines[i].second == 2) continue;
        for (int j = 0; j < n; ++j) {
            if (i == j || lines[j].second == 1) continue;
            int mn_x = min(lines[j].first.x1, lines[j].first.x2);
            int mx_x = max(lines[j].first.x1, lines[j].first.x2);
            int mn_y = min(lines[i].first.y1, lines[i].first.y2);
            int mx_y = max(lines[i].first.y1, lines[i].first.y2);
            if (mn_x <= lines[i].first.x1 && lines[i].first.x1 <= mx_x &&
               mn_y <= lines[j].first.y1 && lines[j].first.y1 <= mx_y) {
                g[vert[i]].push_back(horz[j]);
            }
        }
    }
    vector<int> match = parsoch(vert.size(), horz.size(), g);
    vector<int> match_left = vector<int>(vert.size(), -1);
    vector<vector<int>> g_ = vector<vector<int>>(n);
    for (int i = 0; i < n; ++i) {
        if (lines[i].second == 2) continue;
        for (auto u: g[vert[i]]) {
            if (match[u] == vert[i]) {
                match_left[vert[i]] = u;
                g_[u + vert.size()].push_back(vert[i]);
            } else {
                g_[vert[i]].push_back(u + vert.size());
            }
        }
    }

    vector<bool> used(n, false);
    function<void(int)> dfs = [&](int v) {
        used[v] = true;
        for (auto u: g_[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
    };

    for (int i = 0; i < vert.size(); ++i) {
        if (match_left[i] == -1) {
            dfs(i);
        }
    }

    int all = 0;
    for (int i = 0; i < vert.size(); ++i) {
        if (used[i]) {
            all++;
        }
    }
    for (int i = vert.size(); i < vert.size() + horz.size(); ++i) {
        if (!used[i]) {
            all++;
        }
    }
    cout << all;
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


