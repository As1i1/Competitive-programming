//
// Created by asi1i on 12/11/23.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> wes(n);
    for (int i = 0; i < n; ++i) {
        cin >> wes[i];
    }
    set<vector<int>> C;
    for (int i = 0; i < m; ++i) {
        vector<int> v;
        int sz; cin >> sz;
        for (int j = 0; j < sz; ++j) {
            int x; cin >> x; v.push_back(x - 1);
        }
        sort(v.begin(), v.end());
        C.insert(v);
    }


}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
    freopen("cycles.in", "r", stdin);
    freopen("cycles.out", "w", stdout);
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
