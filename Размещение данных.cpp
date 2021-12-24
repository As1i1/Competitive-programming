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
vector<vector<int>> g, g_comp;
vector<int> tin, fup, comp, comp_size;
vector<bool> used;
vector<pair<int, int>> most;
int timer = 0, color = 1;


void dfs_most_find(int v){
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for(auto u: g[v]){
		if (used[u]){
			fup = min(fup[v], tin[u]);
		}
		else{
			dfs(u);
			fup[v] = min(fup[v], fup[u]);
			if (fup[u] > tin[v]){
				most.push_back({min(u, v), max(v, u)});
			}
		}
	}
}


void dfs(int v){
	used[v] = true;
}


void solve(){
	int n, m;
	cin >> n >> m;
	g.resize(n);
	tin.resize(n);
	fup.resize(n);
	comp.resize(n);
	used.resize(n, false);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 0; i < n; ++i){
		if (!used[i]) dfs(i);
	}
	used.resize(n, false);
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
	while(t--){
		solve();
	}
	return 0;
}
