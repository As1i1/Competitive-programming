//
// Created by AMD on 24.02.2022.
//

//
// Created by AMD on 07.02.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<vector<int>> a;
int n;


bool check(vector<vector<int>> b){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}


void solve(){
    cin >> n;
    vector<pair<int, int>> b;
    a.resize(n, vector<int>(n, 1));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            b.push_back({i, j});
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }
    vector<pair<int, int>> ans;
    for (ll i = 1; i < (1ll << b.size()); ++i){
        vector<pair<int, int>> op;
        vector<vector<int>> tmp(n, vector<int>(n, 0));
        for (int j = 0; j < b.size(); ++j){
            if (i & (1 << j)) {
                int r = b[j].first, c = b[j].second;
                for (int k = 0; k < n; ++k) {
                    tmp[r][k] = 1 - tmp[r][k];
                    tmp[k][c] = 1 - tmp[k][c];
                }
                tmp[r][c] = 1 - tmp[r][c];
            }
            else{
                op.push_back(b[j]);
            }
        }
        if (check(tmp)){
            if (ans.size() == 0 || ans.size() > op.size()){
                ans = op;
                cout << ans.size() << "\n";
                for (auto elem: ans){
                    cout << elem.first << " " << elem.second << "\n";
                }
                return;
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto elem: ans){
        cout << elem.first << " " << elem.second << "\n";
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
