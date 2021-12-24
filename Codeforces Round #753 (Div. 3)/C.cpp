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
	int n;
	cin >> n;
	multiset<ll> a;
	ll t = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		ll tmp;
		cin >> tmp;
		a.insert(tmp);
	}
	ans = *a.begin();
	while (a.size() > 1) {
		ll v = *a.begin();
		a.erase(a.begin());
		ll tmp = *a.begin();
		v -= t;
		t += v;
		ans = max(tmp - t, ans);
	}
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 1;
	//	gen.seed(time(0));
	//	cout << fixed;
	//	cout.precision(15);
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
