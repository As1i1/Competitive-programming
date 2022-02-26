//
// Created by AMD on 26.12.2021.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 998244353, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
ll ans = 0;
vector<ll> n, pos;


ll rec(int )


void solve() {
    int d;
    cin >> d;
    n.resize(d);
    pos.resize(d);
    for (int i = 0; i < d; ++i) {
        cin >> n[i];
    }
    for (int i = 0; i < d; ++i) {
        cin >> pos[i];
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