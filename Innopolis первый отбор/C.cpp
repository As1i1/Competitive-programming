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


void solve() {
	ll l, r;
	cin >> l >> r;
	set<pair<ll, ll>> ans;
	if (-1 >= l && r >= -1){
		cout << -1;
		return;
	}
	for (ll x1 = -5000; x1 <= 5000; ++x1) {
		for (ll x2 = -5000; x2 <= 5000; ++x2) {
			if (x1 * x2 - x1 - x2 >= l && x2 * x1 - x1 - x2 <= r)	ans.insert({ max(x1, x2), min(x2, x1) });
		}
	}
	cout << ans.size();
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
