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
vector<vector<int>> g_t;

auto comps() {
    n *= 2;
    vector<int> color(n, 0), ans;
    vector<bool> used(n, false);

    function<void(int)> dfs;
    function<void(int, int)> c;
    dfs = [&] (int v) {
        used[v] = true;
        for (auto u: g[v]) {
            if (!used[u]) {
                dfs(u);
            }
        }
        ans.push_back(v);
    };


    c = [&] (int v, int clr) {
        used[v] = true;
        color[v] = clr;
        for (auto u: g_t[v]) {
            if (!used[u]) {
                c(u, clr);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    used.assign(n, false);
    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (!used[ans[i]]) {
            c(ans[i], cur++);
        }
    }
    n /= 2;
    return color;
}


void solve(){
    int m;
    cin >> n >> m;
    map<string, int> names;
    vector<string> i_names(n);
    g.assign(2 * n, {});
    g_t.assign(2 * n, {});
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        names[name] = i;
        i_names[i] = name;
    }

    for (int i = 0; i < m; ++i) {
        string name1, im, name2;
        cin >> name1 >> im >> name2;
        int u = names[name1.substr(1, name1.size())];
        int v = names[name2.substr(1, name2.size())];
        if (name1[0] == '+') {
            if (name2[0] == '+') {
                g[u + n].push_back(v + n);
                g[v].push_back(u);
                g_t[v + n].push_back(u + n);
                g_t[u].push_back(v);
            } else {
                g[u + n].push_back(v);
                g[v + n].push_back(u);
                g_t[v].push_back(u + n);
                g_t[u].push_back(v + n);
            }
        } else {
            if (name2[0] == '+') {
                g[u].push_back(v + n);
                g[v].push_back(u + n);
                g_t[v + n].push_back(u);
                g_t[u + n].push_back(v);
            } else {
                g[u].push_back(v);
                g[v + n].push_back(u + n);
                g_t[v].push_back(u);
                g_t[u + n].push_back(v + n);
            }
        }
    }

    auto comp = comps();
    vector<bool> val(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (comp[i] == comp[n + i]) {
            cout << -1;
            return;
        }
        if (comp[i] < comp[n + i]) {
            val[i] = true;
            cnt++;
        } else {
            val[i] = false;
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; ++i) {
        if (val[i]) {
            cout << i_names[i] << "\n";
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
