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
#include <bitset>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


int first_del(int n) {
	int i = 2; 
	while (i * i <= n) {
		if (n % i == 0) {
			return i;
		}
		i++;
	}
	return n;
}


int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}



void solve() {
	int n;
	cin >> n;
	if (n % 2 == 0) cout << n / 2 << " " << n / 2 - 1 << " " << 1;
	else {
		int p = n / 2;
		if (p % 2 == 0) {
			cout << p + 1 << " " << p - 1 << " " << 1;
		}
		else {
			cout << p + 2 << " " << p - 2 << " " << 1;
		}
	}
	cout << "\n";
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
	while (t--) {
		solve();
	}
	return 0;
}
