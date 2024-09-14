//
// Created by aas1i1 on 4/2/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;


ll binpow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    ll d = binpow(a, n / 2);
    if (n % 2 == 0) {
        return d * d;
    }
    return d * d * a;
}


void solve() {
    int n;
    cin >> n;
    if (n < 7) {
        cout << "0";
        return;
    }
    ll ans = 0;
    ans += binpow(26, n - 7) *  (n - 7 + 1);
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


