
//
// Created by AMD on 26.12.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 998244353, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
//mt19937 gen;


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<pair<ll, ll>> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n;) {
        ll last = 0;
        if (a[i] < 0) {
            last = -1;
        }
        else {
            last = 1;
        }
        ll cur_sum = 0, cur_min = ll_INF;
        for (; i < n && last * a[i] >= 0; ++i) {
            cur_sum += a[i];
            cur_min = min(a[i], cur_min);
        }
        b.push_back({ cur_sum, cur_min });
    }
    if (b.size() == 1) {
        cout << min(b[0].first, b[0].second) << "\n";
        return;
    }
    n = b.size();
    for (int i = 0; i < n; ++i){
        b[i].first = -b[i].first;
    }
    ll ans = -ll_INF;
    vector<ll> pref(n + 1);
    ll cur_min = 0;
    pref[0] = 0;
    for (int i = 0; i < n; ++i){
        pref[i + 1] = pref[i] + b[i].first;
        ans = max(ans, pref[i + 1] - cur_min);
        cur_min = min(cur_min, pref[i + 1]);
    }
    cout << -ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
    //	gen.seed(time(0));
    //	cout << fixed;
    //	cout.precision(15);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}