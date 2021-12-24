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

const int INF = 1e9;
const ll ll_INF = 1e18;


vector<int> z_func(string s) {
	int n = s.size();
	vector<int> z(n, 0);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}


vector<int> pi(string s) {
	int n = s.size();
	vector<int> p(n, 0);
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		else{
			j = 0;
		}
		p[i] = j;
	}
	return p;
}


void solve() {
	string a, b, c;
	cin >> a >> b;
	c = b + "#" + a;
	vector<int> p = pi(c);
	vector<int> ans;
	for (int i = 0; i < p.size(); ++i) {
		if (p[i] == b.size()) {
			ans.push_back(i - b.size() * 2 + 1);
		}
	}
	cout << ans.size() << "\n";
	for (auto elem : ans) {
		cout << elem << " ";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int t;
	//	cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
