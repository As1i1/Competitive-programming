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
map<ll, ll> fact_a;
vector<ll> prime;


ll find_ans(map<ll, ll> mp, ll n) {
	bool flag = false;
	for (auto p : mp) {
		if (p.second * n < fact_a[p.first]) {
			flag = true;
			break;
		}
	}
	if (flag) {
		ll ans = ll_INF;
		for (auto p: prime) {
			if (mp[p] != 0){
				mp[p]++;
				ans = min(ans, find_ans(mp, n * p));
				mp[p]--;
			}
			else{
				ans = min(ans, find_ans(mp, n * p));
			}
		}
		return ans;
	}
	else {
		return n;
	}
}


void fact(ll n) {
	ll i = 2;
	while (i * i <= n) {
		while (n % i == 0) {
			n /= i;
			fact_a[i]++;
		}
		i += 1;
	}
	if (n != 1) {
		fact_a[n]++;
	}
}


void solve() {
	vector<bool> tmp(1e4 + 1, false);
	for(int i = 2; i < 1e4; ++i){
		if (!tmp[i]){
			prime.push_back(i);
			for(int j = 2 * i; j < 1e4; j += i){
				tmp[j] = true;
			}
		}
	}
//	cout << prime.size() << " ";
	ll a;
	cin >> a;
	fact(a);
	ll n = 1;
	map<ll, ll> mp;
	for (auto p : fact_a) {
		n *= p.first;
		mp[p.first] = 1;
	}
	cout <<  find_ans(mp, n);
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
	while (t--) {
		solve();
	}
	return 0;
}
