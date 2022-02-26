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
map<set<pair<int, int>>, bool> mp;


bool check(vector<vector<int>> b){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}


set<pair<int, int>> find_ans(vector<vector<int>> &pos, set<pair<int, int>> cur_ans, int cur_dist = 0){
    if (check(pos)) return cur_ans;
    if (cur_dist > 16) {
        mp[cur_ans] = false;
        return {};
    }
    if (mp.find(cur_ans) != mp.end() && !mp[cur_ans]){
        return {};
    }
    set<pair<int, int>> ans;
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (cur_ans.find({i, j}) != cur_ans.end()) continue;
            for (int k = 0; k < n; k++){
                pos[i][k] = 1 - pos[i][k];
                pos[k][j] = 1 - pos[k][j];
            }
            pos[i][j] = 1 - pos[i][j];
            cur_ans.insert({i, j});
            set<pair<int, int>> tmp = find_ans(pos, cur_ans, cur_dist + 1);
            cur_ans.erase({i, j});
            if (tmp.size() != 0 && (tmp.size() > ans.size() || ans.size() == 0)){
                ans = tmp;
                if (cur_dist == 0) return ans;
            }
            for (int k = 0; k < n; k++){
                pos[i][k] = 1 - pos[i][k];
                pos[k][j] = 1 - pos[k][j];
            }
            pos[i][j] = 1 - pos[i][j];
        }
    }
    return ans;
}



void solve(){
    cin >> n;
    a.resize(n, vector<int>(n, 0));
    vector<vector<int>> b(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    set<pair<int, int>> ans = find_ans(b, {}, 0);
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
