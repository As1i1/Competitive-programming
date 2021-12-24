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

vector<vector<pair<int, int>>> up;
vector < vector<int>> g;
map<pair<int, int>, int> mp;
vector<int> d;
vector<bool> used;


void dfs(int v, int depth, int p) {
	used[v] = true;
	d[v] = depth;
	up[v][0] = { p, mp[{min(p, v), max(p, v)}] };
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u, depth + 1, v);
		}
	}
}

int up_to(int v, int u) {

}


pair<int, int> jump(int u, int h) {
	int edge = INF;
	for (int k = 19; k > -1; k--) {
		if ((1 << k) <= h) {
			edge = min(edge, up[u][k].second);
			u = up[u][k].first;
			h -= (1 << k);
		}
	}
	return { u, edge };
}

int LCA(int u, int v) {
	int edge = INF;
	if (u == v) {
		return edge;
	}
	for (int k = 19; k > -1; k--) {
		if (up[u][k] != up[v][k]) {
			edge = min({ edge, up[u][k].second, up[v][k].second });
			u = up[u][k].first;
			v = up[v][k].first;
		}
	}
	return min({ edge, up[u][0].second, up[v][0].second });
}



void solve() {
	int n, m, k = 20;
	cin >> n;
	n++;
	g.resize(n);
	d.resize(n);
	up.resize(n, vector<pair<int, int>>(20, { 0, 0 }));
	used.resize(n, false);
	used[0] = true;
	for (int i = 0; i < n - 2; ++i) {
		int p, c;
		cin >> p >> c;
		g[p].push_back(i + 2);
		g[i + 2].push_back(p);
		mp[{min(p, i + 2), max(p, i + 2)}] = c;
	}
	g[0].push_back(1);
	g[1].push_back(0);
	dfs(1, 0, 0);
	up[0][0] = { 0, 0 };
	for (int i = 0; i < k - 1; ++i) {
		for (int u = 0; u < n; ++u) {
			up[u][i + 1].first = up[up[u][i].first][i].first;
			up[u][i + 1].second = min(up[u][i].second, up[up[u][i].first][i].second);
		}
	}
	cin >> m;
	while (m--) {
		int v, u;
		cin >> v >> u;
		if (d[v] < d[u]) {
			swap(v, u);
		}
		pair<int, int> p = jump(v, d[v] - d[u]);
		int new_v = p.first, ans = p.second;
		int t = LCA(new_v, u);
		cout << min(ans, t) << "\n";
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
