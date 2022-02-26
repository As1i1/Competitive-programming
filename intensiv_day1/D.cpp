//
// Created by AMD on 28.12.2021.  332018GTKED
//
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
vector<vector<int>> g;



ll hashs(string s) {
    ll ans = 0, p = 1;
    for (int i = 0; i < s.size(); ++i) {
        ans = (ans + (s[i] - 'a' + 1) * p) % MOD;
        p *= Q;
        p %= MOD;
    }
    return ans;
}



vector<ll> split(string s, char c) {
    string cur = "";
    vector<ll> ans;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            ans.push_back(hashs(cur));
            cur = "";
        }
        else {
            cur += s[i];
        }
    }
    if (cur.size() != 0) {
        ans.push_back(hashs(cur));
    }
    return ans;
}


void solve2(int n) {
    map<string, int> h_t;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        h_t[s]++;
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        cout << h_t[s] << "\n";
    }
}



void solve() {
    int n, p, m;
    cin >> n >> p;
    if (p == 2) {
        solve2(n);
        return;
    }
    else{
        cout << -1;
        return;
    }
    vector<pair<vector<ll>, vector<ll>>> iss(n);
    vector<pair<pair<string, bool>, pair<string, bool>>> f(n);
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        int deli = tmp.find('/');
        if (deli > tmp.size()) {
            if (tmp[0] == '*') {
                f[i].first = { tmp.substr(2), true };
            }
            else {
                f[i].first = { tmp, false };
            }
        }
        else {
            bool flag1 = false, flag2 = false, flag = false;
            string s1 = "", s2 = "";
            int k1 = 0, k2 = tmp.size();
            if (tmp[0] == '*') {
                k1 += 2;
                flag1 = true;
            }
            if (tmp.back() == '*') {
                k2 -= 2;
                flag2 = true;
            }
            while (k1 < k2) {
                if (tmp[k1] == '/' && !flag) {
                    flag = true;
                    k1++;
                    continue;
                }
                if (flag) {
                    s2 += tmp[k1];
                }
                else {
                    s1 += tmp[k1];
                }
                k1++;
            }
            f[i] = { {s1, flag1}, {s2, flag2} };
        }
        iss[i] = { split(f[i].first.first, '.'), split(f[i].second.first, '/' )};
        reverse(iss[i].first.begin(), iss[i].first.end());
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string tmp, s1 = "", s2 = "";
        cin >> tmp;
        int deli = tmp.find('/');
        if (deli > tmp.size()) {
            s1 = tmp;
        }
        else {
            int k1 = 0;
            bool flag = false;
            while (k1 < tmp.size()) {
                if (tmp[k1] == '/' && !flag) {
                    k1++;
                    flag = true;
                    continue;
                }
                if (flag) {
                    s2 += tmp[k1];
                }
                else {
                    s1 += tmp[k1];
                }
                k1++;
            }
        }
        int ans = 0;
        vector<ll> b1 = split(s1, '.'), b2 = split(s2, '/');
        reverse(b1.begin(), b1.end());
        for (int j = 0; j < n; ++j) {
            string t1 = f[j].first.first, t2 = f[j].second.first;
            vector<ll> a1 = iss[j].first, a2 = iss[j].second;
            bool l_ans = false, r_ans = false;
            if (t1.size() <= s1.size()) {
                if (t1 == s1) {
                    l_ans = true;
                }
                else if (f[j].first.second) {
                    int k1 = 0;
                    bool flag = true;
                    while (k1 < a1.size() && k1 < b1.size()) {
                        if (a1[k1] != b1[k1]) {
                            flag = false;
                            break;
                        }
                        k1++;
                    }
                    if (flag) l_ans = true;
                }
            }
            if (t2.size() <= s2.size()) {
                if (t2 == s2) {
                    r_ans = true;
                }
                else if (f[j].second.second) {
                    int k1 = 0;
                    bool flag = true;
                    while (k1 < a2.size() && k1 < b2.size()) {
                        if (a2[k1] != b2[k1]) {
                            flag = false;
                            break;
                        }
                        k1++;
                    }
                    if (flag) r_ans = true;
                }
            }
            if (l_ans & r_ans)ans++;
        }
        cout << ans << "\n";
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
    //      cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}