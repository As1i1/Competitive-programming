//
// Created by asi1i on 10/15/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
int n;
vector<vector<int>> g;


bool check(int m) {
    vector<int> color(n, 0), ans;
    vector<bool> used(n, false);

    function<void(int)> dfs;
    function<void(int, int)> c;
    dfs = [&] (int v) {
        used[v] = true;
        for (int i = 0; i < n; ++i) {
            if (i == v) continue;
            if (g[v][i] > m) continue;
            if (!used[i]) {
                dfs(i);
            }
        }
        ans.push_back(v);
    };


    c = [&] (int v, int clr) {
        used[v] = true;
        color[v] = clr;
        for (int i = 0; i < n; ++i) {
            if (i == v) continue;
            if (g[i][v] > m) continue;
            if (!used[i]) {
                c(i, clr);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    used.assign(n, false);
    int cur = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (!used[ans[i]]) {
            c(ans[i], cur++);
        }
    }
    return cur == 2;
}


bool check2(int m) {
    for (int i = 0; i < n; ++i) {
        vector<bool> used(n, false);

        function<void(int)> dfs;
        dfs = [&](int v) {
            used[v] = true;
            for (int i = 0; i < n; ++i) {
                if (i == v) continue;
                if (g[v][i] > m) continue;
                if (!used[i]) {
                    dfs(i);
                }
            }
        };
        dfs(i);
        for (int j = 0; j < n; ++j) {
            if (!used[j]) return false;
        }
    }
    return true;
}


void solve(){
    cin >> n;
    g.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    if (n == 1) {
        cout << "0";
        return;
    }
    int l = -1, r = INF + 100;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    for (int d = -2; d < 3; d++) {
        if (check(l + d)) {
            cout << l + d;
            return;
        }
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
    while(t--){
        solve();
    }
    return 0;
}
