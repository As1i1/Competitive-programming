//
// Created by AMD on 28.12.2021.
//

//
// Created by AMD on 28.12.2021.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


bool check(int need, vector<int> a) {
    int n = a.size();
    vector<int> neg(n), pos(n);
    for (int i = n - 1; i >= 2; i--) {
        int x;
        if (pos[i] >= need) {
            x = a[i] / 3;
        }
        else {
            x = (a[i] - need + pos[i]) / 3;
        }
        if (x < 0) continue;
        neg[i] = x * 3;
        pos[i - 1] += x;
        pos[i - 2] += 2 * x;
    }
    for (int i = 0; i < n; ++i) {
        if (pos[i] + a[i] - neg[i] < need) return false;
    }
    return true;
}



void solve() {
    int n;
    ll sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int l = 0, r = sum / n + 100;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (check(m, a)) {
            l = m;
        }
        else {
            r = m;
        }
    }
//    for (int i = r + 5; i >= max(0, l - 5); --i) {
//        if (check(i, a)) {
//            cout << i << "\n";
//            return;
//        }
//   }
    if (check(r, a)) cout << r << "\n";
    else cout << l << "\n";
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
    while (t--) {
        solve();
    }
    return 0;
}
