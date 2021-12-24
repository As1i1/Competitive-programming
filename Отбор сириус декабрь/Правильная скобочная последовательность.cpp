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


void solve(){
	stack<char> st;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i){
		if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
			st.push(s[i]);
		}
		else {
			if (st.empty()){
				cout << "no";
				return;
			}
			else if ((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}')){
				st.pop();
			}
			else{
				cout << "no";
				return;
			}
		}
	}
	if(st.empty()) cout << "yes";
	else cout << "no";
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
