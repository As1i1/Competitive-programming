#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<ll> hashs;


int find_dif(int i1) {
    if (a.size() == 1 && b.size() == 1) {
        if (a[0] == b[0]) return 1;
        return 0;
    }
}



void solve(){
    int n, q;
    cin >> n >> q;
    vector<string> a(n);
    hashs.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (q--) {

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
