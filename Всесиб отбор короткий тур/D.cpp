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

const int INF = 1e9, MOD = 1e9 + 9, Q = 41;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<vector<char>> field;
vector<vector<bool>> used;
vector<pair<int, int>> d = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<int>> bor;
vector<bool> is_terminate;
set<string> ans;
int n, m;



void dfs(int i, int j, int bor_v, string cur_s, int depth = 0) {
	if (bor[bor_v][field[i][j] - 'a'] == -1) {
		return;
	}
	used[i][j] = true;
	bor_v = bor[bor_v][field[i][j] - 'a'];
	cur_s += field[i][j];
	depth++;
	if (is_terminate[bor_v]) {
		ans.insert(cur_s);
	}
	for (auto p : d) {
		int new_x = i + p.first, new_y = j + p.second;
		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !used[new_x][new_y]) {
			dfs(new_x, new_y, bor_v, cur_s, depth);
		}
	}
	used[i][j] = false;
}



void solve() {
	cin >> n >> m;
	field.resize(n, vector<char>(m));
	used.resize(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			field[i][j] = c;
		}
	}
	bor.push_back(vector<int>(26, -1));
	is_terminate.push_back(false);
	int d;
	cin >> d;
	for (int i = 0; i < d; ++i) {
		string word;
		cin >> word;
		int v = 0;
		for (int j = 0; j < word.size(); ++j) {
			if (bor[v][word[j] - 'a'] == -1) {
				bor.push_back(vector<int>(26, -1));
				bor[v][word[j] - 'a'] = bor.size() - 1;
				v = bor.size() - 1;
				is_terminate.push_back(false);
			}
			else {
				v = bor[v][word[j] - 'a'];
			}
		}
		is_terminate[v] = true;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dfs(i, j, 0, "");
		}
	}
	cout << ans.size() << "\n";
	for (auto word : ans) {
		cout << word << "\n";
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
