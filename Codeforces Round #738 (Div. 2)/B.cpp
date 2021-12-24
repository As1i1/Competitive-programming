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
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s[0] == '?'){
		if (s.size() == 1) s[0] = 'B';
		else if (s[1] == 'B') s[0] = 'R';
		else s[0] = 'B';
	}
	for(int i = 1; i < n - 1; ++i){
		if (s[i] == '?'){
			if (s[i - 1] == s[i + 1] && s[i - 1] == 'R'){
				s[i] = 'B';
			}
			else if (s[i - 1] == s[i + 1]){
				s[i] = 'R';
			}
			else if (s[i + 1] == '?'){
				if (s[i - 1] == 'R'){
					s[i] = 'B';
				}
				else{
					s[i] = 'R';
				}
			}
			else{
				s[i] = s[i - 1];
			}
		} 
	}
	if (s[s.size() - 1] == '?'){
		if (s.size() == 1) s[s.size() - 1] = 'B';
		else if (s[s.size() - 2] == 'B') s[s.size() - 1] = 'R';
		else s[s.size() - 1] = 'B';
	}
	cout << s << "\n";
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
