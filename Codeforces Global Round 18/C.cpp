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


void solve(){
    int n;
    string a, b;
    cin >> n >> a >> b;
    int cnt1_a = 0, cnt1_b = 0;
    for(int i = 0; i < n; ++i){
        if (a[i] == '1') {
            cnt1_a++;
        }
        if (b[i] == '1'){
            cnt1_b++;
        }
    }
    if (cnt1_b != cnt1_a && cnt1_b != n - cnt1_a + 1){
        cout << "-1\n";
        return;
    }
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    for(int i = 0; i < n; ++i){
        if (a[i] == '1' && b[i] == '1'){
            a4++;
        }
        else if (a[i] == '1' && b[i] == '0'){
            a3++;
        }
        else if (a[i] == '0' && b[i] == '1'){
            a2++;
        }
        else if (a[i] == '0' && b[i] == '0'){
            a1++;
        }
    }
    cout << min(a1 + a4, a2 + a3) <<"\n";
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
