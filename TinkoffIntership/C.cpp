//
// Created by aas1i1 on 4/15/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;


void solve() {
    int n;
    cin >> n;
    vector<string> files(n);
    for (int i = 0; i < n; ++i) {
        cin >> files[i];
    }
    sort(files.begin(), files.end());
    int step = 0;
    string last_string;
    for (string& s: files) {
        s.s
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
    while (t--) {
        solve();
    }
    return 0;
}


