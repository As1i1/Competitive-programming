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
vector<int> a;


bool check(int l, int r, int number) {
	while (r - l > 0) {
		if (a[l] == a[r]) {
			l++;
			r--;
		}
		else {
			if (a[l] == number) {
				l++;
			}
			else if (a[r] == number) {
				r--;
			}
			else {
				return false;
			}
		}
	}
	return true;
}


void solve() {
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int k1 = 0, k2 = n - 1;
	while (k2 - k1 > 0) {
		if (a[k1] == a[k2]) {
			k2--;
			k1++;
		}
		else {
			if (check(k1, k2, a[k1]) || check(k1, k2, a[k2])) {
				cout << "YES\n";
				return;
			}
			else {
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
