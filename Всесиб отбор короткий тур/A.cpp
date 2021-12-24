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


int check(map<string, int> produkt, map<string, map<string, int>> rezept) {
	int ans = 0;
	for (auto rep : rezept) {
		bool flag = true;
		for (auto comp : rep.second) {
			if (produkt[comp.first] < comp.second) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans++;
		}
	}
	return ans;
}


void solve() {
	int n;
	cin >> n;
	map<string, int> produkt;
	map<string, map<string, int>> rezept;
	for (int i = 0; i < n; ++i) {
		string name;
		int cnt;
		cin >> name >> cnt;
		produkt[name] = cnt;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string name;
		int kol;
		cin >> name >> kol;
		for (int j = 0; j < kol; ++j) {
			string name1;
			int cnt;
			cin >> name1 >> cnt;
			rezept[name][name1] = cnt;
		}
	}
	cout << check(produkt, rezept) << "\n";
	int k = 0;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		string name;
		cin >> name;
		for (auto comp : rezept[name]) {
			produkt[comp.first] -= comp.second;
		}
		cout << check(produkt, rezept) << "\n";
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
