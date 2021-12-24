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
	set<int> s1, s2;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		s1.insert(x);
	}
	cin >> m;
	for(int i = 0; i < m; ++i){
		int x;
		cin >> x;
		s2.insert(x);
	}
	set<int> ans, ans_2;
	for(auto elem: s1){
		if (s2.find(elem) != s2.end()){
			ans.insert(elem);
		}
	}
	for(auto elem: s1){
		if (ans.find(elem) == ans.end()){
			ans_2.insert(elem);
		}
	}
	for(auto elem: s2){
		if (ans.find(elem) == ans.end()){
			ans_2.insert(elem);
		}
	}
	cout << ans_2.size() << "\n";
	for(auto elem: ans_2){
		cout << elem << " ";
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
