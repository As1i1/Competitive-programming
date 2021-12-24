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
	int n, m, t;
	string s;
	cin >> n >> m >> s;
//	vector<int> rows, cols;
//	for (int i = 0; i < n; ++i) rows.push_back(i);
//	for (int i = 0; i < m; ++i) cols.push_back(i);
	t = s.size();
	int cur_r = 0, cur_c = 0, x = 0, y = 0, k1_r = 0, k2_r = n - 1, k1_c = 0, k2_c = m - 1; // mx_r = 0, mn_r = 0, mx_c = 0, mn_c = 0, 
	for (int i = 0; i < t; ++i) {
		if (s[i] == 'R') {
			cur_c++;
		}
		else if (s[i] == 'L') {
			cur_c--;
		}
		else if (s[i] == 'D') {
			cur_r++;
		}
		else if (s[i] == 'U') {
			cur_r--;
		}
		while (k2_c - k1_c >= 0 && k1_c + cur_c < 0) {
			k1_c++;
		}
		while (k2_c - k1_c >= 0 && k2_c + cur_c >= m) {
			k2_c--;
		}
		while (k2_r - k1_r >= 0 && k1_r + cur_r < 0) {
			k1_r++;
		}
		while (k2_r - k1_r >= 0 && k2_r + cur_r >= n) {
			k2_r--;
		}
		if (k2_r - k1_r < 0 || k2_c - k1_c < 0) {
			//cout << x + 1 << " " << y + 1;
			break;
		}
		x = k1_r, y = k1_c;
	}
	cout << x + 1 << " " << y + 1 << "\n";
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
