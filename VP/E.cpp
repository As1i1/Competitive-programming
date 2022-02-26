//
// Created by AMD on 06.02.2022.
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
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 gen;


void solve2(int n, int q) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> mp;
    sort(a.begin(), a.end());
    int cnt = 1, cur = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            mp.push_back({ cur, cnt });
            cur = a[i];
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    mp.push_back({ cur, cnt });
    while (q--) {
        int t;
        cin >> t;
        int ans = 0;
        if (t == 1) {
            vector<pair<int, int>> nw;
            for (auto p : mp) {
                nw.push_back({ p.first + 1, p.second });
                if (p.second % 2 == 1) {
                    ans ^= (p.first + 1);
                }
            }
            mp = nw;
        }
        else {
            int x; cin >> x;
            for (auto &p : mp) {
                if (p.first == x && p.second != 0) p.second--;
                if (p.second % 2 == 1) {
                    ans ^= (p.first + 1);
                }
            }
        }
        cout << ans << "\n";
    }
}



void solve() {
    int n, q;
    cin >> n >> q;
    if (n > 100 || q > 100) {
        solve2(n, q);
        return;
    }
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (q--) {
        int t;
        cin >> t;
        ll ans = 0;
        if (t == 1) {
            ans = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != -1) {
                    a[i]++;
                    ans ^= a[i];
                }
            }
        }
        else if (t == 2) {
            ans = 0;
            ll x; cin >> x;
            a.push_back(x);
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != -1) {
                    ans ^= a[i];
                }
            }
        }
        else {
            ans = 0;
            ll x; cin >> x;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] == x) {
                    a[i] = -1;
                    x = -1;
                }
                if (a[i] != -1) {
                    ans ^= a[i];
                }
            }
        }
        cout << ans << "\n";
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    //gen.seed(time(0));
    //cout << fixed;
    //cout.precision(15);
    int t = 1;
    //   cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}