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
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve() {
	deque <int> st;
	while (true) {
		string s;
		cin >> s;
		if (s == "push_front"){
			int x;
			cin >> x;
			st.push_front(x);
			cout << "ok\n";
		}
		else if (s == "push_back"){
			int x;
			cin >> x;
			st.push_back(x);
			cout << "ok\n";
		}
		else if (s == "pop_front"){
			if (st.empty()) cout << "error\n";
			else {
				cout << st.front() << "\n";
				st.pop_front();
			}
		}
		else if (s == "pop_back"){
			if (st.empty()) cout << "error\n";
			else {
				cout << st.back() << "\n";
				st.pop_back();
			}
		}
		else if (s == "front"){
			if (st.empty()) cout << "error\n";
			else {
				cout << st.front() << "\n";
			}
		}
		else if (s == "back"){
			if (st.empty()) cout << "error\n";
			else {
				cout << st.back() << "\n";
			}
		}
		else if (s == "size") {
			cout << st.size() << "\n";
		}
		else if (s == "clear") {
			while (!st.empty()) {
				st.pop_front();
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
