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


ll bin_pow(ll a, ll b, ll z) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a % z;
	}
	else if (b % 2 == 1) {
		return (bin_pow(a, b - 1, z) * a) % z;
	}
	else {
		ll tmp = bin_pow(a, b / 2, z);
		return (tmp * tmp) % z;
	}
}


ll func_euler(ll n){
	ll i = 2, res = n;
	while(i * i <= n){
		if (n % i == 0){
			res -= (res / i);
			while(n % i == 0){
				n /= i;
			}
		}
		i += 1;
	}
	if (n != 1){
		res -= (res / n);
	}
	return res;
}


ll gcd(ll a, ll b){
	if (b == 0) return a;
	else return gcd(b, a % b);
}


void solve() {
	ll p, a;
	cin >> p >> a;
	if (gcd(p, a) != 1){
		cout << "-1";
	}
	else{
		cout << bin_pow(a, func_euler(p) - 1, p);
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
	while (t--) {
		solve();
	}
	return 0;
}
