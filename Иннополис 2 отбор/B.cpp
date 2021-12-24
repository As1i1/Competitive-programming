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
#include <bitset>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	vector<int> dp(sum + 1, INF);
	dp[0] = -1;
	for(int i = 0; i < n; ++i){
		for (int j = sum; j >= 0; --j) {
			if (j + a[i] <= sum && dp[j] != INF && dp[j + a[i]] == INF){
				dp[j + a[i]] = i;
			}
		}
	}
	int ans1 = 0;
	for (int i = 0; i <= sum; ++i) {
		if (dp[i] != INF) {
			if (abs(sum - i * 2) < abs(sum - ans1 * 2)) {
				ans1 = i;
			}
		}
	}
	vector<int> ans(n, 2);
	int t = ans1;
	while (dp[t] != -1) {
		ans[dp[t]] = 1;
		t = t - a[dp[t]];
	}
	cout << abs(sum - ans1 * 2) << "\n";
	for (int i = 0; i < n; ++i) {
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
