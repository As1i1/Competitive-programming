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
int n, m;


set<vector<int>> get_elem(int i, int j, int k){
	if (k == 1){
		return {{g[i][j], i, j}};
	}
	set<vector<int>> ans;
	if (i + 1 < n){
		set<vector<int>> tmp = get_elem(i + 1, j, k - 1);
		for(auto elem: tmp){
			ans.insert(elem);
		}
	}
	if (i - 1 > -1){
		set<vector<int>> tmp = get_elem(i - 1, j, k - 1);
		for(auto elem: tmp){
			ans.insert(elem);
		}
	}
	if (j - 1 > -1){
		set<vector<int>> tmp = get_elem(i, j - 1, k - 1);
		for(auto elem: tmp){
			ans.insert(elem);
		}
	}
	if (j + 1 < m){
		set<vector<int>> tmp = get_elem(i, j + 1, k - 1);
		for(auto elem: tmp){
			ans.insert(elem);
		}
	}
	return ans;
}



ll get(int i, int j, int k){
	set<vector<int>> 
}



void solve(){
	int  k;
	cin >> n >> m >> k;
	g.resize(n);
	for(int i = 0; i < n; ++i){
		g[i].resize(m);
		for(int j = 0; j < m; ++j){
			cin >> g[i][j];
		}
	}
	ll ans = 0;
	int i_ans, j_ans;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			for(int t = k; k < 15; ++t){
				ll tmp = get(i, j, k);
				if (tmp > ans){
					k = t;
					ans = tmp;
					i_ans = i;
					j_ans = j;
				}
			}
		}
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
