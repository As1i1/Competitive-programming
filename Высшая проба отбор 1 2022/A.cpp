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
	if (n % 2 == 0) {
		cout << n - 2 << "\n";
		for (int i = 3; i <= n - 1; ++i) {
			cout << 1 << " " << i << "\n";
		}
		cout << n / 2 << " " << n / 2 + 2;
	}
	else {
		cout << n - 3 << "\n";
		for (int i = 3; i <= n - 1; ++i) {
			cout << 1 << " " << i << "\n";
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
	//  cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
