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


ll gcd_ext(ll a, ll b, ll& x, ll& y){
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll d = gcd_ext(b, a % b, x, y);
	x -= (a / b) * y;
	swap(x, y);
	return d;
}



void solve(){
	ll a, b, c, x, y;
	cin >> a >> b >> c;
	ll d = gcd_ext(a, b, x, y);
	if (c % d != 0){
		cout << "-1";
	}
	else{
		ll mn_x = INF, mn_y = INF;
//		cout << d << " " << x << " " << y << "\n";
		c /= d;
		b /= d;
		a /= d;
		x *= c;
		y *= c;
//		cout << x << " " << y << " " << a << " " << b << " " << c << "\n";
	 	ll t = -(x / b);
	 	if (x < 0 && abs(x) % b != 0){
	 		t++;
		 }
//		cout << x << " " << y  << " " << t << "\n";
		for(int i = 0; i < 20; ++i){
			x = x + t * b;
			y = y - t * a;
//			cout << x << " " << y << "\n";
			if (x >= 0 && x < mn_x){
				mn_x = x;
				mn_y = y;
				break;
			}
		}
		cout << mn_x << " " << mn_y;
		
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
