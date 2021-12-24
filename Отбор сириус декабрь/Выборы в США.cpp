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


bool comp(pair<int, string> a, pair<int, string> b){
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}


void solve(){
	map<string, int> country;
	map<string, map<string, int>> conutry_name;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string name;
		cin >> name;
		int c;
		cin >> c;
		country[name] = c;
	}
	int m;
	cin >> m;
	map<string, int> ans;
	for(int i = 0; i < m; ++i){
		string coun, name;
		cin >> coun >> name;
		conutry_name[coun][name]++;
		ans[name] = 0;
	}
	for(auto elem: conutry_name){
		int mx = 0;
		string name;
		for(auto p: elem.second){
			if (p.second > mx){
				mx = p.second;
				name = p.first;
			}
			else if (p.second == mx){
				if (p.first < name){
					mx = p.second;
					name = p.first;
				}
			}
		}
		ans[name] += country[elem.first];
	}
	vector<pair<int, string>> tmp;
	for(auto elem: ans){
		tmp.push_back({elem.second, elem.first});
//	cout << elem.first << " " << elem.second << "\n";
	}
	sort(tmp.begin(), tmp.end(), comp);
	for(auto p: tmp){
		cout << p.first << " " << p.second << "\n";
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
