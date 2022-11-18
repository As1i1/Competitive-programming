#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
int n;
vector<int> a;

bool check(int s, int k){
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += a[i] / s;
    }
    return cnt >= k;
}


void solve(){
    int k;
    cin >> n >> k;
    ll sum = 0;
    int mx = 0;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    if (k > sum) {
        cout << "0";
        return;
    }
    int L = 0, R = mx + 1;
    while (R - L > 1) {
        int M = (R + L) / 2;
        if (check(M, k)) {
            L = M;
        } else {
            R = M;
        }
    }
    if (check(L, k)) {
        cout << L;
    } else {
        cout << R;
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
