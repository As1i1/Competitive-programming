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


bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}


void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int k1 = 0, ans = 0;
	vector<pair<int, int>> ans_t;
	while (k1 < n - 1) {
		if (a[k1].first == 0) {
			k1++;
		}
		else if (a[k1].first == 1) {
			a[k1].first--;
			a[k1 + 1].first--;
			ans_t.push_back({ a[k1].second + 1, a[k1 + 1].second + 1 });
			k1++;
			ans++;
		}
		else {
			if ((n - k1) % 2 == 0) {
				for (int i = k1; i < n; i += 2) {
					while (a[k1].first && a[k1 + 1].first) {
						a[k1].first--;
						a[k1 + 1].first--;
						ans++;
						ans_t.push_back({ a[k1].second + 1, a[k1 + 1].second + 1 });
					}
				}
			}
			else {
				a[k1].first -= 2;
				a[k1 + 1].first -= 2;
				a[k1 + 2].first -= 2;
				ans_t.push_back({ a[k1].second + 1, a[k1 + 1].second + 1 });
				ans_t.push_back({ a[k1 + 2].second + 1, a[k1 + 1].second + 1 });
				ans_t.push_back({ a[k1].second + 1, a[k1 + 2].second + 1 });
				ans += 3;
				for (int i = k1 + 3; i < n; i += 2) {
					while (a[k1].first && a[k1 + 1].first) {
						a[k1].first -= 2;
						a[k1 + 1].first -= 2;
						ans += 2;
						ans_t.push_back({ a[k1].second + 1, a[k1 + 1].second + 1 });
						ans_t.push_back({ a[k1].second + 1, a[k1 + 1].second + 1 });
					}
				}
			}
		}
	}
	cout << ans << "\n";
	for (int i = 0; i < ans; ++i) {
		cout << ans_t[i].first << " " << ans_t[i].second << "\n";
	}
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
