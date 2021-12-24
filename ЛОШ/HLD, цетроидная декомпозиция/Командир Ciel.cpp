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
const ll ll_INF = 1e18;
vector<int> sz;
vector<char> ans;
vector<vector<int>> g;
vector<bool> used;
int n;


int centroid(int v, int p, int n) {
	for (int u : g[v])
		if (sz[u] > n / 2 && u != p)
			return centroid(u, v, n);
	return v;
}


void dfs(int v, int p) {
	sz[v] = 1;
	used[v] = true;
	for (auto u : g[v]) {
		if (!used[u] && u != p) {
			dfs(u, p);
			sz[v] += sz[u];
		}
	}
	used[v] = false;
}


void decomposition(int v) {
	//sz.assign(n, 0);
	vector<int> nxt;
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u, v);
			int c = centroid(u, v, sz[u]);
			ans[c] = ans[v] + 1;
			nxt.push_back(c);
		}
	}
	used[v] = true;
	for (auto c : nxt) {
		sz[c] = 0;
		decomposition(c);
	}
}


void solve() {
	cin >> n;
	g.resize(n);
	sz.resize(n, 0);
	used.assign(n, false);
	ans.assign(n, 0);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0);
	used.assign(n, false);
	int start = centroid(0, 0, n);
	ans[start] = 'A';
	used[start] = true;
	sz[start] = 0;
	decomposition(start);
	for (auto elem : ans) {
		cout << elem << " ";
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
