//
// Created by Dubinin Dmitrii on 5/31/24.
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
    int i = 2;
    while (i * i <= n) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
        i++;
    }
    if (n != 1) {
        cout << n;
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


