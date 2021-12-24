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
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<set<int>> g;
vector<bool> used;
map<int, int> comp;
int c = 1;


void dfs(int v) {
	used[v] = true;
	for (auto u : g[v]) {
		if (!used[u]) dfs(u);
	}
}



void solve() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n, false);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		c--;
		g[a].insert(c);
		g[c].insert(a);
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			comp[c] = i;
			dfs(i);
			c++;
		}
	}
	for (int i = 1; i < c - 1; ++i) {
		g[comp[i]].insert(comp[i + 1]);
		g[comp[i + 1]].insert(comp[i]);
	}
	set<pair<int, int>> ans;
	for (int v = 0; v < n; ++v) {
		for (auto u : g[v]) {
			ans.insert({ min(v, u) + 1, max(v,u) + 1 });
		}
	}
	for (auto elem : ans) {
		cout << elem.first << " " << elem.second << "\n";
	}
	used.clear();
	g.clear();
	c = 1;
	comp.clear();
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
