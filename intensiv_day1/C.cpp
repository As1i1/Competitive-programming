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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<pair<ll, int>> a(10), d(10), m(10);


pair<ll, vector<int>> zat(set<int> s) {
    vector<int> ans1;
    ll ans = 0;
    for (int i = 0; i < 10 && ans1.size() != 5; ++i) {
        if (s.find(d[i].second) == s.end()){
            ans += d[i].first;
            ans1.push_back(d[i].second);
        }
    }
    return { ans, ans1 };
}


pair<ll, vector<int>> pol(set<int> s) {
    pair<ll, vector<int>> ans = { -INF, {} };
    for (int i = 0; i < 10; ++i) {
        if (s.find(m[i].second) == s.end()) s.insert(m[i].second);
        else continue;
        for (int j = i + 1; j < 10; ++j) {
            if (s.find(m[j].second) == s.end()) s.insert(m[j].second);
            else continue;
            for (int k = j + 1; k < 10; ++k) {
                if (s.find(m[k].second) == s.end()) s.insert(m[k].second);
                else continue;
                pair<ll, vector<int>> tmp_ans = zat(s);
                if (tmp_ans.first + m[i].first + m[j].first + m[k].first > ans.first) {
                    ans.first = tmp_ans.first + m[i].first + m[j].first + m[k].first;
                    ans.second = tmp_ans.second;
                    ans.second.push_back(m[i].second);
                    ans.second.push_back(m[j].second);
                    ans.second.push_back(m[k].second);
                }
                s.erase(m[k].second);
            }
            s.erase(m[j].second);
        }
        s.erase(m[i].second);
    }
    return ans;
}



pair<ll, vector<int>> nap(set<int> s) {
    pair<ll, vector<int>> ans = { -INF, {} };
    int n = a.size();
    for (int i = 0; i < 10; ++i) {
        s.insert(a[i].second);
        for (int j = i + 1; j < 10; ++j) {
            s.insert(a[j].second);
            pair<ll, vector<int>> tmp_ans = pol(s);
            if (tmp_ans.first + a[i].first + a[j].first > ans.first) {
                ans.first = tmp_ans.first + a[i].first + a[j].first;
                ans.second = tmp_ans.second;
                ans.second.push_back(a[i].second);
                ans.second.push_back(a[j].second);
            }
            s.erase(a[j].second);
        }
        s.erase(a[i].second);
    }
    return ans;
}


void solve() {
    int n;
    cin >> n;
    vector<pair<ll, int>> a_tmp(n), b_tmp(n), c_tmp(n);
    for (int i = 0; i < n; ++i) {
        cin >> a_tmp[i].first >> b_tmp[i].first >> c_tmp[i].first;
        a_tmp[i].second = b_tmp[i].second = c_tmp[i].second = i + 1;
    }
    sort(a_tmp.rbegin(), a_tmp.rend());
    sort(b_tmp.rbegin(), b_tmp.rend());
    sort(c_tmp.rbegin(), c_tmp.rend());
    for (int i = 0; i < 10; ++i) {
        d[i] = a_tmp[i];
        m[i] = b_tmp[i];
        a[i] = c_tmp[i];
    }
    vector<int> ans = nap({}).second;
    cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << "\n";
    cout << ans[5] << " " << ans[6] << " " << ans[7] << "\n";
    cout << ans[8] << " " << ans[9];
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