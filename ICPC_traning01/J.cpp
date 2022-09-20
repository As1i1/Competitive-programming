#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
ld ans = 0, cnt = 0;


void rec(vector<ld> &dr, int a, int b){
    if (a == 0 && b == 0){
        for (int i = 0; i < dr.size(); ++i) {
   //         cout << dr[i] << " ";
            ans += dr[i];
        }
 //       cout << endl;
        cnt++;
    }
    for (int i = 0; i <= a; ++i) {
        if (i == 0) continue;
        for (int k = 0; k < dr.size(); ++k){
            dr[k] += 2;
        }
        dr.push_back(14);
        rec(dr, a - i, b);
        dr.pop_back();
        for (int k = 0; k < dr.size(); ++k){
            dr[k] -= 2;
        }
    }
    for (int j = 0; j <= b; ++j) {
        if (j == 0) continue;
        for (int k = 0; k < dr.size(); ++k) {
            dr[k] *= 2;
        }
        dr.push_back(14);
        rec(dr, a, b - j);
        dr.pop_back();
        for (int k = 0; k < dr.size(); ++k) {
            dr[k] /= 2;
        }
    }
}


void solve(){
    int a, b;
    cin >> a >> b;
    vector<ld> c;
    rec(c, a, b);
    cout << ans << " " << cnt << " ";
    cout << ans / cnt;
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
//	cout << fixed;
	cout.precision(15);
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
