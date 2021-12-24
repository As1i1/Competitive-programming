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


ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


bool check(vector<ll> a) {
	for (int i = 1; i < a.size(); ++i) {
		if (a[i] - a[0] != i) return false;
	}
	return true;
}


void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> matrix(n, vector<ll>(m, 0));
	vector<ll> g_row(n), g_col(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
			if (i == 0) {
				g_col[j] = matrix[i][j];
			}
			if (j == 0) {
				g_row[i] = matrix[i][j];
			}
		}
	}
	if (n == 1 && m == 1) {
		cout << "true";
		return;
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			g_col[i] = gcd(g_col[i], matrix[j][i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			g_row[i] = gcd(g_row[i], matrix[i][j]);
		}
	}
	if (check(g_row) && check(g_col)) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (((g_row[i] % MOD) * g_col[j] % MOD) % MOD != matrix[i][j] % MOD) {
					cout << "false";
					return;
				}
			}
		}
		cout << "true";
	}
	else {
		cout << "false";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//	cin >> t;
	t = 1;
	while (t--) {

		solve();
	}
	return 0;
}
