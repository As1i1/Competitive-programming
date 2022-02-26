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


bool check(int k, vector<int> )


void solve(){
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i){
        char c;
         cin >> c;
         if (c == 'a'){
             a[i] = 0;
         }
         else {
             a[i] = 1;
         }
    }
    int l = 0, r = n + 1;
    while (r - l > 1){
        int m = (r + l) / 2;

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
