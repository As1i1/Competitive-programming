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
	int n, m = 1e6 + 1, k;
	cin >> n;
	vector<int> a(n), dp(m, INF), ans;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> k;
	dp[0] = 0;
	sort(a.begin(), a.end());
	for (int i = 1; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i - a[j] < 0) continue;
			dp[i] = min(dp[i], dp[i - a[j]] + 1);
		}
	}
	if (dp[k] == INF) {
		cout << "No solution";
		return;
	}
	while (k != 0) {
		for (int i = 0; i < n; ++i) {
			while (k - a[i] >= 0 && dp[k - a[i]] + 1 == dp[k]) {
				k -= a[i];
				ans.push_back(a[i]);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = ans.size() - 1; i > -1; i--) {
		cout << ans[i] << " ";
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
