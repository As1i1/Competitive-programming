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
	map<string, int> bank;
	while(n--){
		string s;
		cin >> s;
		if (s == "DEPOSIT"){
			string name;
			cin >> name;
			int x;
			cin >> x;
			bank[name] += x;
		}
		else if (s == "WITHDRAW"){
			string name;
			cin >> name;
			int x;
			cin >> x;
			bank[name] -= x;
		}
		else if (s == "BALANCE"){
			string name;
			cin >> name;
			if (bank.find(name) == bank.end()){
				cout << "ERROR\n";
			}
			else{
				cout << bank[name] << "\n";
			}
		}
		else if (s == "TRANSFER"){
			string name1, name2;
			cin >> name1 >> name2;
			int x;
			cin >> x;
			bank[name1] -= x;
			bank[name2] += x;
		}
		else{
			int p;
			cin >> p;
			for(auto par: bank){
				if (par.second > 0){
					bank[par.first] += (par.second * p / 100);
				}
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
	while(t--){
		solve();
	}
	return 0;
}
