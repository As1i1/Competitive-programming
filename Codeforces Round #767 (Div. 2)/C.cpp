//
// Created by AMD on 22.01.2022.
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
#include <bitset>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
const int MAXN = 1e5 + 5;


int find_mex(vector<bool> used) {
    int l = 0, r = MAXN + 1;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (used[m]) {
            l = m;
        }
        else {
            r = m;
        }
    }
    if (!used[l]) return l;
    return r;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    vector<set<int>> pos(MAXN);
    vector<bool> used(MAXN, false);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].insert(i);
    }
    if (pos[0].size() > 0) used[0] = true;
    for (int i = 1; i < MAXN; ++i) {
        if (pos[i].size() > 0 && used[i - 1]) {
            used[i] = true;
        }
        else {
            break;
        }
    }
    int last = -1;
    bool flag = true;
    while (flag) {
        int mex = find_mex(used);
        if (mex == 0) {
            flag = false;
        }
        else {
            int mx = 0;
            for (int i = 0; i < mex; ++i) {
                mx = max(*pos[i].begin(), mx);
            }
            used.assign(MAXN, false);
            for (int i = 0; i < mex; ++i) {
                while (!pos[i].empty() && *pos[i].begin() <= mx) {
                    pos[i].erase(pos[i].begin());
                }
                if (i == 0) {
                    if (pos[0].size() > 0) used[0] = true;
                }
                else if (pos[i].size() > 0 && used[i - 1]) used[i] = true;
            }
            last = mx;
            b.push_back(mex);
        }
    }
    cout << b.size() + n - last - 1 << "\n";
    for (auto elem : b) cout << elem << " ";
    for (int i = 0; i < n - last - 1; i++) cout << "0 ";
    cout << "\n";
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
