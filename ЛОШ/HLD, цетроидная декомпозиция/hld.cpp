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

vector<vector<int>> up, g;
vector<int> d, tin, way, rootway, sz;
vector<bool> used;
int timer = 0;

struct SegTree {
	vector<int> tree;
	int size = 1;

	void init(int n) {
		while (size < n) {
			size *= 2;
		}
		tree.assign(2 * size, 0);
	}

	void init(int n, vector<int> a) {
		while (size < n) {
			size *= 2;
		}
		tree.assign(2 * size, 0);
		build(a, 0, 0, size);
	}

	void build(vector<int> a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				tree[x] = a[x];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void set(int v, int i, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] += v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(v, i, 2 * x + 1, lx, m);
		}
		else {
			set(v, i, 2 * x + 2, m, rx);
		}
		tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
	}

	int get_max(int x, int lx, int rx, int l, int r) {
		if (l >= rx || r <= lx) {
			return 0;
		}
		if (l >= lx && r <= rx) {
			return tree[x];
		}
		int m = (rx + lx) / 2;
		int left = get_max(2 * x + 1, lx, m, l, r);
		int right = get_max(2 * x + 2, m, rx, l, r);
		return max(left, right);
	}

	int get_max(int l, int r) {
		return get_max(0, 0, size, l, r);
	}

	void set(int v, int i) {
		set(v, i, 0, 0, size);
	}

};


bool comp(int a, int b) {
	return sz[a] > sz[b];
}


void hld(int v, int p = -1) {
	if (p == -1) {
		p = v;
	}
	used[v] = true;
	rootway[v] = p;
	tin[v] = timer++;
	way.push_back(v);
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (used[u]) {
			continue;
		}
		if (i == 0 && sz[u] >= sz[v] / 2) {
			hld(u, p);
		}
		else {
			hld(u);
		}
	}
}


void dfs(int v, int depth, int p) {
	used[v] = true;
	d[v] = depth;
	up[v][0] = p;
	sz[v] = 1;
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u, depth + 1, v);
			sz[v] += sz[u];
		}
	}
}


int jump(int u, int h) {
	for (int k = 20; k > -1; k--) {
		if ((1 << k) <= h) {
			u = up[u][k];
			h -= (1 << k);
		}
	}
	return u;
}

int LCA(int u, int v) {
	if (u == v) {
		return u;
	}
	for (int k = 19; k > -1; k--) {
		if (up[u][k] != up[v][k]) {
			u = up[u][k];
			v = up[v][k];
		}
	}
	return up[u][0];
}


int find_LCA(int u, int v) {
	if (d[v] < d[u]) {
		swap(v, u);
	}
	v = jump(v, d[v] - d[u]);
	return LCA(v, u);
}


bool isparent(int u, int v) {
	if (find_LCA(u, v) == u) {
		return true;
	}
	return false;
}



void solve() {
	int n, m, k = 20;
	cin >> n;
	n++;
	g.resize(n);
	d.resize(n);
	up.resize(n, vector<int>(k, 0));
	tin.resize(n);
	used.resize(n, false);
	rootway.resize(n);
	sz.resize(n);
	used[0] = true;
	for (int i = 0; i < n - 2; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	g[0].push_back(1);
	g[1].push_back(0);
	dfs(1, 0, 0);
	up[0][0] = 0;
	for (int i = 0; i < k - 1; ++i) {
		for (int u = 1; u < n; ++u) {
			up[u][i + 1] = up[up[u][i]][i];
		}
	}
	for (int i = 0; i < n; ++i) {
		sort(g[i].begin(), g[i].end(), comp);
	}
	used.assign(n, false);
	used[0] = true;
	hld(0, -1);
	cin >> m;
	SegTree tree;
	tree.init(way.size());
	while (m--) {
		char c;
		cin >> c;
		if (c == 'I') {
			int u, v;
			cin >> u >> v;
			tree.set(v, tin[u]);
		}
		else {
			int u, v;
			cin >> u >> v;
			u--, v--;
			int w = find_LCA(u, v);
			int ans = 0;
			while (!isparent(rootway[u], w)) {
				ans  = max(ans, tree.get_max(tin[rootway[u]], tin[u] + 1));
				u = up[rootway[u]][0];
			}
			ans = max(ans, tree.get_max(tin[w], tin[u]));
			while (!isparent(rootway[v], w)) {
				ans = max(ans, tree.get_max(tin[rootway[v]], tin[v] + 1));
				v = up[rootway[v]][0];
			}
			ans = max(ans, tree.get_max(tin[w], tin[v]));
			ans = max(ans, tree.get_max(tin[w], tin[w]));
			cout << "\n" << ans << "\n";
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
