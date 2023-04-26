#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
int n, l;
vector<int> a;


bool check(double k) {
    bool flag = true;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum + k < a[i]) {
            flag = false;
            break;
        } else if (i == n - 1) {
            sum += k;
        } else {
            sum = min(sum + k, (double) a[i + 1]);
        }
    }
    return sum >= l && flag;
}


void solve(){
    cin >> n >> l;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1) {
        cout << n;
        return;
    }
    double L = 0, R = l + 1;
    for (int i = 0; i < 200; i++){
        double M = (L + R) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << (L + R) / 2;
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
//	gen.seed(time(0));
	cout << fixed;
    cout.precision( 10);
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
