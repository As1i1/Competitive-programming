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
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve() {
	int n, b, h;
	vector<vector<vector<int>>> dp(102, (vector<vector<int>>(1002, vector<int>(110))));
	cin >> n >> b >> h;
	if (n - b < 0) {
		dp[1][0][b] = 0;
	}
	else {
		dp[1][n - b][b] = 1;
	}
	for (int k = 1; k < h; ++k) {
		for (int i = 0; i <= n; ++i) {
			for (int j = max(b - 50, 0); j < min(110, b + 50); ++j) {
				if (j - 1 > 0 && i - j + 1 > -1) {
					dp[k + 1][i - j + 1][j - 1] = (dp[k + 1][i - j + 1][j - 1] + dp[k][i][j]) % MOD;
				}
				if (i - j - 1 > -1) {
					dp[k + 1][i - j - 1][j + 1] = (dp[k + 1][i - j - 1][j + 1] + dp[k][i][j]) % MOD;
				}

			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 110; ++i) {
		ans = (ans + dp[h][0][i]) % MOD;
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
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
