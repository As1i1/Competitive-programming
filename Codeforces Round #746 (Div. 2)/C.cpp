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
vector<vector<int>> g;
vector<int> a, dp;
vector<bool> used;


void dfs(int v){
	used[v] = true;
	for(auto u: g[v]){
		if(!used[u]){
			dfs(u);
			dp[v] = dp[u] ^ dp[v];
		}
	}
}


void solve(){
	int n, k;
	cin >> n >> k;
	a.resize(n);
	g.resize(n);
	used.resize(n, false);
	dp.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		dp[i] = a[i];
	}
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	for(int i = 0; i < n; ++i){
		cout << dp[i] << " ";
	}
	cout << "   A\n";
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
