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


bool comp1(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}


bool comp2(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}


void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> coord(n);
	for (int i = 0; i < n; ++i) {
		cin >> coord[i].first >> coord[i].second;
	}
	vector<int> pref_x(1e6 + 2, 0), pref_y(1e6 + 2, 0);
	sort(coord.begin(), coord.end(), comp1);
	int k1 = 0, i = 2;
	while (i < 1e6) {
		pref_x[i] = pref_x[i - 2];
		while (k1 != n && coord[k1].first < i) {
			pref_x[i]++;
			k1++;
		}
		i += 2;
	}
	sort(coord.begin(), coord.end(), comp2);
	k1 = 0, i = 2;
	while (i < 1e6) {
		pref_y[i] = pref_y[i - 2];
		while (k1 != n && coord[k1].second < i) {
			pref_y[i]++;
			k1++;
		}
		i += 2;
	}
	int d = INF, ans_x = -1, ans_y = -1;
	for (int i = 0; i < 31; i += 2) {
		if (abs(n / 2 - pref_x[i]) < d) {
			d = abs(n / 2 - pref_x[i]);
			ans_x = i;
		}
	//	cout << d << " ";
	}
	d = INF;
	for (int i = 0; i < 1e6; i += 2) {
		if (abs(n / 2 - pref_y[i]) < d) {
			d = abs(n / 2 - pref_y[i]);
			ans_y = i;
		}
	}
	cout << ans_x << " " << ans_y << " ";
	int cnt[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < n; ++i) {
		if (coord[i].first > ans_x && coord[i].second > ans_y) {
			cnt[3]++;
		}
		else if (coord[i].first < ans_x && coord[i].second < ans_y) {
			cnt[0]++;
		}
		else if (coord[i].first < ans_x && coord[i].second > ans_y) {
			cnt[1]++;
		}
		else {
			cnt[2]++;
		}
	}
	cout << max({ cnt[0], cnt[1], cnt[2], cnt[3] });
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 1;
	//	gen.seed(time(0));
	//	cout << fixed;
	//	cout.precision(15);
		//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
