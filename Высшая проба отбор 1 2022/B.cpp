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
	int n, m, start, finish;
	cin >> n >> m >> start >> finish;
	start--; finish--;
	vector<vector<pair<int, ll>>> g(n);
	for (int i = 0; i < m; ++i) {
		int v, u, c;
		cin >> v >> u >> c;
		v--; u--;
		g[v].push_back({ u, c });
		g[u].push_back({ v, c });
	}
	vector<pair<ll, int>> d(n, { ll_INF, 0 });
	vector<int> par(n, -1);
	set<pair<ll, int>> s;
	d[start] = { 0, 0 };
	par[start] = start;
	s.insert({ d[start].first, start });
	while (!s.empty()) {
		pair<ll, int> tmp = *s.begin();
		s.erase(s.begin());
		int v = tmp.second;
		ll len = tmp.first;
		for (auto p : g[v]) {
			int u = p.first;
			ll len_u = p.second;
			if (d[u].first > len_u + len) {
				d[u].first = len_u + len;
				d[u].second = d[v].second + 1;
				s.insert({ d[u].first, u });
				par[u] = v;
			}
			else if (d[u].first == len_u + len && d[u].second < d[v].second + 1) {
				d[u].second = d[v].second + 1;
				s.insert({ d[u].first, u });
				par[u] = v;
			}
		}
	}
	cout << d[finish].first << "\n" << d[finish].second - 1 << "\n";
	finish = par[finish];
	vector<int> way;
	while (par[finish] != finish) {
		way.push_back(finish);
		finish = par[finish];
	}
	for (int i = way.size() - 1; i > -1; i--) {
		cout << way[i] + 1 << " ";
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
	//  cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
