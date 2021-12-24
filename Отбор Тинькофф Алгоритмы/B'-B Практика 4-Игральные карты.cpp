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


int gcd(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}


void solve() {
	int n1, m1, n2, m2;
	cin >> n1 >> m1;
	vector<vector<int>> a(n1, vector<int>(m1));
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < m1; ++j) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	cin >> n2 >> m2;
	vector<vector<int>> b(n2, vector<int>(m2));
	for (int i = 0; i < n2; ++i) {
		for (int j = 0; j < m2; ++j) {
			char c;
			cin >> c;
			b[i][j] = c - '0';
		}
	}
	int new_n = (n1 * n2) / gcd(n1, n2), new_m = (m1 * m2) / gcd(m1, m2);
	int a1 = new_n / n1, a2 = new_n / n2, b1 = new_m / m1, b2 = new_m / m2;
	ll ans = 0;
	for (int i = 0; i < new_n; ++i) {
		for (int j = 0; j < new_m; ++j) {
			if (a[i / a1][j / b1 ] == b[i / a2 ][j / b2 ]) ans++;
		}
	}
	cout << ans;
}


int main() {
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
