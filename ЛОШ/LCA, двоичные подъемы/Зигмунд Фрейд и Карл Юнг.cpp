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

vector<vector<int>> up;
vector<int> d, nearst_live;
vector<bool> alive;


int jump(int u, int h) {
	for (int k = 19; k > -1; k--) {
		if ((1 << k) <= h) {
			u = up[u][k];
			h -= (1 << k);
		}
	}
	return u;
}

int up_to_live(int u) {
	if (alive[nearst_live[u]]) {
		return nearst_live[u];
	}
	nearst_live[u] = up_to_live(up[u][0]);
	return nearst_live[u];
}

int LCA(int u, int v) {
	if (u == v) {
		return u;
	}
	for (int k = 19; k > -1; k--) {
		if (up[u][k] != up[v][k]) {
			u = up[u][k];
			v = up[v][k];
		}
	}
	return up[u][0];
}



void solve() {
	int n = 2, m, k = 20;
	alive.resize(n, true);
	d.resize(n);
	nearst_live.resize(n);
	nearst_live[0] = 0;
	nearst_live[1] = 1;
	up.resize(n, vector<int>(20, 0));
	up[0][0] = 0;
	up[1][0] = 0;
	d[0] = d[1] = 0;
	for (int i = 0; i < k - 1; ++i) {
		for (int u = 0; u < n; ++u) {
			up[u][i + 1] = up[up[u][i]][i];
		}
	}
	cin >> m;
	while (m--) {
		char c;
		cin >> c;
		if (c == '+') {
			int v;
			cin >> v;
			alive.push_back(true);
			nearst_live.push_back(n);
			d.push_back(d[v] + 1);
			up.push_back(vector<int>(20, 0));
			up[n][0] = v;
			for (int i = 0; i < k - 1; ++i) {
				up[n][i + 1] = up[up[n][i]][i];
			}
			n++;
		}
		else if (c == '-') {
			int v;
			cin >> v;
			alive[v] = false;
		}
		else {
			int u, v;
			cin >> u >> v;
			if (d[v] < d[u]) {
				swap(v, u);
			}
			v = jump(v, d[v] - d[u]);
			cout << up_to_live(LCA(v, u)) << "\n";
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//	cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
