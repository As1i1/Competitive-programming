
//
// Created by AMD on 26.12.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 998244353, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
//mt19937 gen;
int n;
const int MAXN = int(1 << 21) + 10;
vector<vector<int>> g;
//vector<vector<int>> dp;
int dp[22][MAXN];
vector<int> step_2;


int dfs(int i, int mask) {
    if (mask == 1) {
        dp[i][mask] = g[i][0];
        return dp[i][mask];
    }
    if (dp[i][mask] != INF) {
        return dp[i][mask];
    }
    for (int j = 1; j <= n; ++j){
        if (g[i][j] != INF && (mask & step_2[j])) {
            dp[i][mask] = min(dp[i][mask], dfs(j, mask - step_2[j]) + g[i][j]);
        }
    }
    return dp[i][mask];
}



void solve() {
    for (int i = 0; i < MAXN; ++i){
        for (int j = 0; j < 22; ++j){
            dp[j][i] = INF;
        }
    }
    cin >> n;
    step_2.resize(25);
    step_2[0] = 1;
    for (int i = 1; i < 25; ++i) step_2[i] = step_2[i - 1] * 2;
    g.resize(n + 1, vector<int>(n + 1, INF));
//    dp.resize(n + 1, vector<int>((1 << (n + 1)), INF));
    vector<vector<string>> mp(n + 1, vector<string>(n + 1, ""));
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; x--;
        a[i] = { i, x };
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
  //          if (abs(a[i].first - a[j].first) > 1 && abs(a[i].second - a[j].second) > 1) continue;
            string s = "";
            if (a[i].first < a[j].first) {
                string t(a[j].first - a[i].first, 'R');
                s += t;
            }
            else {
                string t(a[i].first - a[j].first, 'L');
                s += t;
            }

            if (a[i].second < a[j].second) {
                string t(a[j].second - a[i].second, 'r');
                s += t;
            }
            else {
                string t(a[i].second - a[j].second, 'l');
                s += t;
            }
            g[i + 1][j + 1] = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
            mp[i + 1][j + 1] = s;
        }
    }
    for (int i = 1; i <= n; ++i) {
        string t1(a[i - 1].first, 'R'), t2(a[i - 1].second, 'r');
        mp[0][i] = t1 + t2;
        g[0][i] = a[i - 1].first + a[i - 1].second;
        g[i][0] = 0;
    }
    dp[0][0] = 0;
    int ans = dfs(0, step_2[n + 1] - 1);
    int i = 0;
    int mask = step_2[n + 1] - 1;
    vector<int> way = {0};
    while (mask != 0) {
        for (int j = 0; j <= n; ++j) {
            if (g[i][j] != INF && (mask & step_2[j]) && dp[i][mask] == dp[j][mask - step_2[j]] + g[i][j]) {
                way.push_back(j);
                i = j;
                mask -= (1 << j);
                break;
            }
        }
    }
    string s_ans = "";
    for (int i = 0; i < n; ++i) {
        s_ans += mp[way[i]][way[i + 1]];
    }
    cout << s_ans;
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
    //	gen.seed(time(0));
    //	cout << fixed;
    //	cout.precision(15);
    //  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}