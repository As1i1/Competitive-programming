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
vector<vector<vector<int>>> dp;
vector<int> d = { 2, 3, 5 };
int n = 100, m = 300, cnt = 0;



int calc(int i, int j, int t) {
	int d1 = -1, d2 = -1;
	cnt++;

	if (i + d[t] >= n) {
		d1 = 1;
	}
	else if (dp[i + d[t]][j][(t + 1) % 3] != -1) {
		d1 = dp[i + d[t]][j][(t + 1) % 3];
	}
	else {
		d1 = calc(i + d[t], j, (t + 1) % 3);
	}


	if (j + d[t] >= m) {
		d2 = 1;
	}
	else if (dp[i][j + d[t]][(t + 1) % 3] != -1) {
		d2 = dp[i][j + d[t]][(t + 1) % 3];
	}
	else {
		d2 = calc(i, d[t] + j, (t + 1) % 3);
	}


	if (d1 == 1 && d2 == 1) {
		dp[i][j][t] = 0;
		return 0;
	}
	else {
		dp[i][j][t] = 1;
		return 1;
	}
}



void solve() {
//	cin >> n >> m;
	dp.assign(n, vector<vector<int>>(m, vector<int>(3, -1)));
	calc(0, 0, 0);
	if (dp[0][0][0] == 1) {
//		cout << "Alice\n";
	}
	else {
//		cout << "Bob\n";
	}
}



signed main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 10000;
	//	gen.seed(time(0));
	//	cout << fixed;
	//	cout.precision(15);
	//cin >> t;
	while (t--) {
		solve();
	}
	cout << cnt;
	return 0;
}
