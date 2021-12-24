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


bool is_prime(int number) {
	int i = 2; 
	while (i * i <= number) {
		if (number % i == 0) return false;
		i++;
	}
	return true;
}


void solve() {
	int n;
	string s;
	cin >> s;
	n = s.size();
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') {
			flag = false;
			break;
		}
	}
	if (flag) {
		if (!is_prime(stoi(s))) {
			cout << stoi(s);
		}
		else {
			cout << -1;
		}
	}
	else {
		if (s.back() == '*') {
			s[s.size() - 1] = '2';
			for (int i = 0; i < n - 1; ++i) {
				if (s[i] == '*') {
					s[i] = '1';
				}
			}
		}
		else {
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				if (s[i] != '*') {
					sum += s[i] - '0';
				}
			}
			for (int i = 0; i < n; ++i) {
				if (s[i] == '*') {
					if (sum % 3 == 0) {
						s[i] = '3';
						sum += 3;
					}
					else if (sum % 3 == 1) {
						s[i] = '2';
						sum += 2;
					}
					else if (sum % 3 == 2) {
						s[i] = '1';
						sum += 1;
					}
				}
			}
		}
		cout << s;
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
