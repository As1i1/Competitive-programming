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
	int k, n = 20000000, cnt = 0;
	cin >> k;
	vector<bool> prime(n, true);
	for (int i = 2; cnt < k; ++i) {
		if (!prime[i]) {
			continue;
		}
		cnt++;
		if (cnt == k) {
			cout << i;
			break;
		}
		for (int j = 2 * i; j < n; j += i) {
			prime[j] = false;
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
	//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
