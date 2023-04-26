#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


ll gcd(ll a, ll b) {
    return b == 0 ? a: gcd(b, a % b);
}


void solve(){
    ll nod, nok;
    cin >> nod >> nok;
    ll n = nok * nod;
    ll i = 2, ans = 0;
    while (i * i <= n) {
        if (n % i == 0 && gcd(n / i, i) == nod) {
            if (n / i == i) {
                ans--;
            }
            ans += 2;
        }
        i++;
    }
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
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
