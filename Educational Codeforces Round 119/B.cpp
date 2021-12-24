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


void solve() {
	ll w, h;
	cin >> w >> h;
	vector<ll> w1, w2, h1, h2;
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		ll tmp; cin >> tmp;
		w1.push_back(tmp);
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		ll tmp; cin >> tmp;
		w2.push_back(tmp);
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		ll tmp; cin >> tmp;
		h1.push_back(tmp);
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		ll tmp; cin >> tmp;
		h2.push_back(tmp);
	}
	cout << max({ (w1.back() - w1[0]) * h, (w2.back() - w2[0]) * h, (h1.back() - h1[0]) * w, (h2.back() - h2[0]) * w }) << "\n";
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
