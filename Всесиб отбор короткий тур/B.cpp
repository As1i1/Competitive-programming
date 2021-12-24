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


struct Point {
	ld x, y;
	Point(ld x1, ld y1) {
		x = x1;
		y = y1;
	}
};


vector<Point> dorf;
vector<bool> used;
map<pair<int, int>, int> ways;


ld get_dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}


pair<int, ld> get_way(int x, int r, int xx, int t) {
	ld way = 0;
	int cnt = xx;
	for (int i = max(0, x - r); i < min(int(dorf.size()) - 1, x + r); ++i) {
		if (ways[{i, i + 1}] != 0) {
			way += get_dist(dorf[i], dorf[i + 1]);
			cnt -= (t - ways[{i, i + 1}]);
		}
	}
	return { cnt, way };
}


void solve() {
	int k, n, r, t;
	ld ans = 0;
	cin >> k >> n >> r >> t;
	dorf.push_back(Point{ 0, 0});
	used.assign(n + 2, false);
	for (int i = 0; i < n; ++i) {
		ld x;
		cin >> x;
		dorf.push_back(Point{ ld(i + 1), x });
	}
	for (int i = 0; i < n + 1; ++i) {
		ways[{i, i + 1}] = t;
	}
	dorf.push_back(Point{ ld(n + 1), 0 });
	for (int i = 0; i < k; ++i) {
		ld max_way = -1;
		int x = -1, min_cnt = INF;
		for (int j = 0; j < n + 2; ++j) {
			if (used[j]) continue;
			pair<int, ld> tmp = get_way(j, r, 2 * r + 1, t);
			ld cur_way = tmp.second;
			int cnt = tmp.first;
			if (cnt < min_cnt) {
				min_cnt = cnt;
				x = j;
				max_way = cur_way;
			}
			else if (cnt == min_cnt && cur_way > max_way) {
				max_way = cur_way;
				x = j;
			}
		}
		if (x == -1) continue;
		for (int j = max(0, x - r); j < min(int(dorf.size() - 1), x + r); ++j) {
			ways[{j, j + 1}] = max(0, ways[{j, j + 1}] - 1);
		}
		used[x] = true;
	}
	for (auto p : ways) {
		if (p.second == 0) {
			ans += sqrt(get_dist(dorf[p.first.first], dorf[p.first.second]));
		}
	}
	cout << ans;
}


signed main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t = 1;
	//	gen.seed(time(0));
		cout << fixed;
		cout.precision(15);
	//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
