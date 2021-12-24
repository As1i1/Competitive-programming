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


bool ckeck(set<int> s, int k, int x){
	for(auto elem: s){
		if ((elem - x) % k != 0){
			return false;
		}
	}
	return true;
}


void solve(){
	int n;
	cin >> n;
	set<int> s;
	for(int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	if (s.size() == 1) cout << -1;
	else{
		int x = *s.begin();
		s.erase(s.begin());
		int y = *s.begin();
		int ans = 1;
		for(int i = 2; i < y - x; ++i){
			if (check(s, i, x)){
				ans = i;
			}
		}
		cout << ans;
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
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
