#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll ll_INF = 1e18;

vector<vector<int>> up, g;
vector<	long long> d, way, pos, lgo;
vector<bool> used;


int jump(int u, int h) {
	for (int k = 19; k > -1; k--) {
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


void dfs(int v, int depth) {
	used[v] = true;
	d[v] = depth;
	pos[v] = way.size();
	way.push_back(v);
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u, depth + 1);
			way.push_back(v);
		}
	}
}


int min(int a, int b) {
	if (a == INF) return b;
	if (b == INF) return a;
	if (d[a] <= d[b]) return a;
	else return b;
}


struct SegTree {
	vector<long long> tree;
	int size = 1;

	void init(int N, vector<long long> a) {
		while (size < N) {
			size *= 2;
		}
		tree.assign(size * 2, INF);
		build(a, 0, 0, size);
	}

	void build(vector<long long> a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				tree[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		if (tree[2 * x + 1] == INF) tree[x] = tree[2 * x + 2];
		else if (tree[2 * x + 2] == INF) tree[x] = tree[2 * x + 1];
		else if (tree[2 * x + 1] == INF && tree[2 * x + 2] == INF) tree[x] = INF;
		else if (d[tree[2 * x + 1]] <= d[tree[2 * x + 2]]) tree[x] = tree[2 * x + 1];
		else tree[x] = tree[2 * x + 2];
	//	tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
	}

	long long get_min(int x, int lx, int rx, int l, int r) {
		if (rx <= l || lx >= r) {
			return INF;
		}
		if (l <= lx && rx <= r) {
			return tree[x];
		}
		int m = (rx + lx) / 2;
		int a = get_min(2 * x + 1, lx, m, l, r);
		int b = get_min(2 * x + 2, m, rx, l, r);
		if (a == INF) return b;
		if (b == INF) return a;
		if (d[a] <= d[b]) return a;
		else return b;
	}
	
	long long get_min(int l, int r) {
		return get_min(0, 0, size, l, r);
	}

};



void solve() {
	int n, m, k = 20;
	cin >> n >> m;
	g.resize(n);
	pos.resize(n);
	d.resize(n);
	used.resize(n, false);
	for (int i = 0; i < n - 1; ++i) {
		int tmp;
		cin >> tmp;
		g[tmp].push_back(i + 1);
		g[i + 1].push_back(tmp);
	}
	dfs(0, 0);
	long long a1, a2, x, y, z;
	cin >> a1 >> a2 >> x >> y >> z;
	vector<int> a(2 * m, 0);
	a[0] = a1;
	a[1] = a2;
	long long v, ans = 0;
	for (int i = 2; i < 2 * m; ++i) {
		a[i] = (x * a[i - 2] + y * a[i - 1] + z) % n;
	}
	SegTree tree;
	tree.init(way.size(), way);
	v = tree.get_min(min(pos[a1], pos[a2]), max(pos[a1], pos[a2]) + 1);
	ans += v;
//	cout << a1 << " " << a2 << " " << v << "\n";
	for (int i = 1; i < m; ++i) {
		int a1 = (a[i * 2] + v) % n, a2 = a[i * 2 + 1];
		v = tree.get_min(min(pos[a1], pos[a2]), max(pos[a1], pos[a2]) + 1);
		ans += v;
	//	cout << a1 << " " << a2 << " " << v << "\n";
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
		solve();
	}
	return 0;
}
