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
const short sh_INF = 32766;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<vector<int>> g;
vector<bool> used;
vector<int> dist;
//map<int, int> mp;
int x1 = -1, x2 = -1;

void bfs(int s) {
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : g[v]) {
			if (dist[v] + 1 < dist[u]) {
				q.push(u);
				dist[u] = dist[v] + 1;
			}
		}
	}
}

void dfs_find_way(int v, int to, vector<int> &way) {
	used[v] = true;
	if (v == to) {
		if (way.size() % 2 == 0) {
			x1 = way[way.size() / 2 - 1];
			x2 = way[way.size() / 2];
		}
		else {
			x1 = way[way.size() / 2];
			//		x2 = way[way.size() / 2 + 1];
		}
	}
	for (auto u : g[v]) {
		if (!used[u]) {
			way.push_back(u);
			dfs_find_way(u, to, way);
			way.pop_back();
		}
	}
	used[v] = false;
}


void dfs(int v) {
	used[v] = true;
	bool flag = true;
	for (auto u : g[v]) {
		if (!used[u]) {
			flag = false;
			dfs(u);
			dist[v] = max(dist[v], dist[u] + 1);
		}
	}
	if (flag) {
		dist[v] = 1;
	}
}


void solve() {
	int n, k;
	cin >> n >> k;
	g.resize(n);
	used.resize(n, false);
	dist.resize(n, INF);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if ((n == 1 || n == 2) && k >= 1) {
		g.clear();
		//		d.clear();
		dist.clear();
		used.clear();
		//		mp.clear();
		cout << "0\n";
		return;
	}
	bfs(0);
	int max_dist = 0, v = -1;
	for (int i = 0; i < n; ++i) {
		if (dist[i] > max_dist) {
			max_dist = dist[i];
			v = i;
		}
	}
	dist.assign(n, INF);
	bfs(v);
	max_dist = 0;
	int u = -1;
	for (int i = 0; i < n; ++i) {
		if (dist[i] > max_dist) {
			max_dist = dist[i];
			u = i;
		}
	}
	vector<int> way = { v };
	dfs_find_way(v, u, way);
	dist.assign(n, 0);
	if (x2 == -1) {
		dfs(x1);
	}
	else {
		used[x1] = true;
		used[x2] = true;
		dfs(x1);
		dfs(x2);
	}
	int k1 = 0;
	sort(dist.begin(), dist.end());
	int ans = n;
	while (k1 < n && k > 0) {
		int x = dist[k1];
		while (k1 < n && dist[k1] == x) {
			k1++;
			ans--;
		}
		k--;
	}
	cout << ans << "\n";
	g.clear();
	//	d.clear();
	dist.clear();
	used.clear();
	//	mp.clear();
	x1 = x2 = -1;
}


signed main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 1;
	//	gen.seed(time(0));
	//	cout << fixed;
	//	cout.precision(15);
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
