//
// Created by asi1i on 10/21/23.
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


list<int> g_path() {
    list<int> path;
    path.push_back(0);
    if (g[0][1]) {
        path.push_back(1);
    } else {
        path.push_front(1);
    }
    for (int i = 2; i < n; ++i) {
        auto cur = path.begin();
        for (int j = 0; j < path.size(); ++j) {
           if (g[*cur][i] == 0) {
               break;
           }
           cur = next(cur);
        }
        if (cur == path.begin()) {
            path.push_front(i);
        } else {
            path.insert(cur, i);
        }
    }
    return path;
}


void solve(){
    cin >> n;
    g.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            char c; cin >> c;
            if (c == '0') {
                g[j][i] = 1;
            } else {
                g[i][j] = 1;
            }
        }
    }

    list<int> path = g_path();
    list<int> circle;

    {
        int start = *path.begin();
        auto it = path.end();
        for (; it != path.begin();) {
            it = prev(it);
            if (g[*it][start]) {
                break;
            }
        }
        circle.splice(circle.begin(), path, path.begin(), next(it));
    }
    for (auto it = path.begin(); !path.empty();) {
        bool flag = false;
        auto it2 = circle.begin();
        for (; it2 != circle.end(); it2 = next(it2)) {
            if (g[*it][*it2]) {
//                circle.insert(it2, *it);
                flag = true;
                break;
            }
        }
        if (flag) {
            circle.splice(it2, path, path.begin(), next(it));
            it = path.begin();
        } else {
            it = next(it);
        }
    }
    for (auto u: circle) {
        cout << u + 1 << " ";
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
