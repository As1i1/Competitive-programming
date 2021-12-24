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
	set<int> ans;
	while(i * i <= n){
		while (n % i == 0){
			ans.insert(i);
			n /= i;
		}
		i += 1;
	}
	if (n != 1){
		ans.insert(i);
	}
	return ans;
}


void solve(){
	map<int, int> primes;
	vector<bool> numbers(1e4, false);
	for(int i = 2; i < 1e4; ++i){
		if (!numbers[i]){
			primes[i] = 0;
			for(int j = 2 * i; j < 1e4; j += i){
				numbers[j] = true;
			}
		}
	}
	int n;
	cin >> n;
	vector<set<int>> a_fact(n);
	for(int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;
		a_fact[i] = fact(tmp);
	}
	int ans = 1, k1 = 1;
	vector<pair<int, int>> last;
	for(auto p: a_fact[0]){
		primes[p] = 1;
		last.push_back({p, 1});
	}
	while(k1 < n){
		for (auto p: a_fact[k1]){
			primes[p]++;
		}
		for(auto p: last){
			if (primes[p.first] != p.second){
				primes[p.first] = 0;
			}
		}
		last.clear();
		for(auto p: primes){
			if (p.second != 0){
				last.push_back(p);
			}
			ans = max(ans, p.second);
		}
		k1++;
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
