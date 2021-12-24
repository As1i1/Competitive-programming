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
	int a, b;
	cin >> a >> b;
	vector<int> primes;
	vector<bool> numbers(b + 1, false);
	for(int i = 2; i < b + 1; ++i){
		if(!numbers[i]){
			primes.push_back(i);
			for(int j = 2 * i; j < b + 1; j += i){
				numbers[j] = true;
			}
		}
	}
	set<int> ans;
	for(auto x: primes){
		for(auto y: primes){
			if (x + y >= a && x + y <= b){
				ans.insert(x + y);
			}
		}
	}
	for(auto elem: ans){
		cout << elem << "\n";
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
