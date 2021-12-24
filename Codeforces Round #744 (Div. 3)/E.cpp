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
#include <deque>
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
	deque<int> dq;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	dq.push_back(a[0]);
	for (int i = 1; i < n; ++i) {
		int cur_front = dq.front();
		if (cur_front > a[i]) {
			dq.push_front(a[i]);
		}
		else {
			dq.push_back(a[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << dq[i] << " ";
	}
	cout << "\n";
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
