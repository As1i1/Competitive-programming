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
vector<set<int>> g;
map<pair<int, int>, bool> mp;


vector<int> fact(int n) {
	int i = 2;
	vector<int> ans = { 1, n };
	while (i * i <= n) {
		if (n % i == 0) {
			ans.push_back(i);
			ans.push_back(n / i);
		}
		i++;
	}
	return ans;
}


bool is_prime(int n) {
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			return false;
		}
		i++;
	}
	return true;
}


void build(vector<int> tmp) {
	for (int i = 0; i < tmp.size(); ++i) {
		for (int j = 0; j < tmp.size(); ++j) {
			if (i == j) continue;
			if (!mp[{max(tmp[i], tmp[j]), min(tmp[i], tmp[j])}]) {
				g[i].insert(j);
				g[j].insert(i);
			}
		}
	}
}





void solve() {
	int n;
	cin >> n;
	vector<int> a = fact(n);
	int m = a.size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == j) continue;
			if (max(a[i], a[j]) % min(a[i], a[j]) != 0) mp[{max(a[i], a[j]), min(a[i], a[j])}] = false;
			else mp[{max(a[i], a[j]), min(a[i], a[j])}] = is_prime(max(a[i], a[j]) / min(a[i], a[j]));
		}
	}
	vector<int> ans = { 1 };
	for (int i = 1; i < (1 << m); ++i) {
		vector<int> tmp;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				tmp.push_back(a[j]);
			}
		}
//		g.clear();
		int k = tmp.size();
//		g.resize(k);
//		build(tmp);
		vector<int> tmp_c = tmp;

		while (next_permutation(tmp.begin(), tmp.end())) {
			bool flag = true;
			for (int i = 0; i < k; ++i) {
				if (!mp[{max(tmp[i], tmp[(i + 1) % k]), min(tmp[i], tmp[(i + 1) % k])}]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				if (ans.size() < tmp.size()) {
					ans = tmp;
				}
			}
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
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
	//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
