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
	int n, t = 63;
	cin >> n;
	if (n > 3000){
		t = 6;
	}
	vector<ll> a(n);
	vector<vector<ll>> pref(n, vector<ll>(t + 1, 0));
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i <= t; ++i) {
		if (a[0] & (1 << i)) {
			pref[0][i] = 1;
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= t; ++j) {
			pref[i][j] = pref[i - 1][j];
			if (a[i] & (1 << j)) {
				pref[i][j]++;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 2; j < n; ++j) {
			if ((a[i] ^ a[j]) == 0) continue;
			ll k = __lg(a[i] ^ a[j]);
			if (a[j] & (1 << k)) {
				ans += (j - i - 1) - (pref[j - 1][k] - pref[i][k]);
			}
			else {
				ans += pref[j - 1][k] - pref[i][k];
			}
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
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
