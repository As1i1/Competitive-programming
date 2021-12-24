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
vector<set<pair<int, int>>> g;
vector<int> ans;


void euler(int v) {
	while (!g[v].empty()) {
		auto p = *g[v].begin();
		int u = p.first;
		g[v].erase(g[v].begin());
		g[u].erase({ v, p.second });
		euler(u);
	}
	ans.push_back(v);
}



void solve() {
	set<pair<int, int>> s1;
	s1.erase({ -1, -1 });
	int n, m, p;
	cin >> n >> m >> p;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].insert({ v, i });
		g[v].insert({ u, i });
	}
	int cnt = 0, s = -1;
	vector<vector<int>> ans1;
	for (int i = 0; i < n; ++i) {
		bool flag = false;
		int u = -1;
		for (auto edge : g[i]) {
			if (edge.first != i) {
				flag = true;
				u = edge.first;
			}
		}
		if (flag) {
			set<pair<int, int>> s;
			for (auto edge : g[i]) {
				if (edge.first == i) {
					ans1.push_back({ i, i, u });
					m--;
				}
				else {
					s.insert(edge);
				}
			}
			g[i] = s;
		}
		if (g[i].size() % 2 == 1) {
			cnt++;
			s = i;
		}
		if (g[i].size() != 0 && s == -1) {
			s = i;
		}
	}
	if (cnt > 2) {
		cout << "NO";
		return;
	}
	euler(s);
	reverse(ans.begin(), ans.end());
	if (ans.size() != m + 1) {
		cout << "NO";
		return;
	}
	cout << "YES\n";
	if (p == 0) {
		return;
	}
	for (int i = 0; i < ans1.size(); ++i) {
		cout << ans1[i][0] + 1 << " " << ans1[i][1] + 1 << " " << ans1[i][2] + 1 << "\n";
	}
	for (int i = 0; i < ans.size() - 2; ++i) {
		cout << ans[0] + 1 << " " << ans[i + 1] + 1 << " " << ans[i + 2] + 1 << "\n";
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
