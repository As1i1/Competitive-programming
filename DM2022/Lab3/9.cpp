//
// Created by Dima on 23.12.2022.
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
    int n;
    cin >> n;
    n *= 2;
    vector<string> ans;
    for (int i = 0; i < (1 << n); ++i){
        string s = "";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                s += "(";
            } else {
                s += ")";
            }
        }
        int b = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '('){
                b++;
            } else {
                b--;
            }
            if (b < 0) {
                goto m1;
            }
        }
        if (b == 0) ans.push_back(s);
        m1: s = "";
    }
    sort(ans.begin(), ans.end());
    for (string s: ans){
        cout << s << '\n';
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
