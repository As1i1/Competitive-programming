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
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ll ll_INF = 1e18;


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
	string s, t;
	cin >> s >> t;
	s = "#" + s;
	t = "#" + t;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0) {
				continue;
			}
			else if (s[i] == t[j]) {
				a[i][j] = a[i - 1][j - 1] + 1;
			}
			else {
				a[i][j] = 0;
			}
		}
	}
	int ans = 0;
	pair<int, int> tmp = { 0, 0 };
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (a[i][j] > ans) {
				if (a[i][j] == 15) {
					ans = 15;
				}
				ans = a[i][j];
				tmp = { j - ans + 1, j + 1 };
			}
		}
	}
	for (int i = tmp.first; i < tmp.second; ++i) {
		cout << t[i];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//	cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
