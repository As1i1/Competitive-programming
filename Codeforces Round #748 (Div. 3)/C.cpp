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
	int n, k;
	cin >> n >> k;
	vector<int> pos(k);
	for (int i = 0; i < k; ++i) {
		cin >> pos[i];
		pos[i] = n - pos[i];
	}
	sort(pos.begin(), pos.end());
	int cur_pos = 0, k1 = 0, ans = 0;
	while (k1 < k && cur_pos < n) {
		if (cur_pos + pos[k1] < n && cur_pos < n - pos[k1]) {
			ans++;
			cur_pos += pos[k1];
			k1++;
		}
		else {
			break;
		}
	}
	cout << ans << "\n";
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
