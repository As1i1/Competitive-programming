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
	int m, n;
	cin >> n >> m;
	vector<int> a(m), b(m);
	vector<bool> used(m, false);
	map<int, pair<int, int>> mp;
	for(int i = 0; i < m; ++i){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	mp[b[0]].first = 0;
	for(int i = 1; i < m; ++i){
		if (b[i] != b[i - 1]){
			mp[b[i - 1]].second = i;
			mp[b[i]].first = i;
		}
	}
	mp[b.back()].second = m;
	int ans = 0;
	for(int i = 0; i < m; ++i){
		int place = mp[a[i]].second;
		for(int i = 0; i < place; ++i){
			if (used[i]) ans++;
		}
		mp[a[i]].second--;
		used[place - 1] = true;
	}
	cout << ans << "\n";
}


signed main() {
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
