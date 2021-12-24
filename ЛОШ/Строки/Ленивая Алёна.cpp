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
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ll ll_INF = 1e18;


void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<ll> p(n), hash(n + 1);
	p[0] = 1;
	hash[0] = 0;
	for (int i = 1; i < n; ++i) {
		p[i] = p[i - 1] * Q % MOD;
	}
	for (int i = 1; i <= n; ++i) {
		hash[i] = (hash[i - 1] + (s[i - 1] - 'a' + 1) * p[i - 1] % MOD) % MOD;
	}
	int m;
	cin >> m;
	while (m--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		ll h1 = (hash[r1 + 1] - hash[l1] + MOD) % MOD, h2 = (hash[r2 + 1] - hash[l2] + MOD) % MOD;
		h1 = h1 * p[l2] % MOD;
		h2 = h2 * p[l1] % MOD;
		if (h1 == h2) {
			cout << "0\n";
		}
		else if (h1 > h2) {
			cout << "1\n";
		}
		else{
			cout << "-1\n";
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
