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
vector<int> d;
vector<bool> used;


void dfs(int v, int depth, int p) {
	used[v] = true;
	d[v] = depth;
	up[v][0] = p;
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u, depth + 1, v);
		}
	}
}


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



void solve() {
	int n, m, k = 20;
	cin >> n;
	n++;
	g.resize(n);
	d.resize(n);
	up.resize(n, vector<int>(20, 0));
	used.resize(n, false);
	used[0] = true;
	for (int i = 0; i < n - 2; ++i) {
		int u, v;
		up[i].resize(k);
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	g[0].push_back(1);
	g[1].push_back(0);
	dfs(1, 0, 0);
	up[0][0] = 0;
	for (int i = 0; i < k - 1; ++i) {
		for (int u = 0; u < n; ++u) {
			up[u][i + 1] = up[up[u][i]][i];
		}
	}
	cin >> m;
	while (m--) {
		int v, u, ans = 0;
		cin >> v >> u;
		if (d[v] < d[u]) {
			swap(v, u);
		}
		ans += d[v] - d[u];
		v = jump(v, d[v] - d[u]);
		int t = LCA(v, u);
		cout << ans + d[v] - d[t] + d[u] - d[t] << "\n";
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
