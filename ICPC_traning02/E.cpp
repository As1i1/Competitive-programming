#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> ans(n);
    for (int i = 0; i < k; ++i){
        ll tmp = 0;
        for (int j = i; j < n; j += k){
            tmp += a[j];
        }
        ans[i] = tmp;
    }
    ll mn = ll_INF;
    for (int i = 0; i < k; ++i){
        mn = min(mn, ans[i]);
    }
    cout << mn;
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
