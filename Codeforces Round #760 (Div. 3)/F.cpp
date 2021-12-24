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



bool check(string s, string t) {
	int n = s.size(), m = t.size();
	for (int i = 0; i < n - m + 1; ++i){
		string s1 = "";
		bool flag = true;
		for (int j = i; j < i + m; ++j) {
			s1 += s[j];
		}
		for (int j = i + m; j < n; ++j) {
			if (s[j] == '0') flag = false;
		}
		for (int j = 0; j < i; ++j) {
			if (s[j] == '0') flag = false;
		}
		if (s1 == t && flag) {
			return true;
		}
	}
	return false;
}



void solve() {
	ll x, y;
	cin >> x >> y;
	string s_x = "", s_y = "";
	for (ll i = 0; i < 63; ++i) {
		if ((1ll << i) <= x) {
			if (x & (1ll << i)) {
				s_x += "1";
			}
			else {
				s_x += "0";
			}
		}
		if ((1ll << i) <= y) {
			if (y & (1ll << i)) {
				s_y += "1";
			}
			else {
				s_y += "0";
			}
		}
	}
	reverse(s_y.begin(), s_y.end());
	string s1 = "", s2;
	bool flag = false;
	for (int i = 0; i < s_x.size(); ++i) {
		if (s_x[i] == '1') flag = true;
		if (flag) s1 += s_x[i];
	}
	reverse(s_x.begin(), s_x.end());
	s2 = s_x + "1";
	if (check(s_y, s1) || check(s_y, s2)) {
		cout << "YES";
		return;
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	if (check(s_y, s1) || check(s_y, s2)) {
		cout << "YES";
		return;
	}
	cout << "NO";
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
