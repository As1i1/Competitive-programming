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
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int ans = 0;
	if (s[0] == '?') {
		s[0] = t[0];
	}
	for (int i = 1; i < n; ++i) {
		if (s[i - 1] == t[0] && s[i] == '?') {
			s[i] = t[1];
		}
		else if (i != n - 1 && s[i + 1] == t[1] && s[i] == '?') {
			s[i] = t[0];
		}
		else if (s[i] == '?') {
			s[i] = t[0];
		}
		if (s[i - 1] == t[0] && s[i] == t[1]) {
			ans++;
		}
	}
	cout << ans << "\n" << s;
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
