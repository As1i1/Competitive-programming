//
// Created by Dubinin Dmitrii on 6/3/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll get_M_i(ll a, ll M) {
    ll M_i = M / a;
    ll x, y;
    gcd(M_i, a, x, y);
    x = (x % M + M) % M;
    return (M_i * x) % M;
}

void solve() {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    ll M = n * m;
    cout << (((a * get_M_i(n, M)) % M) + (b * get_M_i(m, M))) % M;
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


