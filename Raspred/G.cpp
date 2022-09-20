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
    vector<string> words;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> field(n, vector<char>(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> field[i][j];
        }
    }
    for (int i = 0; i < n; ++i){
        string cur = "";
        for (int j = 0; j < m; ++j){
            if (field[i][j] == '.'){
                if (cur.size() > 1) words.push_back(cur);
                cur = "";
            }
            else{
                cur += field[i][j];
            }
        }
        if (cur.size() > 1) words.push_back(cur);
    }
    for (int j = 0; j < m; ++j){
        string cur = "";
        for (int i = 0; i < n; ++i){
            if (field[i][j] == '.'){
                if (cur.size() > 1) words.push_back(cur);
                cur = "";
            }
            else{
                cur += field[i][j];
            }
        }
        if (cur.size() > 1) words.push_back(cur);
    }
    sort(words.begin(), words.end());
    for (auto s: words){
        cout << s << " ";
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
