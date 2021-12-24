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
#include <bitset>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<char> gens = { 'A', 'G', 'T', 'C' };


int optimal_find(int S) {
	string s = to_string(S);
	if (s[0] >= '2' || s.size() == 1) {
		return S / 2;
	}
	else {
		if (s[1] == '0') {
			return S / 2;
		}
		else {
			string s1 = "";
			s1 += s[0];
			for (int i = 1; i < s.size(); ++i) {
				s1 += "0";
			}
			return stoi(s1);
		}
	}
//	int L = 2, R = S / 2;
//	int ans = L;
//	for (int i = L; i <= R; i += 10) {
//		if (int(log10(i)) + int(log10(S - i)) > int(log10(ans)) + int(log10(S - ans))) {
//			ans = i;
//		}
//	}
//	return ans; 
}




pair<pair<int, int>, char> add_char(pair<int, char> cur_block) {
	int mx = 0, pos = 0;
	char c = cur_block.second;
	for (auto g : gens) {
		if (cur_block.first == 1) {
			if (cur_block.second == g && 1 > mx) {
				mx = 1;
				pos = 1;
				c = g;
			}
		}
		else {
			if (cur_block.second == g) {
				if (int(log10(cur_block.first)) != int(log10(cur_block.first + 1)) && 1 > mx) {
					mx = 1;
					pos = 0;
					c = g;
				}
			}
			else if (cur_block.second != g) {
				if (cur_block.first == 2) {
					if (1 > mx) {
						mx = 1;
						pos = 1;
						c = g;
					}
				}
				else if (cur_block.first == 3) {
					if (2 > mx) {
						mx = 2;
						pos = 2;
						c = g;
					}
				}
				else {
					int tmp = optimal_find(cur_block.first);
					if (int(log10(tmp)) + int(log10(cur_block.first - tmp)) + 2 - int(log10(cur_block.first)) > mx) {
						mx = int(log10(tmp)) + int(log10(cur_block.first - tmp)) + 2 - int(log10(cur_block.first));
						pos = tmp;
						c = g;
					}
				}
			}
		}
	}
	return { { mx, pos }, c };
}


pair<pair<int, int>, char> del_char(pair<int, char> cur_block, vector<pair<int, char>> near) {
	int mn = 0, pos = 1;
	char c = cur_block.second;
	if (cur_block.first == 1) {
		if (near[0].first == -1 || near[1].first == -1) {
			mn = -1;
			pos = 1;
		}
		else {
			if (near[0].second == near[1].second) {
				mn = int(log10(near[0].first + near[1].first)) - 2 - (int(log10(near[0].first)) + int(log10(near[1].first)));
				pos = 1;
			}
			else {
				mn = -1;
				pos = 1;
			}
		}
	}
	else {
		if (cur_block.first == 2 || (int(log10(cur_block.first - 1)) != int(log10(cur_block.first)))) {
			mn = -1;
			pos = 1;
		}
	}
	return { {mn, pos}, c };
}


void solve() {
	string short_s;
	int n, m = 0;
	cin >> short_s;
	n = short_s.size();
	vector<pair<int, char>> a;
	for (int i = 0; i < n; ++i) {
		string t = "";
		while (i < n && short_s[i] - '0' <= 9 && short_s[i] > 0) {
			t += short_s[i];
			i++;
		}
		if (t == "") {
			a.push_back({ 1, short_s[i] });
		}
		else {
			a.push_back({ stoi(t), short_s[i] });
		}
		m += a.back().first;
	}
	int mn = m + 1, mx = m - 1, cnt = 0;
	pair<int, char> ans_mn, ans_mx;
	for (int i = 0; i < a.size(); ++i) {
		pair<pair<int, int>, char> tmp = add_char(a[i]);
		if (tmp.first.first + m > mx) {
			ans_mx = { tmp.first.second + cnt, tmp.second };
			mx = tmp.first.first + m;
		}
		if (i == 0) {
			tmp = del_char(a[i], { {-1, ' '}, { -1, ' ' } });
		}
		else if (i == a.size() - 1) {
			tmp = del_char(a[i], { {-1, ' '}, { -1, ' ' } });
		}
		else {
			tmp = del_char(a[i], { a[i - 1], a[i + 1] });
		}
		if (tmp.first.first + m < mn) {
			mn = tmp.first.first + m;
			ans_mn = { tmp.first.second + cnt, tmp.second };
		}
		cnt += a[i].first;
	}
	cout << "2 " << ans_mn.first << "\n";
	cout << "1 " << ans_mx.first << " " << ans_mx.second;

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
