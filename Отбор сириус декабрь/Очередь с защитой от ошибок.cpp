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
	queue<int> st;
	while (true) {
		string s;
		cin >> s;
		if (s == "push") {
			int c;
			cin >> c;
			st.push(c);
			cout << "ok\n";
		}
		else if (s == "pop") {
			if (st.size() == 0) {
				cout << "error\n";
			}
			else {
				cout << st.front() << "\n";
				st.pop();
			}
		}
		else if (s == "front") {
			if (st.size() == 0) {
				cout << "error\n";
			}
			else {
				cout << st.front() << "\n";
			}
		}
		else if (s == "size") {
			cout << st.size() << "\n";
		}
		else if (s == "clear") {
			while (!st.empty()) {
				st.pop();
			}
			cout << "ok\n";
		}
		else if (s == "exit") {
			cout << "bye\n";
			break;
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
