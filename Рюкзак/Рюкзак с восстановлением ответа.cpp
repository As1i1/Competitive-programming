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
vector<set<int>> g;
vector<bool> used;
map<int, int> comp;
int c = 1;


void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> m(n + 1), w(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	set<int> ans;
	for (int i = 0; i < n; ++i) {
		cin >> m[i + 1];
	}
	for (int j = 0; j < n; ++j) {
		cin >> w[j + 1];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (j - m[i] < 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - m[i]] + w[i]);
		}
	}
	int t_n = n, t_w = k;
	while (t_n != 0) {
		if (dp[t_n][t_w] == dp[t_n - 1][t_w]) {
			t_n--;
		}
		else {
			t_w -= m[t_n];
			ans.insert(t_n);
			t_n -= 1;
		}
	}
	for (auto elem : ans) {
		cout << elem << "\n";
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
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
