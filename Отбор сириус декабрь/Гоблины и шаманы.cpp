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
deque<int> q1, q2;


void perehod(){
	while ((q1.size() + q2.size() + 1) / 2 != q1.size()){
		int x = q2.front();
		q2.pop_front();
		q1.push_back(x);
	}
}


void solve(){
	int n;
	cin >> n;
	while(n--){
		char c;
		cin >> c;
		if (c == '+'){
			int x;
			cin >> x;
			q2.push_back(x);
			perehod();
		}
		else if (c == '-'){
			cout << q1.front() << "\n";
			q1.pop_front();
			perehod();
		}
		else if (c == '*'){
			int x;
			cin >> x;
			q2.push_front(x);
			perehod();
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
	while(t--){
		solve();
	}
	return 0;
}
