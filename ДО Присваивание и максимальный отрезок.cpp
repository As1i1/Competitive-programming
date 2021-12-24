#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e9;


struct SegTree {
	struct Node {
		long long sum, seg, pref, suf, op;
	};

	long long size = 1;
	vector<Node> tree;

	void init(long long n) {
		while (size <= n) {
			size *= 2;
		}
		tree.assign(2 * size, { 0, 0, 0, 0, INF });
	}

	void propagate(long long x, long long lx, long long rx) {
		if (rx - lx == 1 || tree[x].op == INF) {
			return;
		}
		tree[2 * x + 1].sum = tree[2 * x + 2].sum = tree[x].op * (rx - lx) / 2;
		tree[2 * x + 1].op = tree[2 * x + 2].op = tree[x].op;
		if (tree[2 * x + 1].sum > 0) {
			tree[2 * x + 1].seg = tree[2 * x + 1].pref = tree[2 * x + 1].suf = tree[2 * x + 1].sum;
		}
		else {
			tree[2 * x + 1].seg = tree[2 * x + 1].pref = tree[2 * x + 1].suf = 0;
		}
		if (tree[2 * x + 2].sum > 0) {
			tree[2 * x + 2].seg = tree[2 * x + 2].pref = tree[2 * x + 2].suf = tree[2 * x + 2].sum;
		}
		else {
			tree[2 * x + 2].seg = tree[2 * x + 2].pref = tree[2 * x + 2].suf = 0;
		}
		tree[x].op = INF;
	}

	Node combine(Node a, Node b) {
		Node c;
		c.sum = a.sum + b.sum;
		c.pref = max(a.sum + b.pref, a.pref);
		c.suf = max(a.suf + b.sum, b.suf);
		c.sum = a.sum + b.sum;
		c.seg = max({ a.seg, b.seg, a.suf + b.pref });
		c.op = INF;
		return c;
	}

	void modify(long long v, long long x, long long lx, long long rx, long long l, long long r) {
		propagate(x, lx, rx);
		if (l >= rx || r <= lx) {
			return;
		}
		if (rx <= r && lx >= l) {
			tree[x].op = v;
			tree[x].sum = (rx - lx) * v;
			if (v > 0) {
				tree[x].seg = tree[x].pref = tree[x].suf = tree[x].sum;
			}
			else {
				tree[x].seg = tree[x].pref = tree[x].suf = 0;
			}
			return;
		}
		long long m = (rx + lx) / 2;
		modify(v, 2 * x + 1, lx, m, l, r);
		modify(v, 2 * x + 2, m, rx, l, r);
		tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
	}

	Node get_mx(long long x, long long lx, long long rx, long long l, long long r) {
		propagate(x, lx, rx);
		if (l >= rx || r <= lx) {
			return { 0, 0, 0, 0, INF };
		}
		if (rx <= r && lx >= l) {
			return tree[x];
		}
		long long m = (rx + lx) / 2;
		Node left = get_mx(2 * x + 1, lx, m, l, r);
		Node right = get_mx(2 * x + 2, m, rx, l, r);
		return combine(left, right);
	}

	long long get_mx(long long l, long long r) {
		return get_mx(0, 0, size, l, r).seg;
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
		long long l, r, v;
		cin >> l >> r >> v;
		tree.modify(v, l, r);
		cout << tree.get_mx(0, n) << "\n";
	}
	return 0;
}
