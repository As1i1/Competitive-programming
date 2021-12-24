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


ll gcd(ll a, ll b){
	if (b == 0) return a;
	else return gcd(b, a % b);
}


void solve(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	c -= a;
	d -= b;
	c = abs(c);
	d = abs(d);
	if (c == 0 || d == 0){
		cout << 0;
	}
	else if (abs(c) == abs(d)){
		cout << c;
	}
	else{
		ll g = gcd(c, d), k = c / g + d / g - 1;
		cout << k * g;
		
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
