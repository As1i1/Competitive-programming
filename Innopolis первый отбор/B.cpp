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
	int n, m;
	cin >> n;
	m = n - 1;
	vector<vector<int>> a(m, vector<int>(n, 0));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	vector<pair<bool, int>> can(n, { false, -1 });
	vector<ll> add(n, 0);
	vector<bool> used(n);
	for (int i = 0; i < n; ++i) {
		used.assign(n, false);
		for (int j = 0; j < m; ++j) {
			used[a[j][i] - 1] = true;
		}
		int cnt = 0, ind = -1;
		for (int j = 0; j < n; ++j) {
			if (!used[j]) {
				cnt++;
				ind = j;
			}
		}
		if (cnt == 1) {
			can[i] = { true, ind };
		}
	}
	int ans = n;
	for (int i = 0; i < n; ++i) {
		if (can[i].first) {
			if (add[can[i].second] == 0) ans--;
			add[can[i].second]++;
		}
	}
	ll ans2 = 1;
	for (ll i = 2; i <= ans; ++i) {
		ans2 = (ans2 * i) % MOD;
	}
	for (int i = 0; i < n; ++i) {
		if (add[i] != 0) {
			ans2 = (ans2 * add[i]) % MOD;
		}
	}
	cout << n - ans << " " << ans2;
}


signed main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 1;
	//	gen.seed(time(0));
	//	cout << fixed;
	//	cout.precision(15);
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
