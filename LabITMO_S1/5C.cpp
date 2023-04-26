#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> w(n), c(n);
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[j][i - 1])
        }
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
