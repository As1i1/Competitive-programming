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
    vector<int> gribochik_count(3);
    int n;
    cin >> n;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> gribochik_count_new(3);
        char s[3];
        cin >> s[0] >> s[1] >> s[2];
        for (int j = 0; j < 3; ++j) {
            int mx = -INF;
            for (int k = max(j - 1, 0); k <= min(j + 1, 2); k++) {
                mx = max(mx, gribochik_count[k]);
            }
            if (s[j] == '.') {
                gribochik_count_new[j] = mx;
            } else if (s[j] == 'C') {
                gribochik_count_new[j] = mx + 1;
            } else {
                gribochik_count_new[j] = -INF;
            }
        }
        gribochik_count = gribochik_count_new;
        answer = max(*max_element(gribochik_count.begin(), gribochik_count.end()), answer);
    }
    cout << answer;
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


