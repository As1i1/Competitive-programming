//
// Created by AMD on 31.01.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


bool check(int d, int m, int y){
    string a1 = to_string(d), a2 = to_string(m), a3 = to_string(y);
    if (a1.size() == 1) a1 = "0" + a1;
    if (a2.size() == 1) a2 = "0" + a2;
    string a = a1 + a2 + a3, a_r = a;
    reverse(a_r.begin(), a_r.end());
    return a == a_r;
}



void solve(){
    int n; cin >> n;
    int d = 1, m = 1, y = 1, ans = 0;
    vector<int> p = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 0; i < n; ++i){
        if (check(d, m, y)){
            ans++;
        }
        d++;
        if (y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0) && p[2] == 28){
            p[2]++;
        }
        if (y % 4 != 0 && p[2] == 29){
            p[2]--;
        }
        if (d == p[m] + 1 && m == 12){
            d = 1;
            m = 1;
            y++;
        }
        else if (d == p[m] + 1){
            d = 1;
            m++;
        }
    }
    cout << ans;
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
