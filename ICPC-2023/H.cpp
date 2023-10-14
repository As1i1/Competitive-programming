#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int q;
    cin >> q;
    map<string, int> mp;
    set<string> used;
    while (q--) {
        string s;
        cin >> s;
        string ans = s;
        if (used.find(ans) != used.end()) {
            int t = 1;
            if (mp.find(s) != mp.end()) {
                t = mp[s];
            }
            while (used.find(ans + to_string(t)) != used.end()) {
                t++;
            }
            mp[s] = t + 1;
            used.insert(ans + to_string(t));
            cout << ans + to_string(t) << "\n";
        } else {
            used.insert(ans);
            mp[ans] = 1;
            cout << ans << "\n";
        }
//        if (mp.find(s) == mp.end()) {
////            mp[s] = 1;
////            cout << s << "\n";
//        } else {
//            cout << s << mp[s] << "\n";
//            mp[s]++;
//        }
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
