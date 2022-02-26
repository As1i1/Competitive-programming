//
// Created by AMD on 08.01.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> points(2 * n);
    vector<pair<int, int>> otr;
    for (int i = 0; i < 2 * n; ++i){
        cin >> points[i];
    }
    int k1 = 0;
    for (int i = 0; i < 2 * n; i += 2){
        k1 += points[i + 1] - points[i];
    }
    if (k1 > k){
        cout << "No";
        return;
    }
    k -= k1;
    for (int i = 1; i < 2 * n - 1; i += 2){
        otr.push_back({i, points[i + 1] - points[i]});
    }
    vector<int> dp(k + 1, INF);
    int m = otr.size();
    dp[0] = -1;
    for (int i = 0; i < m; ++i){
        for (int j = k; j >= 0; j--){
            if (otr[i].second + j <= k && dp[j] != INF && dp[otr[i].second + j] == INF){
                dp[j + otr[i].second] = i;
            }
        }
    }
    if (dp[k] == INF){
        cout << "No";
        return;
    }
    vector<bool> used(m, false);
    int cur = dp[k];
    while(cur != -1){
        used[cur] = true;
        int x = otr[cur].second;
        cur = dp[k - x];
        k -= x;
    }
    cout << "Yes\n";
    vector<pair<int, int>> ans;
    int first = 0;
    for (int i = 0; i < m; i++){
        if (!used[i]){
            ans.push_back({first, otr[i].first});
            first = otr[i].first + 1;
        }
    }
    ans.push_back({first, 2 * n - 1});
    for (auto p: ans){
        cout << p.first + 1 << " " << p.second + 1 << "\n";
        for (int i = p.first + 1; i < p.second; i += 2){
            cout << i + 1 << " " << i + 2 << "\n";
        }
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
  //  cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
