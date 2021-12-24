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
vector<int> p(1e5 * 5 + 1);


void szh(int v) {
	if 
}



void solve() {
	int q;
	for (int i = 0; i < 1e5 * 5 + 1; ++i) {
		p[i] = i;
	}
	cin >> q;
	vector<pair<int, int>> op;
	while (q--){
		int c;
		cin >> c;
		if (c == 1) {
			int x;
			cin >> x;
			op.push_back({ x, -1 });
		}
		else {
			int x, y;
			cin >> x >> y;
			op.push_back({ x, y });
		}
	}
	vector<int> ans;

	for (int i = op.size() - 1; i >= 0; i--) {
		if (op[i].second == -1) {
			ans.push_back(p[op[i].first]);
		}
		else {

		}
	}
	reverse(ans.begin(), ans.end());
	for (auto elem : ans) {
		cout << elem << " ";
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
