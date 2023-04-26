#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    vector<vector<int>> dp(n);
    vector<ll> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k - 1; i++) {
        dp[k - 1].push_back(i);
        ans[k - 1] += abs(a[i] - a[i + 1]);
    }
    dp[k - 1].push_back(k - 1);



    for (int i = k; i < n; ++i) {
        ll new_sum = ans[i - 1];
        int index = -1;
        vector<int> indexs = dp[i - 1];
        for (int j = 0; j < k; j++) {
            if (j == 0) {
                ll cur = ans[i - 1] -
                        abs(a[indexs[j]] - a[indexs[j + 1]]) +
                        abs(a[indexs.back()] - a[i]);
                if (cur > new_sum) {
                    new_sum = cur;
                    index = j;
                }
            } else if (j == k - 1) {
                ll cur = ans[i - 1] -
                        abs(a[indexs[j]] - a[indexs[j - 1]]) +
                        abs(a[indexs[j - 1]] - a[i]);
                if (cur > new_sum) {
                    new_sum = cur;
                    index = j;
                }
            } else {
                ll cur = ans[i - 1] -
                        abs(a[indexs[j]] - a[indexs[j + 1]]) -
                        abs(a[indexs[j]] - a[indexs[j - 1]]) +
                        abs(a[indexs.back()] - a[i]);
                if (cur > new_sum) {
                    new_sum = cur;
                    index = j;
                }
            }
        }
        if (index == -1) {
            dp[i] = indexs;
            ans[i] = new_sum;
        } else {
            for (int j = 0; j < k; ++j) {
                if (j != index) {
                    dp[i].push_back(indexs[j]);
                }
            }
            dp[i].push_back(i);
            ans[i] = new_sum;
        }
    }

    cout << ans.back();
}



signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
//    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
    solve();
    return 0;
}
