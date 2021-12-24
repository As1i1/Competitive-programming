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
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;

int ans = 0, n;


void req(int a, int b) {
	int c = a + b;
	if (c == n) ans++;
	else if (c < n) {
		req(a, c);
	    req(b, c);
	}
}


void solve2() {
	int n, k, q;
	cin >> n >> k >> q;
	map<vector<int>, pair<int, int>> pred;
	for (int i = 0; i < n; ++i) {
		int c, cnt;
		cin >> c >> cnt;
		vector<int> v(cnt);
		for (int j = 0; j < cnt; ++j) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		if (pred.find(v) != pred.end()) {
			if (pred[v].first > c) {
				pred[v] = { c, i };
			}
		}
		else {
			pred[v] = { c, i };
		}
	}
	while (q--) {
		int c;
		cin >> c;
		vector<int> v(c);
		for (int i = 0; i < c; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int ans = INF, number = -1;
		for(auto par: pred){
			vector<int> v1 = par.first;
			bool is_ans = true;
			for (auto elem : v) {
				if (find(v1.begin(), v1.end(), elem) == v1.end()) {
					is_ans = false;
					break;
				}
			}
			if (is_ans && ans > par.second.first) {
				ans = par.second.first;
				number = par.second.second + 1;
			}
			else if (is_ans && ans == par.second.first && number > par.second.second + 1){
				ans = par.second.first;
				number = par.second.second + 1;
			}
		}
		cout << number << "\n";
	}
}


struct Rectangle {
	int x1, y1, x2, y2;

	bool coll(Rectangle a) {
		return !(a.x2 < x1 || a.x1 > x2 || a.y1 > y2 || a.y2 < y1);
	}
};


void solve() {
	int w, h;
	cin >> w >> h;
	int n;
	cin >> n; 
	int max_x = -INF, min_x = INF, max_y = -INF, min_y = INF;
	vector<Rectangle> rect(n);
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Rectangle a;
		a.x1 = x1;
		a.y1 = y1;
		a.x2 = x2;
		a.y2 = y2;
		min_x = min(min_x, x1);
		max_x = max(max_x, x2);
		min_y = min(min_y, y1);
		max_y = max(max_y, y2);
		rect[i] = a;
	}
	Rectangle a;
	int ans = 0;
	for (int x = min_x; x < max(min_x + 1, max_x - w); ++x) {
		for (int y = min_y; y < max(min_y + 1, max_y - h); ++y) {
			a.x1 = x;
			a.x2 = x + w;
			a.y1 = y;
			a.y2 = y + h;
			int tmp_ans = 0;
			for (auto r : rect) {
				if (r.coll(a)) tmp_ans++;
			}
			ans = max(ans, tmp_ans);
		}
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//	cin >> t;
	t = 1;
	while (t--) {
		cout << fixed;
		cout.precision(15);
		solve();
	}
	return 0;
}
