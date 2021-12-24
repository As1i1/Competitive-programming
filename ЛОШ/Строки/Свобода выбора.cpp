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

const int INF = 1e9, MOD = 1e9 + 7, Q = 38, MOD_2 = 1797979811;
const ll ll_INF = 1e18;


vector<int> pi(vector<int> a) {
	int n = a.size();
	vector<int> p(n, 0);
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && a[i] != a[j]) {
			j = p[j - 1];
		}
		if (a[i] == a[j]) {
			j++;
		}
		else {
			j = 0;
		}
		p[i] = j;
	}
	return p;
}


vector<int> h1, h2, p, obr_p, h1_2, h2_2;
int size_1, size_2;


ll bin_pow(ll base, ll p) {
	if (p == 1) {
		return base;
	}

	if (p % 2 == 0) {
		ll t = bin_pow(base, p / 2);
		return t * t % MOD;
	}
	else {
		return bin_pow(base, p - 1) * base % MOD;
	}
}

ll inverse_element(ll x) {
	return bin_pow(x, MOD - 2);
}


pair<int, int> check(int l) {
	set<int> s;
	for (int i = 0; i <= size_1 - l; ++i) {
		s.insert(((h1[l + i] - h1[i] + MOD) % MOD) * 1ll * obr_p[i] % MOD);
	}
	for (int i = 0; i <= size_2 - l; ++i) {
		int h = ((h2[l + i] - h2[i] + MOD) % MOD) * 1ll * obr_p[i] % MOD;
		if (s.find(h) != s.end()) {
			return { i, i + l };
		}
	}
	return { -1, -1 };
}


pair<int, int> check_2(int l) {
	set<int> s;
	for (int i = 0; i <= size_1 - l; ++i) {
		s.insert(((h1_2[l + i] - h1_2[i] + MOD_2) % MOD_2) * 1ll * obr_p[i] % MOD_2);
	}
	for (int i = 0; i <= size_2 - l; ++i) {
		int h = ((h2_2[l + i] - h2_2[i] + MOD_2) % MOD_2) * 1ll * obr_p[i] % MOD_2;
		if (s.find(h) != s.end()) {
			return { i, i + l };
		}
	}
	return { -1, -1 };
}


void solve() {
	int k;
	cin >> k;
	k--;
	k = 1;
	string s;
	p.assign(1e5 + 5, 0);
	obr_p.assign(1e5 + 5, 0);
	p[0] = 1;
	obr_p[0] = inverse_element(p[0]);
	for (int i = 1; i < 1e5 + 5; ++i) {
		p[i] = p[i - 1] * 1ll * Q % MOD;
		obr_p[i] = inverse_element(p[i]);
	}
	cin >> s;
	while (k--) {
		string t;
		cin >> t;
		size_1 = s.size();
		size_2 = t.size();
		h1.assign(size_1 + 1, 0);
		h2.assign(size_2 + 1, 0);
		h1_2.assign(size_1 + 1, 0);
		h2_2.assign(size_2 + 1, 0);
		for (int i = 0; i < size_1; ++i) {
			h1[i + 1] = (h1[i] + (s[i] - 'A' + 1) * 1ll * p[i] % MOD) % MOD;
			h1_2[i + 1] = (h1_2[i] + (s[i] - 'A' + 1) * 1ll * p[i] % MOD_2) % MOD_2;
		}
		for (int i = 0; i < size_2; ++i) {
			h2[i + 1] = (h2[i] + (t[i] - 'A' + 1) * 1ll * p[i] % MOD) % MOD;
			h2_2[i + 1] = (h2_2[i] + (s[i] - 'A' + 1) * 1ll * p[i] % MOD_2) % MOD_2;
		}
		int l = 0, r = size_1 + 1;
		pair<int, int> ans = { -1, -1 };
		while (r - l > 1) {
			int m = (r + l) / 2;
			pair<int, int> par = check(m), par_2 = check_2(m);
			if (par.first != -1 && par_2.first != -1) {
				l = m;
				ans = par;
			}
			else {
				r = m;
			}
		}
		if (ans.first == -1) {
			s = "";
			break;
		}
		s = "";
		for (int i = ans.first; i < ans.second; ++i) {
			s += t[i];
		}
	}
	cout << s;
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
