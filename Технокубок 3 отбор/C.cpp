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
	vector<int> coordp, coordn;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp < 0) {
			coordn.push_back(abs(tmp));
		}
		else {
			coordp.push_back(tmp);
		}
	}
	sort(coordn.begin(), coordn.end());
	sort(coordp.begin(), coordp.end());
	multiset<ll> s;
	if (coordn.size() == 0) {
		s.insert(0);
		ll ans1 = 0;
		for (int i = 0; i < coordp.size(); ++i) {
			if (i - k - 1 >= -1) {
				s.erase(s.begin());
			}
			ans1 = *s.begin() + coordp[i] * 2;
			s.insert(ans1);
		}
		cout << ans1 - coordp[n - 1];
	}
	else if (coordp.size() == 0) {
		ll ans2 = 0;
		s.insert(0);
		for (int i = 0; i < coordn.size(); ++i) {
			if (i - k - 1 >= -1) {
				s.erase(s.begin());
			}
			ans2 = *s.begin() + coordn[i] * 2;
			s.insert(ans2);
		}
		cout << ans2 - coordn[n - 1];
	}
	else {
		s.insert(0);
		ll ans1 = 0;
		for (int i = 0; i < coordp.size(); ++i) {
			if (i - k - 1 >= -1) {
				s.erase(s.begin());
			}
			ans1 = *s.begin() + coordp[i] * 2;
			s.insert(ans1);
		}
		s.clear();
		ll ans2 = 0;
		s.insert(0);
		for (int i = 0; i < coordn.size(); ++i) {
			if (i - k - 1 >= -1) {
				s.erase(s.begin());
			}
			ans2 = *s.begin() + coordn[i] * 2;
			s.insert(ans2);
		}
		cout << min(ans1 + ans2 - coordp.back(), ans1 + ans2 - coordn.back());
	}
	cout << "\n";
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
