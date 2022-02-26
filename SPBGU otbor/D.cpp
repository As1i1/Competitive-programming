//
// Created by AMD on 25.12.2021.
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
    vector<ll> a(n), pref(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    pref[0] = 0;
    pref[1] = a[0];
    pref[2] = a[1] + a[0];
    int ans = INF;
    for(int i = 2; i < n; ++i){
        if (pref[i] <= a[i]){
            pref[i + 1] = pref[i] + a[i];
            continue;
        }
        int l = 0, r = i - 2;
        while(r - l > 1) {
            int m = (r + l) / 2;
            if (pref[i] - pref[m - 1] > a[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        for (int j = max(0, l - 3); j <= min(i - 2, r + 3); j++){
            if (pref[i] - pref[j] > a[i]){
                ans = min(ans, i - j + 1);
            }
        }
        pref[i + 1] = pref[i] + a[i];
    }
    if (ans == INF) cout << -1;
    else cout << ans;
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
