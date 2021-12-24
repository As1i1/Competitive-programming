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
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ll ll_INF = 1e18;


bool comp(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}


void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), comp);
	int last = a[0].second;
	for(int i = 1; i < n; ++i){
		if (a[i].second < last){
			last = a[i].first;
		}
		else{
			last = a[i].second;
		}
	}
	cout << last;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
//	cin >> t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}
