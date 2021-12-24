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


ll binpow(ll a, ll n, ll p) {
	if (n == 1) return a % p;
	if (n == 0) return 1;
	ll d = binpow(a, n / 2, p);
	if (n % 2 == 1) return (((d * d) % p) * a) % p;
	else return (d * d) % p;
}



void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
	}
	ll ans = (binpow(2, n - 1, MOD) * n) % MOD;
	vector<vector<ll>> C(n + 1, vector<ll>(n + 1, 0));
	for (int i = 0; i <= n; ++i){
		C[i][0] = 1;
		C[i][i] = 1;
		for (int j = 1; j < i; ++j){ 
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	n--;
	for (int i = 0; i <= n ; ++i) {
		ans = (ans + (((n * C[n][i]) % MOD) + (((i * (n - i)) % MOD) * C[n][i]) % MOD) % MOD) % MOD;
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
	//  cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
