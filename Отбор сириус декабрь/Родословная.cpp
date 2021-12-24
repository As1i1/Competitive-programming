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
vector<int> d;


bool comp(pair<int, string> a, pair<int, string> b){
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}


void dfs(int v, int depth=0){
	d[v] = depth;
	for(auto u: g[v]){
		dfs(u, depth + 1);
	}
}


void solve(){
	int n;
	cin >> n;
	map<string, int> p;
	int cnt = 0;
	g.resize(n);
	d.resize(n, 0);
	string r = "";
	for(int i = 0; i < n - 1; ++i){
		string name1, name2;
		cin >> name1 >> name2;
		if (r == ""){
			r = name2;
		}
		if (p.find(p.begin(), p.end(), name1) == p.end()){
			p[name1] = cnt;
			cnt++;
		}
		if (p.find(p.begin(), p.end(), name2) == p.end()){
			p[name2] = cnt;
			cnt++;
		}
		g[p[name2]].push_back(p[name1]);
	}	
	dfs(p[r]);
	vector<pair<string, int>> ans(n);
	for(int i = 0; i < n; ++i){
		ans[i] = {p[i], d[i]};
	}	
	sort(ans.begin(), ans.end(), comp);
	for(auto p: ans){
		cout << p.first << " " << p.second << "\n";
	}
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
	while(t--){
		solve();
	}
	return 0;
}
