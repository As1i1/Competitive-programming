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
map<char, set<int>> answer;
vector<char> numbers = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


void solve() {
	int n, k;
	cin >> n >> k;
	string s = to_string(n);
	int ans = INF;
	if (k == 2) {
		if (s == "1000000000") {
			cout << "1000000000\n";
			return;
		}
		int i = -1;
		for (int kk = 0; kk < 10; ++kk) {
			if (numbers[kk] == s[0]) i = kk;
		}		
		ans = *answer[numbers[i]].upper_bound(n - 1);
	}
	else {
		if (s == "1000000000") {
			cout << "1111111111\n";
			return;
		}
		for (int i = 0; i < 10; ++i) {
			string tmp = "";
			for (int j = 0; j < s.size(); ++j) {
				tmp += numbers[i];
			}
			int tmp_ans = stoi(tmp);
			if (tmp_ans >= n) ans = min(ans, tmp_ans);
		}
	}
	cout << ans << "\n";
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int z = 0; z < pow(2, 9); ++z) {
				string tmp = "";
				for (int y = 0; y < 9; ++y) {
					if (z & (1 << y)) {
						tmp += numbers[i];
					}
					else {
						tmp += numbers[j];
					}
					int tmp_ans = stoi(tmp);
					answer[tmp[0]].insert(tmp_ans);
				}
			}
		}
	}
	//	gen.seed(time(0));
	//	cout << fixed;
	//	cout.precision(15);
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
