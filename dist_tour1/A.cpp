//
// Created by AMD on 30.12.2021.
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
    ll k;
    cin >> n >> k;
    if (k == 0){
        cout << -1;
        return;
    }
    for (int i = 2; i < n; ++i){
        ll cnt1 = i - 1, cnt2 = n - i - 1;
        if (cnt1 * cnt2 == k){
            cout << 1 << " " << i + 1;
            return;
        }
    }
    cout << -1;
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
