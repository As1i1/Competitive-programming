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
#include <bitset>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<vector<int>> g1, g2, up2, up1;
vector<int> h2, h1;


void dfs1(int v, int p = 0, int depth = 0) {
	h1[v] = depth;
	up1[v][0] = p;
	for (int i = 1; i < 22; ++i) {
		up1[v][i] = up1[up1[v][i - 1]][i - 1];
	}
	for (auto u : g1[v]) {
		if (u != p) {
			dfs1(u, v, depth + 1);
		}
	}
}


void dfs2(int v, int p = 0, int depth = 0) {
	h2[v] = depth;
	up2[v][0] = p;
	for (int i = 1; i < 22; ++i) {
		up2[v][i] = up2[up2[v][i - 1]][i - 1];
	}
	for (auto u : g2[v]) {
		if (u != p) {
			dfs2(u, v, depth + 1);
		}
	}
}


int jump1(int v, int d) {
	for (int i = 21; i >= 0; i--) {
		if ((1 << i) <= d) {
			v = up1[v][i];
			d -= (1 << i);
		}
	}
	return v;
}

int LCA1(int u, int v) {
	int ans = 0;
	if (h1[v] < h1[u]) {
		swap(v, u);
	}
	ans += h1[v] - h1[u];
	v = jump1(v, h1[v] - h1[u]);
	if (v == u) {
		return ans;
	}
	int u1 = u, v1 = v;
	for (int i = 21; i >= 0; --i) {
		if (up1[v][i] != up1[u][i]) {
			v = up1[v][i];
			u = up1[u][i];
		}
	}
	int t = up1[u][0];
	return ans + h1[v1] - h1[t] + h1[u1] - h1[t];
}


int jump2(int v, int d) {
	for (int i = 21; i >= 0; i--) {
		if ((1 << i) <= d) {
			v = up2[v][i];
			d -= (1 << i);
		}
	}
	return v;
}

int LCA2(int u, int v) {
	int ans = 0;
	if (h2[v] < h2[u]) {
		swap(v, u);
	}
	ans += h2[v] - h2[u];
	v = jump2(v, h2[v] - h2[u]);
	if (v == u) {
		return ans;
	}
	int u1 = u, v1 = v;
	for (int i = 21; i >= 0; --i) {
		if (up2[v][i] != up2[u][i]) {
			v = up2[v][i];
			u = up2[u][i];
		}
	}
	int t = up2[u][0];
	return ans + h2[v1] - h2[t] + h2[u1] - h2[t];
}



void solve() {
	int n;
	cin >> n;
	g1.resize(n);
	g2.resize(n);
	up2.resize(n, vector<int>(22, -1));
	h2.resize(n);
	up1.resize(n, vector<int>(22, -1));
	h1.resize(n);
	for (int i = 1; i < n; ++i) {
		int u;
		cin >> u;
		u--;
		g1[u].push_back(i);
		g1[i].push_back(u);
	}
	for (int i = 1; i < n; ++i) {
		int u;
		cin >> u;
		u--;
		g2[u].push_back(i);
		g2[i].push_back(u);
	}
	dfs1(0);
	dfs2(0);
	int ans = INF;
	pair<int, int> p = { -1, -1 };
	for (int v = 0; v < n; ++v) {
		for (int u = v + 1; u < n; ++u) {
			int tmp = LCA1(u, v) + LCA2(u, v);
			if (tmp < ans) {
				ans = tmp;
				p = { u, v };
			}
		}
	}
	cout << ans << "\n" << p.first + 1 << " " << p.second + 1;
}



signed main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 1;
	//	gen.seed(time(0));
	//	cout << fixed;
	//	cout.precision(15);
	//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
