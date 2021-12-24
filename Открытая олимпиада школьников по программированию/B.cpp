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


void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	map<int, int> field;
	while (n--) {
		char c;
		int i;
		cin >> c >> i;
		if (c == '+') {
			if (field[i] == 0) {
				field[i]++;
			}
			else {
				int cnt_l = 1, cnt_r = 1, i_l = i - 1, i_r = i + 1;
				while (field[i_l] == 1) {
					cnt_l++;
					i_l--;
				}
				while (field[i_r] == 1) {
					cnt_r++;
					i_r++;
				}
				int j = i_l;
				for (; cnt_r != 0; ++j, cnt_r--) {
					field[j] = 1;
				}
				field[j] = 0;
				j++;
				for (; cnt_l != 0; j++, cnt_l--) {
					field[j] = 1;
				}
			}
		}
		else {
			cout << field[i] << "\n";
		}
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
