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

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;


struct Node {
	int nxt[126] = { 0 };
	bool terminal = false;
	int suflink, parent;
	vector<int> rev_suflinks;
};

int pos = 1;
vector<Node> bor;
vector<int> used;

void add_string(string s) {
	int cur = 0;
	for (char c : s) {
		c -= 32;
		if (bor[cur].nxt[c]) {
			cur = bor[cur].nxt[c];
		}
		else {
			bor.push_back(Node{});
			bor[cur].nxt[c] = pos++;
			bor[pos - 1].parent = cur;
			cur = pos - 1;
		}
	}
	bor[cur].terminal = true;
}


void build_korasik() {
	int cur = 0;
	queue<int> q;
	bor[cur].suflink = -1;
	for (int i = 0; i < 126; ++i) {
		if (bor[cur].nxt[i]) {
			bor[bor[cur].nxt[i]].suflink = 0;
			bor[0].rev_suflinks.push_back(bor[cur].nxt[i]);
			q.push(bor[cur].nxt[i]);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 126; ++i) {
			if (bor[cur].nxt[i]) {
				int	p = bor[cur].suflink;
				while (p != -1 && bor[p].nxt[i] == 0) {
					p = bor[p].suflink;
				}
				if (p == -1) {
					bor[bor[cur].nxt[i]].suflink = 0;
					bor[0].rev_suflinks.push_back(bor[cur].nxt[i]);
				}
				else {
					bor[bor[cur].nxt[i]].suflink = bor[p].nxt[i];
					bor[bor[p].nxt[i]].rev_suflinks.push_back(bor[cur].nxt[i]);
				}
				q.push(bor[cur].nxt[i]);
			}
		}
	}
}


void check(string s) {
	int cur = 0;
	for (char c : s) {
		c -= 'a';
		if (bor[cur].nxt[c]) {
			cur = bor[cur].nxt[c];
		}
		else if (cur != 0) {
			while (cur != -1 && bor[cur].nxt[c] == 0) {
				cur = bor[cur].suflink;
			}
			if (cur == -1) {
				cur = 0;
			}
			else {
				cur = bor[cur].nxt[c];
			}
		}
		used[cur] += 1;
	}
}


void used_vertex() {
	for (int i = 0; i < bor.size(); ++i) {
		if (used[i]) {
			int u = i;
			while (bor[u].suflink != -1 && !used[bor[u].suflink]) {
				used[bor[u].suflink] = true;
				u = bor[i].suflink;
			}
		}
	}
}


void dfs(int v) {
	for (auto u : bor[v].rev_suflinks) {
		dfs(u);
		used[v] += used[u];
	}
}


void solve() {
	int n, m;
	cin >> n;
	bor.resize(n);
	bor[0].parent = -1;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int v;
			char c;
			cin >> v;
			cin >> c;
			v--;
			bor[i].nxt[c - 'a'] = v;
		}
	}
	build_korasik();
	cin >> m;
	used.assign(bor.size(), 0);
	string s = "";
	while (m--) {
		string s;
		cin >> s;
		check(s);
	}
	dfs(0);
	cout << used[0];
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//	cin >> t;
	t = 1;
	while (t--) {
		cout << fixed;
		cout.precision(15);
		solve();
	}
	return 0;
}
