//
// Created by AMD on 24.12.2021.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<vector<int>> pref(2e5 + 1, vector<int>(20, 0));


void solve(){
    int l, r;
    cin >> l >> r;
    l--;
    int n = r - l;
    vector<int> cnt(20, n);
    int ans = n - 1;
    for(int i = 0; i < 20; ++i){
        cnt[i] = pref[r][i] - pref[l][i];
        ans = min(ans, n - cnt[i]);
    }
    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    for(int i = 1; i <= 2e5; ++i){
        for(int j = 0; j < 20; ++j){
            pref[i][j] = pref[i - 1][j];
            if (i & (1 << j)){
                pref[i][j]++;
            }
        }
    }
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}