//
// Created by aas1i1 on 3/2/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;

int find_index(int start, vector<string>& v, string& s) {
    for (int i = start; i < v.size(); ++i) {
        if (v[i].starts_with(s))
            return i;
    }
    return v.size();
}


void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    vector<tuple<string, int, int>> se(q);
    for (int i = 0; i < q; ++i) {
        cin >> get<1>(se[i]) >> get<0>(se[i]);
        get<2>(se[i]) = i;
    }
    sort(se.begin(), se.end(), [](tuple<string, int, int> a, tuple<string, int, int> b) {
        return get<0>(a) < get<0>(b);
    });
    vector<int> ans(q);
    int last = 0;
    for (int i = 0; i < q; ++i) {
        int pos = find_index(last, words, get<0>(se[i]));
        int k = get<1>(se[i]);
        if (pos + k > n || !words[pos + k - 1].starts_with(get<0>(se[i]))) {
            ans[get<2>(se[i])] = -1;
        } else {
            ans[get<2>(se[i])] = pos + k;
        }
        last = pos == words.size() ? last : pos;
    }
    for (auto c: ans) {
        cout << c << "\n";
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


