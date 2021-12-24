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


set<int> fact(int n){
	int i = 2;
	set<int> ans = {1, n};
	while(i * i <= n){
		if (n % i == 0){
			ans.insert(i);
			ans.insert(n / i);
		}
		i += 1;
	}
	return ans;
}


int gcd(int a, int b){
	if (b == 0) return a;
	else return gcd(b, a % b);
}


void solve(){
	int n, ans = 0;
	cin >> n;
	set<int> dels = fact(n);
	set<pair<int, int>> used;
	for(auto a: dels){
		for(auto b: dels){
			if (a > b || a * b > n || gcd(a, b) != 1 || used.find({a, b}) != used.end() || used.find({b, a}) != used.end() || (a == b && a == 1)){
				continue;
			}
//			cout << a << "  " << b << "\n";
			used.insert({a, b});
			used.insert({b, a});
			ans++;
		}
	}
	cout << ans;
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
