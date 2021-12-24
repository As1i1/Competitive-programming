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

const int INF = 1e9;
const ll ll_INF = 1e18;


void solve() {
	int k, n, m;
	cin >> k >> n >> m;
	vector<int> ans(n + m), a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	int k1 = 0, k2 = 0, k3 = 0;
	while (k3 < n + m) {
		if (k1 < n && a[k1] == 0) {
			ans[k3] = 0;
			k1++;
			k++;
		}
		else if (k2 < m && b[k2] == 0) {
			ans[k3] = 0;
			k2++;
			k++;
		}
		else {
			if (k1 < n && a[k1] <= k) {
				ans[k3] = a[k1];
				k1++;
			}
			else if (k2 < m && b[k2] <= k) {
				ans[k3] = b[k2];
				k2++;
			}
			else {
				k3 = -1;
				break;
			}
		}
		k3++;
	}
	if (k3 == -1) {
		cout << "-1\n";
	}
	else {
		for (int i = 0; i < n + m; ++i) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
