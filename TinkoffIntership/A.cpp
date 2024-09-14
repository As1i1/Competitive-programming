//
// Created by aas1i1 on 4/15/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9, MOD = 1e9 + 7, Q = 38;
constexpr ld eps = 1e-9;
constexpr ll ll_INF = 1e18;
mt19937 gen;


void solve() {
    int n;
    cin >> n;
    vector<int> notes(n);
    for (int i = 0; i < n; ++i) {
        cin >> notes[i];
    }
    if (n < 7) {
        cout << "-1";
        return;
    }
    int counter_2 = 0;
    int counter_3 = 0;
    int counter_5 = 0;
    for (int i = 0; i < 7; ++i) {
        if (notes[i] == 2) {
            counter_2++;
        }
        if (notes[i] == 3) {
            counter_3++;
        }
        if (notes[i] == 5) {
            counter_5++;
        }
    }
    int max_5_count = (counter_3 == 0 && counter_2 == 0) ? counter_5 : -1;
    for (int i = 7; i < n; ++i) {
        if (notes[i] == 2) {
            counter_2++;
        }
        if (notes[i] == 3) {
            counter_3++;
        }
        if (notes[i] == 5) {
            counter_5++;
        }
        if (notes[i - 7] == 2) {
            counter_2--;
        }
        if (notes[i - 7] == 3) {
            counter_3--;
        }
        if (notes[i - 7] == 5) {
            counter_5--;
        }
        max_5_count = max((counter_3 == 0 && counter_2 == 0) ? counter_5 : -1, max_5_count);
    }

    cout << max_5_count;
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


