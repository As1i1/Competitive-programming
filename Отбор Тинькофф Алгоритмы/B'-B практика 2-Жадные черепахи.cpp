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
#include <list>
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
	list<pair<int, int>> a;
	vector<bool> used;
	used.resize(n, false);
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		a.push_back({ tmp, i });
	}
	int i = 0;
	int cnt = 0;
	while (i < 1e6) {
		pair<int, int> x = a.front();
		if (!used[x.second]) cnt++;
		used[x.second] = true;
		if (cnt == n || x.first == n - 1) break;
		a.pop_front();
		auto it = a.end();
		for (int i = 0; i < x.first; ++i) {
			it--;
		}
		a.insert(it, x);
		i++;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) ans++;
	}
	cout << ans;
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
