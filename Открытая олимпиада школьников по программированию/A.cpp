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


void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), cur(2 * 1e5 + 1, INF), order(2 * 1e5 + 1, -1);
	vector<queue<int>> q(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		order[b[i]] = i;
	}
	vector<int> ans(n);
	for (int i = n - 1; i >= 0; --i) {
		if (order[a[i]] == 0) {
			cur[a[i]] = i;
			int j = 1; 
			bool flag = true;
			while (j < m && flag) {
				flag = false;
				while (!q[j].empty() && q[j].front() > cur[b[j - 1]]) {
					cur[b[j]] = q[j].front();
					q[j].pop();
					flag = true;
				}
				j++;
			}
		}
		else if (order[a[i]] != -1) {
			q[order[a[i]]].push(i);
			int j = order[a[i]];
			bool flag = true;
			while (j < m && flag) {
				flag = false;
				while (!q[j].empty() && q[j].front() > cur[b[j - 1]]) {
					cur[b[j]] = q[j].front();
					q[j].pop();
					flag = true;
				}
				j++;
			}
		}
		if (cur[b.back()] == INF) {
			ans[i] = -1;
		}
		else {
			ans[i] = cur[b.back()] + 1;
		}

	}
	for (int i = 0; i < n; ++i) cout << ans[i] << " ";
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
	while (t--) {
		solve();
	}
	return 0;
}
