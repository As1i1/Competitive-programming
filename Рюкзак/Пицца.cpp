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
vector<set<int>> g;
vector<bool> used;
map<int, int> comp;
int c = 1;


void solve() {
	ll a, b, c, n;
	cin >> a >> b >> c >> n;
	vector<ll> m(n);
	for (int i = 0; i < n; ++i) cin >> m[i];
	if (a > c) cout << a;
	else {
		c -= a;
		ll mn_c = ll_INF;
		vector<bool> dp(c + 2, false);
		dp[0] = true;
		for (int i = 0; i < n; ++i) {
			for (ll j = c; j >= 0; --j) {
				if (j + m[i] > c && dp[j]) {
					mn_c = min(j + m[i], mn_c);
				}
				else if (j + m[i] < c + 1) {
					dp[j + m[i]] = true;
				}
			}
		}
		cout << min(mn_c + a, a + b); 
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
