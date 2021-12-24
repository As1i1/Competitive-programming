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
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int>(m, 0)), pref(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == '.') field[i][j] = 0;
			else field[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] + field[i - 1][j - 1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x1, x2;
		cin >> x1 >> x2;
		if ((pref[1][x2] - pref[1][x1 - 1] - pref[0][x2] + pref[x1 - 1][0]) == x2 - x1 + 1 &&
			(pref[n][x2] - pref[n][x1 - 1]) == n) cout << "NO\n";
		else cout << "YES\n";
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
