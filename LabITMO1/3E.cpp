#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
ll n, a, b, w, h;


bool check(ll d) {
    ll a_ = a + 2 * d, b_ = b + 2 * d;
    return (w / a_) * (h / b_) >= n || (w / b_) * (h / a_) >= n;
}


void solve(){
    cin >> n >> a >> b >> w >> h;
    ll l = 0, r = ll_INF + 1;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l;
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

