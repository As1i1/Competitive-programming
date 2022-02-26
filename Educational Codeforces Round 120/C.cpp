//
// Created by AMD on 27.12.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <ctime>
#include <bitset>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


ll check(vector<ll> a, ll a0, ll k, ll sum) {
    int ans = 0, cnt1 = 1;
    ll cur = a[0];
    if (a0 * cnt1 + sum - cur <= k) {
        return ans;
    }
    for (int i = a.size() - 1; i > 0; --i) {
        cur += a[i];
        cnt1++;
        ans++;
        if (a0 * cnt1 + sum - cur <= k) {
            return ans;
        }
    }
    return INF;
}




void solve() {
    int n;
    ll k, sum = 0;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    ll l = -INF - 1e5 - 10, r = a[0];
    while (r - l > 10) {
        ll m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        ll cnt1 = abs(a[0] - m1) + check(a, m1, k, sum), cnt2 = abs(a[0] - m2) + check(a, m2, k, sum);
        if (cnt1 > cnt2) {
            l = m1;
        }
        else {
            r = m2;
        }
    }
    ll ans = ll_INF;
    for (int i = l; i <= r; ++i) {
        ans = min(ans, abs(a[0] - i) + check(a, i, k, sum));
    }
    cout << ans << "\n";
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
