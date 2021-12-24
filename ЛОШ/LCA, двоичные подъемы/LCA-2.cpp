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
	long long a1, a2, x, y, z;
	cin >> a1 >> a2 >> x >> y >> z;
	vector<int> a(2 * m, 0);
	a[0] = a1;
	a[1] = a2;
	long long v, ans = 0;
	for (int i = 2; i < 2 * m; ++i) {
		a[i] = (x * a[i - 2] + y * a[i - 1] + z) % n;
	}
	int l = min(pos[a1], pos[a2]), r = max(pos[a1], pos[a2]), j = lgo[r - l + 1];
	if (d[mn[l][j]] <= d[mn[r - (1 << j) + 1][j]]) {
		v = mn[l][j];
	}
	else {
		v = mn[r - (1 << j) + 1][j];
	}
	ans += v;
	//	cout << a1 << " " << a2 << " " << v << "\n";
	for (int i = 1; i < m; ++i) {
		int a1 = (a[i * 2] + v) % n, a2 = a[i * 2 + 1];
		int l = min(pos[a1], pos[a2]), r = max(pos[a1], pos[a2]), j = lgo[r - l + 1];
		if (d[mn[l][j]] <= d[mn[r - (1 << j) + 1][j]]) {
			v = mn[l][j];
		}
		else {
			v = mn[r - (1 << j) + 1][j];
		}
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
