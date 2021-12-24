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
vector<set<int>> g;
vector<bool> used;
map<int, int> comp;
int c = 1;


void solve() {
	int n, k = 100*101, sm = 0;
	cin >> n;
	vector<int> m(n);
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
	for (int i = 0; i < n; ++i) {
		cin >> m[i];
		sm += m[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int cnt = 1; cnt <= n; ++cnt) {
			for (int w = 1; w < k; ++w) {
				if (w - m[i] < 0) {
					continue;
				}
				if (cnt == 1 && w - m[i] == 0 && dp[cnt][w] == -1) {
					dp[cnt][w] = i;
				}
				if (dp[cnt - 1][w - m[i]] != -1 && dp[cnt - 1][w - m[i]] != i && dp[cnt][w] == -1) {
					dp[cnt][w] = i;
				}
			}
		}
	}
	if (n % 2 == 1 || sm % 2 == 1 || dp[n / 2][sm / 2] == -1) cout << "No solution";
	else {
		vector<bool> ans(n, false);
		int t = n / 2, w = sm / 2;
		while (dp[t][w] != -1) {
			ans[dp[t][w]]= true;
			w -= m[dp[t][w]];
			t--;
		}
		for (int i = 0; i < n; ++i) if (!ans[i]) cout << i + 1 << " ";
		cout << "\n";
		for (int i = 0; i < n; ++i) if (ans[i]) cout << i + 1 << " ";
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
	while (t--) {
		solve();
	}
	return 0;
}
