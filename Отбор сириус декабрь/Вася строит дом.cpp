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
	ll a, b, d;
	cin >> a >> b >> d;
	ll dist = abs(a - b);
	if (dist % 2 == 0){
		ll m = min(a, b) + dist / 2;
		cout << m << " " << min(abs(m) % d, d - abs(m) % d);
	}
	else if (min(a, b) + 1 == max(a, b)){
		ll m1 = min(a, b) - 1, m2 = max(a, b) + 1;
		if (min(m1 % d, d - m1 % d) < min(m2 % d, d - m2 % d)){
			cout << m1 << " " << min(m1 % d, d - m1 % d);
		}
		else{
			cout << m2 << " " << min(m2 % d, d - m2 % d);
		}
	}
	else{
		ll m = min(a, b) + dist / 2;
		if (min(abs(m) % d, d - abs(m) % d) < min(abs(m + 1) % d, d - abs(m + 1) % d)){
			cout << m << " " << min(abs(m) % d, d - abs(m) % d);
		}
		else{
			cout << m + 1 << " " << min(abs(m + 1) % d, d - abs(m + 1) % d);
		}
		
	}
	cout << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 5;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
