//
// Created by AMD on 25.12.2021.
//

#include <iostream>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
//mt19937 gen;


void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1;  return;
    }
    if (n == 2) {
        cout << 3 * 2; return;
    }
    ll st = 4, ans = 6;
    for (int i = 3; i <= n; ++i) {
        ll tmp_st = (2 * st - 1) % MOD;
        ans = (((tmp_st * ans) % MOD) * st) % MOD;
        st = (st * 2) % MOD;
    }
    cout << ans;
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