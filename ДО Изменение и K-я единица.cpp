#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e9;


struct SegTree {
	struct Node {
		long long sum;
		long long op;
	};

	long long size = 1;
	vector<Node> tree;

	void init(long long n) {
		while (size <= n) {
			size *= 2;
		}
		tree.assign(2 * size, { 0, INF });
	}

	void propagate(long long x, long long lx, long long rx) {
		if (rx - lx == 1 || tree[x].op == INF) {
			return;
		}
		tree[2 * x + 1].sum = tree[2 * x + 2].sum = tree[x].op * (rx - lx) / 2;
		tree[2 * x + 1].op = tree[2 * x + 2].op = tree[x].op;
		tree[x].op = INF;
	}

	void modify(long long v, long long x, long long lx, long long rx, long long l, long long r) {
		propagate(x, lx, rx);
		if (l >= rx || r <= lx) {
			return;
		}
		if (rx <= r && lx >= l) {
			tree[x].op = v;
			tree[x].sum = (rx - lx) * v;
			return;
		}
		long long m = (rx + lx) / 2;
		modify(v, 2 * x + 1, lx, m, l, r);
		modify(v, 2 * x + 2, m, rx, l, r);
		tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum;
	}

	long long get_sum(long long x, long long lx, long long rx, long long l, long long r) {
		propagate(x, lx, rx);
		if (l >= rx || r <= lx) {
			return 0;
		}
		if (rx <= r && lx >= l) {
			return tree[x].sum;
		}
		long long m = (rx + lx) / 2;
		long long left = get_sum(2 * x + 1, lx, m, l, r);
		long long right = get_sum(2 * x + 2, m, rx, l, r);
		return left + right;
	}

	long long get_sum(long long l, long long r) {
		return get_sum(0, 0, size, l, r);
	}

	void modify(long long v, long long l, long long r) {
		modify(v, 0, 0, size, l, r);
	}
};


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	long long n, q;
	cin >> n >> q;
	SegTree tree;
	tree.init(n);
	while (q--) {
		long long c;
		cin >> c;
		if (c == 1) {
			long long l, r, v;
			cin >> l >> r >> v;
			tree.modify(v, l, r);
		}
		else {
			long long l, r;
			cin >> l >> r;
			cout << tree.get_sum(l, r) << "\n";
		}
	}
	return 0;
}
