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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n, vector<int>(m, 0));
	vector<vector<bool>> ans(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == '*') {
				g[i][j] = 1;
			}
		}
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = 1; j < m - 1; ++j) {
			if (g[i][j] == 1 && g[i - 1][j - 1] == 1 && g[i - 1][j + 1] == 1) {
				int ii = i, j1 = j, j2 = j, t = -1;
				while (ii >= 0 && j1 >= 0 && j2 < m && g[ii][j1] == 1 && g[ii][j2] == 1) {
//					ans[ii][j1] = true;
//					ans[ii][j2] = true;
					ii--;
					j1--;
					j2++;
					t++;
				}
				if (t >= k) {
					ii = i, j1 = j, j2 = j;
					while (ii >= 0 && j1 >= 0 && j2 < m && g[ii][j1] == 1 && g[ii][j2] == 1) {
						ans[ii][j1] = true;
						ans[ii][j2] = true;
						ii--;
						j1--;
						j2++;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == 1 && !ans[i][j]) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
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
