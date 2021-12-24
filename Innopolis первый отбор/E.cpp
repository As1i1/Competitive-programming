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


void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int j = 0; j < n; ++j) cin >> b[j];
	vector<pair<int, int>> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i].first >> c[i].second;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < (1 << n); ++i) {
		vector<int> tmp_a, tmp_b;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				tmp_a.push_back(c[j].first);
				tmp_b.push_back(c[j].second);
			}
			else {
				tmp_b.push_back(c[j].first);
				tmp_a.push_back(c[j].second);
			}
		}
		sort(tmp_a.begin(), tmp_a.end());
		sort(tmp_b.begin(), tmp_b.end());
		if (a == tmp_a && b == tmp_b) {
			cout << "YES\n";
			for (int j = 0; j < n; ++j) {
				if (i & (1 << j)) {
					cout << c[j].first << " " << c[j].second << "\n";
				}
				else {
					cout << c[j].second << " " << c[j].first << "\n";
				}
			}
			return;
		}
	}
	cout << "NO";
}


signed main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 1;
	//	gen.seed(time(0));
	//	cout << fixed;
	//	cout.precision(15);
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
