//
// Created by Dima on 30.08.2022.
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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> field(n, vector<bool>(m, false));
    for(int i = 0; i < m; ++i){
        field[0][i] = true;
    }
    for(int i = 1; i < n; ++i){
        int a; cin >> a;
        for (int j = 0; j < a; ++j){
            field[i][j] = true;
        }
    }
    vector<pair<int, int>> ans;
    int x = 0, y = 0;
    while (x < n && y < m){
        if (field[x][y]){
            ans.push_back({x, y});
            x++;
            y++;
        }
        else{
            break;
        }
    }
    cout << ans.size() << "\n";
    for(auto p: ans){
        cout << p.first + 1 << " " << p.second + 1 << "\n";
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
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
