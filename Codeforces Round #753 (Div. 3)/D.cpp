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
	int n;
	cin >> n;
	string s;
	multiset<int> R, B;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			R.insert(a[i]);
		}
		else if (s[i] == 'B') {
			B.insert(a[i]);
		}
	}
	if ((!B.empty() && *B.begin() <= 0) || (!R.empty() && *R.begin() > n)) {
		cout << "NO\n";
		return;
	}
	int k1 = 1;
	while (k1 < n + 1) {
		if (B.empty()) {
			int v = *R.begin();
			R.erase(R.begin());
			if (v > k1) {
				cout << "NO\n";
				return;
			}
		}
		else {
			int v = *B.begin();
			B.erase(B.begin());
			if (k1 > v) {
				cout << "NO\n";
				return;
			}
		}
		k1++;
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
