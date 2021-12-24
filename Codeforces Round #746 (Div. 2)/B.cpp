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
	int n, x;
	cin >> n >> x;
	vector<int> a(n), a_sorted(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a_sorted[i] = a[i];
	}
	sort(a_sorted.begin(), a_sorted.end());
	bool check = true;
	for (int i = 0; i < n; ++i) {
		if (a[i] != a_sorted[i]) {
			check = false;
			break;
		}
	}
	if (check) {
		cout << "YES\n";
	}
	else {
		if (n == x) cout << "NO\n";
		else if (x <= n / 2) cout << "YES\n";
		else {
			bool flag = true;
			for (int i = n - x; i < x; ++i) {
				if (a[i] != a_sorted[i]) {
					flag = false;
 					break;
				}
			}
			if (flag) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
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
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
