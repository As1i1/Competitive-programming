#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<int> a;
int n;


bool check(int x, int k){
    int last = a[0];
    k--;
    for (int i = 1; i < n; ++i) {
        if (a[i] - last >= x) {
            k--;
            last = a[i];
        }
    }
    return k <= 0;
}


void solve(){
    int k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = INF;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (check(m, k)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l;
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
