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


struct SegTree_max_min {
	vector<pair<int, int>> tree;
	int size = 1;

	void init(int n, vector<int>& a) {
		while (n > size) {
			size *= 2;
		}
		tree.assign(2 * size, { 0, 0 });
		build(0, 0, size, a);
	}

	void build(int x, int lx, int rx, vector<int>& a) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				tree[x] = { a[lx], a[lx] };
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(2 * x + 1, lx, m, a);
		build(2 * x + 2, m, rx, a);
		tree[x].first = max(tree[2 * x + 1].first, tree[2 * x + 2].first);
		tree[x].second = min(tree[2 * x + 1].second, tree[2 * x + 2].second);
	}

	int get_max(int x, int l, int r, int lx, int rx) {
		if (rx <= l || r <= lx) {
			return -1;
		}
		if (l <= lx && r >= rx) {
			return tree[x].first;
		}
		int m = (lx + rx) / 2;
		int left = get_max(2 * x + 1, l, r, lx, m);
		int rigth = get_max(2 * x + 2, l, r, m, rx);
		return max(left, rigth);
		return max(get_max(2 * x + 1, l, r, lx, m), get_max(2 * x + 2, l, r, m, rx));
	}

	int get_min(int x, int l, int r, int lx, int rx) {
		if (rx <= l || r <= lx) {
			return INF;
		}
		if (l <= lx && r >= rx) {
			return tree[x].second;
		}
		int m = (lx + rx) / 2;
		return min(get_min(2 * x + 1, l, r, lx, m), get_min(2 * x + 2, l, r, m, rx));
	}

	int get_max(int l, int r) {
		return get_max(0, l, r, 0, size);
	}

	int get_min(int l, int r) {
		return get_min(0, l, r, 0, size);
	}

};


struct SegTree_cnt {
	vector<set<int>> tree;
	int size = 1;

	void init(int n, vector<int>& a) {
		while (n > size) {
			size *= 2;
		}
		tree.assign(2 * size, {});
		build(0, 0, size, a);
	}

	void build(int x, int lx, int rx, vector<int>& a) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				tree[x] = { a[lx] };
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(2 * x + 1, lx, m, a);
		build(2 * x + 2, m, rx, a);
		set<int> c = tree[2 * x + 1], b = tree[2 * x + 2];
		if (c.size() > b.size()) {
			swap(c, b);
		}
		for (auto elem : c) {
			b.insert(elem);
		}
		tree[x] = b;
	}

	set<int> get_cnt(int x, int l, int r, int lx, int rx) {
		if (rx <= l || r <= lx) {
			return {};
		}
		if (l <= lx && r >= rx) {
			return tree[x];
		}
		int m = (lx + rx) / 2;
		set<int> left = get_cnt(2 * x + 1, l, r, lx, m), right = get_cnt(2 * x + 2, l, r, m, rx);
		if (left.size() > right.size()) {
			swap(left, right);
		}
		for (auto elem : left) {
			right.insert(elem);
		}
		return right;
	}

	int get_cnt(int l, int r) {
		return get_cnt(0, l, r, 0, size).size();
	}
};



void solve() {
	int n;
	cin >> n;
	vector<int> a(n), t, nt;
	map<pair<int, int>, int> mp;
	int c = 0;
	cin >> a[0];
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		pair<int, int> p = { max(a[i], a[i - 1]), min(a[i], a[i - 1]) };
		if (a[i - 1] == a[i]) {
			mp[p] = -1;
		}
		else if (mp.find(p) == mp.end()) {
			mp[p] = c;
			c++;
		}
		if (i % 2 == 0) {
			nt.push_back(mp[p]);
		}
		else {
			t.push_back(mp[p]);
		}
	}
	SegTree_max_min mx, mn_t, mn_nt;
	mx.init(n, a);
	mn_t.init(t.size(), t);
	mn_nt.init(nt.size(), nt);
	SegTree_cnt cnt_t, cnt_nt;
	cnt_t.init(t.size(), t);
	cnt_nt.init(nt.size(), nt);
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == 0 || a[i + 1] * 2 >= n - i - 1) continue;
		if (i % 2 == 1) {
			int mx1 = mx.get_max(i + 2, i + 2 + a[i + 1] * 2 );
			int mn = mn_nt.get_min(i / 2 + 1, i / 2 + a[i + 1] + 1);
			int cnt = cnt_nt.get_cnt(i / 2 + 1, i / 2 + a[i + 1] + 1);
			if (mx1 <= a[i] && mn != -1 && cnt == a[i + 1]) ans++;
		}
		else {
			int mx1 = mx.get_max(i + 2, i + 2 + a[i + 1] * 2);
			int mn = mn_t.get_min(i / 2 + 1, i / 2 + a[i + 1] + 1);
			int cnt = cnt_t.get_cnt(i / 2 + 1, i / 2 + a[i + 1] + 1);
			if (mx1 <= a[i] && mn != -1 && cnt == a[i + 1]) ans++;
		}
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
	//  cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
