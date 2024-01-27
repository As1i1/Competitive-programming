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
vector<vector<int>> g;

void solve(){
    int n;
    cin >> n;
    g.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            char c; cin >> c;
            if (c == '1') {
                g[i][j] = 1;
                g[j][i] = 1;
            }
        }
    }

    deque<int> q;
    for (int i = 0; i < n; ++i) {
        q.push_back(i);
    }

    for (int k = 0; k < n * (n - 1); k++) {
        int first = q[0];
        int second = q[1];
        if (g[first][second] == 0) {
            int i = 2;
            while (g[first][q[i]] == 0 || g[second][q[i + 1]] == 0) {
                ++i;
            }
            for (int j = 1; j <= i - j + 1; ++j) {
                int t = q[j];
                q[j] = q[i - j + 1];
                q[i - j + 1] = t;
            }
        }
        q.push_back(first);
        q.pop_front();
    }
    for (auto e: q) {
        cout << e + 1 << " ";
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
