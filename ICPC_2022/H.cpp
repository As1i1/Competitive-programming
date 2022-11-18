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
    vector<ll> s(n), p(n);
    ll sum_s = 0, sum_p = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sum_s += s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        sum_p += p[i];
    }
    ll k = sum_s / sum_p;
    ll ans = sum_s % sum_p;
    ll ans2 = 0;
    for (int i = 0; i < n; ++i) {
        ans2 += abs(s[i] - p[i] * k);
    }
    ans = ans + ans2;
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
 //   cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
