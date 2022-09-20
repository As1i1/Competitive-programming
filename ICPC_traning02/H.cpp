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
    vector<int> a(n);
    bool ans_b = true;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (a[i] > i + 1){
            ans_b = false;
        }
    }
    if (!ans_b){
        cout << "NO";
        return;
    }
    vector<int> ans;
    while (!a.empty()){
        int tmp = 0;
        for (int i = 0; i < n; ++i){
            if (a[i] == i + 1){
                tmp = a[i];
            }
        }
        ans.push_back(tmp);
        a.erase();
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
