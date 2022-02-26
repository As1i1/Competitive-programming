//
// Created by AMD on 30.12.2021.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


bool eq(vector<int> a, vector<int> b) {
    return a[0] * b[1] == a[1] * b[0] && a[1] * b[2] == a[2] * b[1] && a[0] * b[2] == a[2] * b[0];
}


bool par(vector<int> a, vector<int> b) {
    return a[0] * b[1] == a[1] * b[0];
}


void solve() {
    int n;
    cin >> n;
    map<vector<int>, ll> lines;
    while (n--) {
        int t, a, b, c;
        cin >> t >> a >> b >> c;
        if (t == 1) {
            int q;
            cin >> q;
            if (lines.find({a, b, c}) != lines.end()){
                lines[{a, b, c}] += q;
            }
            else{
                lines[{a, b, c}] = q;
            }
        }
        else {
            vector<int> cur = { a, b, c };
            ll ans = 0;
            for (auto line : lines) {
                if (eq(line.first, cur)) {
                    if (line.second != 0){
                        ans = ll_INF;
                        break;
                    }
                }
                else if (!par(line.first, cur)) {
                    ans += line.second;
                }
            }
            if (ans == ll_INF) {
                cout << "inf\n";
            }
            else {
                cout << ans << "\n";
            }
        }
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
    while (t--) {
        solve();
    }
    return 0;
}
