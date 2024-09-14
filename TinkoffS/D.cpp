//
// Created by aas1i1 on 4/2/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;


void solve() {
    int n;
    cin >> n;
    if ((n & (n + 1)) == 0) {
        int sm = 0;
        for (int i = 1; sm < n; sm += i, i = i * 2) {
            cout << i << " ";
        }
    } else {
        vector<vector<bool>> dp(n + 10, vector<bool>(n + 10, false));
        dp[1][1] = true;
        for (int sm = 1; sm < n; ++sm) {
            for (int cur = 1; cur < n; ++cur) {
                if (!dp[sm][cur]) continue;
                if (sm + cur * 2 <= n) {
                    dp[sm + cur * 2][cur * 2] = true;
                }
                if (sm + cur + 1 <= n) {
                    dp[sm + cur + 1][cur + 1] = true;
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (dp[n][i])  {
                int sm = n;
                vector<int> res;
                while (sm != 0) {
                    res.push_back(i);
                    if (i % 2 == 0 && dp[sm - i][i / 2]) {
                        sm -= i;
                        i /= 2;
                    } else {
                        sm -= i;
                        i--;
                    }
                }
                std::reverse(res.begin(), res.end());
                for (auto c: res) {
                    cout << c << " ";
                }
                return;
            }
        }
        cout << "-1";

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
    while (t--) {
        solve();
    }
    return 0;
}


