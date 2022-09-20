//
// Created by Dima on 30.08.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int n;
    cin >> n;
    set<ll> s;
    for(int i = 0; i < n; ++i){
        ll a; cin >> a; s.insert(a);
    }
    int m;
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        auto p1 = s.lower_bound(l), p2 = s.upper_bound(r);
        p2--;
        ll x = *p1, y = *p2;
        if (x > r || x < l || y > r || y < l) cout << 0 << "\n";
        else cout << y - x << "\n";

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
