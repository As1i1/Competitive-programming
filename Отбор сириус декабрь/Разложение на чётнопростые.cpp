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
	int cnt2 = 0, i = 2, n, old_n;
	vector<int> nt;
	cin >> n;
	old_n = n;
	while (i * i <= n) {
		while (n % i == 0) {
			if (i == 2) {
				cnt2++;
			}
			else {
				nt.push_back(i);
			}
			n /= i;
		}
		i += 1;
	}
	if (n != 1) {
		if (n == 2) {
			cnt2++;
		}
		else {
			nt.push_back(n);
		}
	}
	if (cnt2 == 1) {
		cout << "prime";
	}
	else if (cnt2 >= 2) {
		if (nt.size() <= 1) {
			cout << "single\n";
			if (nt.size() == 1) {
				cout << 2 * (*nt.begin()) << " ";
				for (int i = 1; i < cnt2; ++i) {
					cout << 2 << " ";
				}
			}
			else {
				for (int i = 0; i < cnt2; ++i) {
					cout << 2 << " ";
				}
			}
		}
		else {
			cout << "many\n";
			cout << 2 * nt[0] * nt[1] << " ";
			int second = 2;
			for (int i = 2; i < nt.size(); ++i) {
				second *= nt[i];
			}
			cout << second << " ";
			for (int i = 2; i < cnt2; ++i) {
				cout << 2 << " ";
			}
			cout << "\n";
			cout << 2 * nt[0] << " " << second * nt[1] << " ";
			for (int i = 2; i < cnt2; ++i) {
				cout << 2 << " ";
			}
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
