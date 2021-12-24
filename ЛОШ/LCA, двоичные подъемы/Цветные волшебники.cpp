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
vector<	long long> d, way, pos, lgo, par;
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


void bfs(int v){
	queue<int> q;
	d[v] = 0;
	par[v] = v;
	q.push(v);
	whlie(!q.empty()){
		int v = *q.front();
		q.pop();
		for(auto u: g[v]){
			if (d[v] + 1 < d[u]){
				q.push(u);
				d[u] = d[v] + 1;
				par[u] = v;
			}
		}
	}
}


void dfs(int v) {
	used[v] = true;
	pos[v] = way.size();
	way.push_back(v);
	for (auto u : g[v]) {
		if (!used[u] && par[u] == v) {
			dfs(u);
			way.push_back(v);

		}
	}
}



void solve() {
	int n, m, k = 20, start;
	cin >> n >> m >> start;
	start--;
	g.resize(n, INF);
	par.resize(n);
	pos.resize(n);
	d.resize(n);
	used.resize(n, false);
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	bfs(start);
	dfs(start);
	vector<vector<int>> mn(way.size(), vector<int>(k, 0));
	for (int i = 0; i < way.size(); ++i) {
		mn[i][0] = way[i];
	}
	for (int j = 1; j <= k; j++) {
		for (int i = 0; i + (1 << j) <= way.size(); i++) {
			if (d[mn[i][j - 1]] < d[mn[i + (1 << (j - 1))][j - 1]]) {
				mn[i][j] = mn[i][j - 1];
			}
			else {
				mn[i][j] = mn[i + (1 << (j - 1))][j - 1];
			}
		}
	}
	lgo.resize(way.size() + 1);
	lgo[1] = 0;
	for (int i = 2; i <= way.size(); ++i) {
		lgo[i] = lgo[i / 2] + 1;
	}
	for (int i = 1; i < m; ++i) {
		int v, u, ans;
		cin >> v >> u;
		v--;u--;
		int l = min(pos[v], pos[u]), r = max(pos[v], pos[u]), j = lgo[r - l + 1];
		if (d[mn[l][j]] <= d[mn[r - (1 << j) + 1][j]]) {
			ans = mn[l][j];
		}
		else {
			ans = mn[r - (1 << j) + 1][j];
		}
		cout << d[ans] << "\n";
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
