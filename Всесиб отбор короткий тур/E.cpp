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
#define next cout << "\n"; cout.flush();

char check() {
	int cnt = 0, cnt_n = 0;
	for (int i = 0; i < 3; ++i) {
		char c1, c2;
		cin >> c1 >> c2;
		if (c1 == '>' && c2 == '>') {
			cnt++;
		}
		if (c1 == '=' && c2 == '=') {
			cnt_n++;
		}
		if ((c1 == '>' && c2 == '=') || (c1 == '=' && c2 == '>')) {
			cnt++;
		}
	}
	if (cnt > ((3 - cnt_n) / 2.)) {
		return 'W';
	}
	return 'L';
}



void solve() {
	vector<int> har = { 0, 0, 0, 0, 0, 0 };
	int k;
	for (int i = 0; i < 6; ++i) {
		cin >> har[i];
	}
	cin >> k;
	cout << "! ";
	for (int i = 0; i < 6; ++i) {
		cout << har[i] + k / 6 << " ";
	}
	next;
	char c = check();
	if (c == 'W') return;
	cout << "! ";
	for (int i = 0; i < 4; ++i) {
		cout << har[i] + k / 4 << " ";
	}
	cout << har[4] << " " << har[5];
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] << " " << har[1] << " ";
	for (int i = 2; i < 6; ++i) {
		cout << har[i] + k / 4 << " ";
	}
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] + k / 4 << " " << har[1] + k / 4 << " " << har[2] << " " << har[3] << " " << har[4] + k / 4 << " " << har[5] + k / 4;
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] + k / 3 << " " << har[1] + k / 3 << " " << har[2] + k / 3 << " " << har[3] << " " << har[4] << " " << har[5];
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] + k / 3 << " " << har[1] + k / 3 << " " << har[2] << " " << har[3] + k / 3 << " " << har[4] << " " << har[5];
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] + k / 3 << " " << har[1] + k / 3 << " " << har[2] << " " << har[3] << " " << har[4] + k / 3 << " " << har[5];
	next;
	c = check();
	if (c == 'w') return;
	cout << "! " << har[0] + k / 3 << " " << har[1] + k / 3 << " " << har[2] << " " << har[3] << " " << har[4]  << " " << har[5] + k / 3;
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] + k / 3 << " " << har[1]  << " " << har[2] << " " << har[3] << " " << har[4] + k / 3 << " " << har[5] + k / 3;
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] << " " << har[1] + k / 3 << " " << har[2] << " " << har[3] << " " << har[4] + k / 3 << " " << har[5] + k / 3;
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] << " " << har[1]  << " " << har[2] + k / 3  << " " << har[3] << " " << har[4] + k / 3 << " " << har[5] + k / 3;
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] << " " << har[1] << " " << har[2]  << " " << har[3] + k / 3 << " " << har[4] + k / 3 << " " << har[5] + k / 3;
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] << " " << har[1] << " " << har[2] + k / 3 << " " << har[3] + k / 3 << " " << har[4] + k / 3 << " " << har[5] ;
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] << " " << har[1] << " " << har[2] + k / 3 << " " << har[3] + k / 3 << " " << har[4]  << " " << har[5] + k / 3;
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] << " " << har[1] + k / 3 << " " << har[2] + k / 3 << " " << har[3] + k / 3 << " " << har[4] << " " << har[5];
	next;
	c = check();
	if (c == 'W') return;
	cout << "! " << har[0] + k / 3 << " " << har[1]  << " " << har[2] + k / 3 << " " << har[3] + k / 3 << " " << har[4] << " " << har[5];
	next;
	c = check();
	if (c == 'W') return;
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
