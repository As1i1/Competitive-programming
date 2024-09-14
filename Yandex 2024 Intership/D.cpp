//
// Created by aas1i1 on 3/2/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


int find_next(int s, vector<char>& v) {
    for (int i = s; i < v.size(); ++i) {
        if (v[i] != 'F') {
            return i - s;
        }
    }
    return v.size() - s;
}


void solve() {
    int n;
    cin >> n;
    vector<char> actions(n);
    vector<pair<int, int>> dp(n + 1);
    dp[0] = {0, 1};
    for (int i = 0; i < n; ++i){
        cin >> actions[i];
        if (actions[i] == 'F') {
            dp[i + 1] = {dp[i].first + dp[i].second, dp[i].second};
        } else if (actions[i] == 'L') {
            dp[i + 1] = {dp[i].first, -1};
        } else {
            dp[i + 1] = {dp[i].first, 1};
        }
    }
    set<int> ans;
    int next = 0;
    for (int i = 0; i < n; ++i) {
        if (next == 0) {
            next = find_next(i + 1, actions);
        } else {
            next--;
        }
        if (actions[i] == 'F') {
            ans.insert(dp[n].first - dp[i].second); // N F -> N N
            ans.insert(dp[n].first + 2 * next * (-dp[i].second) - dp[i].second); // N F -> N !N
        } else if (actions[i] == 'L') {
            if (dp[i].second == -1) {
                ans.insert(dp[n].first - 1); // L L -> L F
                ans.insert(dp[n].first + 2 * next); // L L -> L R
            } else {
                ans.insert(dp[n].first + 2 * next + 1); // R L -> R F
                ans.insert(dp[n].first + 2 * next); // R L -> R R
            }
        } else {
            if (dp[i].second == 1) {
                ans.insert(dp[n].first + 1); // R R -> R F;
                ans.insert(dp[n].first - 2 * next); // R R -> R L
            } else {
                ans.insert(dp[n].first - 2 * next - 1); // L R -> L F
                ans.insert(dp[n].first - 2 * next); // L R -> L L
            }
        }
    }
    cout << ans.size() << "\n";
//    for (auto c: ans) {
//        cout << c << " ";
//    }
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

