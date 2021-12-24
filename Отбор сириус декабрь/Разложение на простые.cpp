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


map<int, int> fact(int n){
	int i = 2;
	map<int, int> ans;
	while(i * i <= n){
		while(n % i == 0){
			ans[i]++;
			n /= i;
		}
		i += 1;
	}
	if (n != 1){
		ans[n]++;
	}
	return ans;
}


void solve(){
	int n;
	cin >> n;
	map<int, int> ans = fact(n);
	bool flag = false;
	for(auto p: ans){
		if (!flag){
			if (p.second == 1){
				cout << p.first;
			}
			else cout << p.first << "^" << p.second;
			flag = true;
		}
		else{
			if (p.second == 1){
				cout << "*" << p.first;
			}
			else cout << "*" << p.first << "^" << p.second;
			flag = true;
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
