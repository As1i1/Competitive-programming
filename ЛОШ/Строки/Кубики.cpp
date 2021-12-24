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
	int n, m;
	cin >> n >> m;
	m++;
	vector<int> a1(n), a2(n), h1(n + 1), h2(n + 1), p(n);
	for (int i = 0; i < n; ++i) {
		cin >> a1[i];
		a2[n - i - 1] = a1[i];
	}
	p[0] = 1;
	for (int i = 1; i < n; ++i) {
		p[i] = p[i - 1] * 1ll * m % MOD;
	}
	h1[0] = h2[0] = 0;
	for (int i = 0; i < n; ++i) {
		h1[i + 1] = (h1[i] + (a1[i] * 1ll * p[i] % MOD)) % MOD;
		h2[i + 1] = (h2[i] + (a2[i] * 1ll * p[i] % MOD)) % MOD;
	}
	vector<int> ans;
	for (int i = n / 2; i > 0; --i) {
		int has1 = h1[i], has2 = (h2[n - i] - h2[n - 2 * i] + MOD) % MOD;
		int r1 = i, r2 = n - i;
		if ((r1 < r2 && has1 * 1ll * p[r2 - r1] % MOD == has2) || (r2 < r1 && has1 == has2 * 1ll * p[r1 - r2] % MOD) || (r1 == r2 && h1 == h2)) {
			ans.push_back(n - i);
		}
	}
	for (auto elem : ans) {
		cout << elem << " ";
	}
	cout << n;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//	cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
