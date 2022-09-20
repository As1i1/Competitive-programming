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
    vector<int> dp(n + 1), a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i){
        dp[i] = a[i];
    }
    for (int i = k; i <= n; ++i){
        for (int j = i - k; j < i; ++j){
            dp[i] = max(dp[i], dp[j]);
        }
        if (i != n) dp[i] = min(dp[i], a[i]);
    }
    cout << dp[n];
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
