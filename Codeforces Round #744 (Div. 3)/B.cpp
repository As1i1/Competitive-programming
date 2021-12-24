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
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int last = a[0], ans = 0;
	vector<vector<int>> ans_t;
	for(int i = 1; i < n; ++i){
		if (a[i] > last){
			int l = 0, r = i + 1;
			for(int j = 0; j < i; ++j){
				if (a[j] > a[i]){
					 l = j + 1;
					 break;
				}
			}
			ans_t.push_back({l, r, r - l + 1});
			sort(a.begin() + l - 1, a.end() + r);
		}
		last = a[i];
	}
	cout << ans << "\n";
	for(int i = 0; i < ans; ++i){
		cout << ans_t[i][0] << " " << ans_t[i][1] << " " << ans_t[i][2] << " \n";
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
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
