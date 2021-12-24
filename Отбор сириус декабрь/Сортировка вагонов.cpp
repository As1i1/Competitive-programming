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
	stack<int> st;
	for(int i = 0; i < n; ++i) cin >> a[i];
	int cur = 1, k1 = 0;
	vector<pair<int, int>> ans;
	while(true){
		int cnt = 0;
		while ((st.empty() || st.top() != cur) && k1 < n){
			st.push(a[k1]);
			k1++;
			cnt++;
		}	
		if (cnt){
			ans.push_back({1, cnt});
		}
		if (!st.empty() && st.top() == cur){
			st.pop();
			cur++;
			ans.push_back({2, 1});
		}
		else if ((st.empty() && cnt == 0) || (st.top() != cur && cnt == 0)) break;
	}
	if (cur == n + 1){
		for(int i = 0; i < ans.size(); ++i){
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}
	else{
		cout << 0;
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
