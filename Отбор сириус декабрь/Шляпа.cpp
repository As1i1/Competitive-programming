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


void solve(){
	int n, m;
	cin >> n >> m;
	map<string, int> mp;
	vector<int> points(n);
	for(int i = 0; i < m; ++i){
		int team;
		string word;
		cin >> team >> word;
		mp[word] = team - 1;
	}
	for(auto elem: mp){
		points[elem.second]++;
	}
	for(int i = 0; i < n; ++i){
		cout << points[i] << " ";
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
