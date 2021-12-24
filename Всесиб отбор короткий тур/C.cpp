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

const int INF = 1e9, MOD = 1e9 + 9, Q = 41;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve() {
	ll n, m, w;
	cin >> n >> m >> w;
	vector<int> b(m);
	ll mn = 1e9;
	for (int i = 0; i < n; ++i) {
		ll tmp;
		cin >> tmp;
		mn = min(tmp, mn);
	}
	mn *= w;
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(b.begin(), b.end());
	ll ans = 0;
	for (int i = m - 1; i >= 0; i--) {
		if (b[i] - mn > 0) {
			ans += (b[i] - mn);
		}
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
