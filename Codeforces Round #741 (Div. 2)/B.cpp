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
	int k;
	cin >> k;
	string s;
	cin >> s;
	int flag = false;
	string t;
	vector<char> numbers = {'2', '3', '5',  '7',};
	map<char, int> mp;
	for(int i = 0; i < k; ++i){
		if (s[i] - '0' == 1 || s[i] - '0' % 2 == 0 || s[i] - '0' == 9){
			flag = true;
			t = s[i];
		}
		mp[s[i]]++;
	}
	if (flag){
		cout << "A1\n" << t << "\n";
	}
	else{
		for(auto elem: numbers){
			if (mp[elem] >= 2){
				flag = true;
				t = elem;
				t += elem;
			}
		}
		if (flag){
			cout << "A2\n" << t << "\n";
		}
		else{
			if (mp['2'] != 0 && s[0] != '2'){
				cout << "A2\n" << s[0] << "2\n";
			} 
			else if (mp['5'] != 0 && s[0] != '5'){
				cout << "A2\n" << s[0] << "5\n";
			}
			else{
				if (mp['2'] && mp['7']){
					cout << "A2\n27\n";
				}
			}
		}
	}
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
