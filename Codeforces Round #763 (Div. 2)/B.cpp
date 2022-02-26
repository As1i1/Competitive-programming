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


bool comp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3, 0));
    vector<vector<int>> ans(n, vector<int>(3, -1));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
        ans[i][0] = a[i][0];
        ans[i][1] = a[i][1];
    }
    if (n == 1) {
        cout << "1 1 1\n";
        return;
    }
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == a[i][1]) {
            ans[a[i][2]][2] = a[i][0];
            continue;
        }
        int k1 = a[i][0];
        for (int j = i + 1; j < n; ++j) {
            if (k1 != a[j][0]) {
                ans[a[i][2]][2] = k1;
            }
            else {
                k1 = a[j][1] + 1;
            }
        }
        if (ans[a[i][2]][2] == -1) {
            ans[a[i][2]][2] = a[i][1];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
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
    while (t--) {
        solve();
    }
    return 0;
}
