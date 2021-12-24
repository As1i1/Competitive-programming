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
#define int ll

bool comp1(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}


bool comp2(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}


void solve() {
	int n, m;
	int add = 1e6 + 5;
	int start_x = 0 + add, start_y = 0 + add;
	cin >> n >> m;
	vector<pair<int, int>> points(n);
	vector<int> pref_x(2 * 1e6 + 7), pref_y(2 * 1e6 + 7);
	for (int i = 0; i < n; ++i) {
		cin >> points[i].first >> points[i].second;
		points[i].first += add;
		points[i].second += add;
	}
	sort(points.begin(), points.end(), comp1);
	int k1 = 0, i = 1;
	while (i < 2 * 1e6 + 7) {
		pref_x[i] = pref_x[i - 1];
		while (k1 != n && points[k1].first < i) {
			pref_x[i]++;
			k1++;
		}
		i += 1;
	}
	sort(points.begin(), points.end(), comp2);
	k1 = 0, i = 1;
	while (i < 2 * 1e6 + 7) {
		pref_y[i] = pref_y[i - 1];
		while (k1 != n && points[k1].second < i) {
			pref_y[i]++;
			k1++;
		}
		i += 1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += abs(points[i].first - start_x) + abs(points[i].second - start_y);
	}
	for (int i = 0; i < m; ++i) {
		char c;
		cin >> c;
		if (c == 'S') {
			start_y++;
			ans += pref_y[start_y];
			ans = ans - (n - pref_y[start_y]);
		}
		else if (c == 'J') {
			start_y--;
			ans = ans + (n - pref_y[start_y + 1]);
			ans = ans - pref_y[start_y + 1];
		}
		else if (c == 'I') {
			start_x++;
			ans += pref_x[start_x];
			ans = ans - (n - pref_x[start_x]);
		}
		else if (c == 'Z') {
			start_x--;
			ans = ans + (n - pref_x[start_x + 1]);
			ans = ans - pref_x[start_x + 1];
		}
		cout << ans << "\n";
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
