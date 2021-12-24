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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int k1 = n - 2 * k, k2 = n - 1;
	int ans = 0;
	map<int, int> mp;
	set<pair<int, int>> s;
	for (int i = k1; i < n; ++i) {
		mp[a[i]]++;
	}
	for (auto p : mp) {
		s.insert({p.second, p.first});
	}
	while (!s.empty()) {
		auto u = *s.rbegin();
		s.erase(u);
		if (s.empty()) {
			ans += u.first / 2;
		}
		else {
			auto v = *s.rbegin();
			s.erase(v);
			u.first -= v.first;
			if (u.first != 0) {
				s.insert(u);
			}
		}
	}
	for (int i = 0; i < k1; ++i) {
		ans += a[i];
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
