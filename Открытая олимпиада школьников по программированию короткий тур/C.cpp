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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	map<int, vector<ll>> pref;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pref[a[i]].resize(n);
	}
	for (int i = 0; i < n; ++i) {
		pref[a[i]][i]++;
		if (i == 0) continue;
		for (auto& p : pref) {
			p.second[i] += p.second[i - 1];
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		ll ans = (r - l) * (r - l + 2) * (r - l + 1) / 6;
		for (int len = 1; len <= (r - l); ++len) {
			for (int j = l; j <= r - len; ++j) {
				ans -= (pref[a[j]][r - len] - pref[a[j]][j] + 1);
			}
		}
		cout << ans << "\n";
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
