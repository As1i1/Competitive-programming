#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


ll binpow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a % MOD;
    }
    ll d = binpow(a, n / 2);
    if (n % 2 == 0) {
        return (d * d) % MOD;
    }
    return (((d * d) % MOD) * a) % MOD;
}


void solve(){
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 2;
        return;
    }
    ll p = binpow(2, n);
    if (n % 3 == 2) {
        cout << (p - binpow(2, n / 3) * 2 + MOD) % MOD;
    } else {
        cout << p;
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
