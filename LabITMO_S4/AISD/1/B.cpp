//
// Created by aas1i1 on 3/12/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

vector<int> cun(int n, int n_, vector<vector<int>> &g, vector<int> &order) {
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
        dfs(order[i]);
        used.assign(n, false);
    }
    return match;
}

vector<int> re_match(vector<int> left, vector<int> right, int n, int m) {
    for (int i = 0; i < n; ++i) {
        left.insert(left.begin(), -1);
    }
    for (int i = n; i < m + n; ++i) {
        if (left[i] != -1)
            left[left[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        right.push_back(-1);
    }
    for (int i = 0; i < n; ++i) {
        if (right[i] != -1) {
            right[i] += n;
            right[right[i]] = i;
        }
    }
    function<void(int)> dfs = [&] (int /* R */ v)  {
        int next = left[right[v]];
        if (right[next] == -1) {
            left[next] = -1;
            left[right[v]] = v;
            left[v] = right[v];
        } else {
            dfs(next);
            left[v] = right[v];
            left[right[v]] = v;
        }
    };
    for (int i = n; i < m + n; ++i) {
        if (left[i] == -1 && right[i] != -1) {
            dfs(i);
        }
    }
    return left;
}

void solve() {
    int n, m, e;
    cin >> n >> m >> e;
    vector<int> left(n), right(m);
    for (int i = 0; i < n; ++i) {
        cin >> left[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> right[i];
    }
    vector<vector<int>> g_left(n);
    vector<vector<int>> g_right(m);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < e; ++i) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g_left[v].push_back(u);
        g_right[u].push_back(v);
        mp[{v, u}] = i;
    }
    vector<int> order_left(n), order_right(m);
    for (int i = 0; i < n; ++i) {
        order_left[i] = i;
    }
    sort(order_left.begin(), order_left.end(), [&](int i, int j) {
        return left[i] > left[j];
    });
    for (int j = 0; j < m; ++j) {
        order_right[j] = j;
    }
    sort(order_right.begin(), order_right.end(), [&](int i, int j) {
        return right[i] > right[j];
    });
    auto left_match = cun(n, m, g_left, order_left);
    auto right_match = cun(m, n, g_right, order_right);
    auto result_match = re_match(left_match, right_match, n, m);
    ll res = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (result_match[i] != -1) {
            res += left[i];
            res += right[result_match[i] - n];
            cnt++;
        }
    }
    cout << res << "\n" << cnt << "\n";
    for (int i = 0; i < n; ++i) {
        if (result_match[i] != -1) {
            cout << mp[{i, result_match[i] - n}] + 1 << " ";
        }
    }
}

/*
2 3 4
1 2
1 2 3
1 1
1 2
2 2
2 3
 */


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


