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

const int INF = 1e9;
const ll ll_INF = 1e18;


struct SegTree {
	vector<pair<ll, ll>> tree;
	int size = 1;

	void init(int n, vector<ll> a) {
		while (size < n) {
			size *= 2;
		}
		tree.assign(size * 2, { 0, 0 });
		build(a, 0, 0, size);
	}

	void build(vector<ll> a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				tree[x].first = a[lx];
			}
			return;
		}
		int m = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		tree[x].first = max(tree[2 * x + 1].first, tree[2 * x + 2].first);
	}

	void add(ll v, int l, int r, int x, int lx, int rx) {
		if (rx <= l || r <= lx) {
			return;
		}
		if (lx >= l && rx <= r) {
			tree[x].second += v;
			return;
		}
		int m = (lx + rx) / 2;
		add(v, l, r, 2 * x + 1, lx, m);
		add(v, l, r, 2 * x + 2, m, rx);
		tree[x].first = max(tree[2 * x + 1].first + tree[2 * x + 1].second, tree[2 * x + 2].first + tree[2 * x + 2].second);
	}

	ll get_max(int x, int lx, int rx, int l, int r) {
		if (rx <= l || r <= lx) {
			return 0;
		}
		if (lx >= l && rx <= r) {
			return tree[x].first + tree[x].second;
		}
		int m = (lx + rx) / 2;
		ll left = get_max(2 * x + 1, lx, m, l, r);
		ll right = get_max(2 * x + 2, m, rx, l, r);
		return max(left, right) + tree[x].second;
	}

	ll get_max(int l, int r) {
		return get_max(0, 0, size, l, r);
	}

	void add(ll v, int l, int r) {
		add(v, l, r, 0, 0, size);
	}
};


void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	SegTree tree;
	tree.init(n, a);
	int q;
	n = tree.size;
	cin >> q;
	while (q--) {
		char c;
		cin >> c;
		if (c == 'a') {
			int l, r, v;
			cin >> l >> r >> v;
			l--;
			tree.add(v, l, r, 0, 0, n);
		}
		else {
			int l, r;
			cin >> l >> r;
			l--;
			cout << tree.get_max(0, 0, n, l, r) << " ";
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//	cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
