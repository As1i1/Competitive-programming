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
vector<vector<int>> g;
vector<set<int>> colors;
vector<int> ans;


void dfs(int v){
	for(auto u: g[v]){
		dfs(u);
		if (colors[v].size() < colors[u].size()){
			swap(colors[v], colors[u]);
		}
		for(auto elem: colors[u]){
			colors[v].insert(elem);
		}
		colors[u].clear();
	}
	ans[v] = colors[v].size();
}


void solve(){
	int n, start = -1;
	cin >> n;
	g.resize(n);
	ans.resize(n);
	colors.resize(n);
	for(int i = 0; i < n; ++i){
		int p, c;
		cin >> p >> c;
		p--;
		if (p == -1){
			start = i;
		}
		else{
			g[p].push_back(i);
		}
		colors[i].insert(c);
	}
	dfs(start);
	for(int i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//cin >> t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}
