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
// . - 0, X - 1, S - 2
vector<vector<int>> g, d, field, comp;
vector<pair<int, int>> d_coord = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
vector<bool> used;
vector<pair<int, int>> comp_start;
int n, m, clr = 0;


void bfs(int i, int j, int color) {
	queue<int> qx, qy;
	qx.push(i);
	qy.push(j);
	d[i][j] = 0;
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front();
		qx.pop();
		qy.pop();
		for (auto tmp : d_coord) {
			int new_x = tmp.first + x, new_y = tmp.second + y;
			if (new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && d[x][y] + 1 < d[new_x][new_y]) {
				if (field[new_x][new_y] == 1 && comp[new_x][new_y] == color && d[new_x][new_y] != 0) {
					qx.push(new_x);
					qy.push(new_y);
					d[new_x][new_y] = 0;
				}
				else if (field[new_x][new_y] == 1) {
					d[new_x][new_y] = d[x][y];
					g[color][comp[new_x][new_y]] = min(g[color][comp[new_x][new_y]], d[new_x][new_y]);
					g[comp[new_x][new_y]][color] = g[color][comp[new_x][new_y]];
					qx.push(new_x);
					qy.push(new_y);
				}
				else if (field[new_x][new_y] == 2) {
					d[new_x][new_y] = d[x][y] + 1;
					qx.push(new_x);
					qy.push(new_y);
				}
			}
		}
	}
}


void bfs_comp(int i, int j, int color) {
	queue<int> qx, qy;
	qx.push(i);
	qy.push(j);
	comp[i][j] = color;
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front();
		qx.pop();
		qy.pop();
		for (auto tmp : d_coord) {
			int new_x = x + tmp.first, new_y = y + tmp.second;
			if (new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && field[new_x][new_y] == 1 && comp[new_x][new_y] == -1) {
				qx.push(new_x);
				qy.push(new_y);
				comp[new_x][new_y] = color;
			}
		}
	}
}


int dfs(int v, int cnt, int way, int cur_ans) {
	int ans = INF;
	if (cnt == clr) {
		return way;
	}
	if (way > cur_ans) {
		return cur_ans;
	}
	used[v] = true;
	for (int u = 0; u < clr; ++u) {
		if (!used[u] && g[v][u] != INF) {
			ans = min(ans, dfs(u, cnt + 1, way + g[v][u], ans));
		}
	}
	used[v] = false;
	return ans;
}


void solve() {
	cin >> n >> m;
	field.resize(n);
	d.assign(n, vector<int>(m, INF));
	comp.resize(n);
	for (int i = 0; i < n; ++i) {
		field[i].resize(m);
		comp[i].resize(m, -1);
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == '.') {
				field[i][j] = 0;
			}
			else if (c == 'X') {
				field[i][j] = 1;
			}
			else if (c == 'S') {
				field[i][j] = 2;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (field[i][j] == 1 && comp[i][j] == -1) {
				bfs_comp(i, j, clr);
				comp_start.push_back({ i, j });
				clr++;
			}
		}
	}
	g.assign(clr, vector<int>(clr, INF));
	used.assign(clr, false);
	for (int i = 0; i < clr; ++i) {
		bfs(comp_start[i].first, comp_start[i].second, i);
		d.assign(n, vector<int>(m, INF));
	}
	//	for (int i = 0; i < clr; ++i) {
	//		for (int j = 0; j < clr; ++j) {
	//			cout << g[i][j] << "\t";
	//		}
	//		cout << "\n";
	//	}
	cout << dfs(0, 1, 0, INF);
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

