#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> alle_staat, dumm_staat;
    for(int i = 0; i < n; ++i){
        int t; cin >> t;
        alle_staat.push_back({a[i], i});
        if (t == 0) {
            dumm_staat.push_back({a[i], i});
        }
    }

    sort(alle_staat.begin(), alle_staat.end(), comp);
    sort(dumm_staat.begin(), dumm_staat.end(), comp);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> mn1(n), mn2(dumm_staat.size());
    mn1[0] = alle_staat[0].second;
    if (dumm_staat.size() != 0) mn2[0] = dumm_staat[0].second;
    for (int i = 1; i < n; ++i) {
        mn1[i] = min(mn1[i - 1], alle_staat[i].second);
    }
    for (int i = 1; i < dumm_staat.size(); ++i) {
        mn2[i] = min(mn2[i - 1], dumm_staat[i].second);
    }

    int q;
    cin >> q;
    vector<vector<int>> mitschuler(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        cin >> mitschuler[i][0];
    }
    for (int i = 0; i < q; ++i) {
        cin >> mitschuler[i][1];
    }
    for (int i = 0; i < q; ++i) {
        cin >> mitschuler[i][2];
    }

    for (int i = 0; i < q; ++i){
        int ans;
        if (mitschuler[i][1] == 1) {
            int l = -1, r = n;
            while (r - l > 1) {
                int m = (r + l) / 2;
                if (alle_staat[m].first <= mitschuler[i][0]){
                    l = m;
                } else {
                    r = m;
                }
            }
            if (l == -1) {
                ans = INF;
            } else {
                ans = mn1[l];
            }
        } else {
            int l = -1, r = dumm_staat.size();
            while (r - l > 1) {
                int m = (r + l) / 2;
                if (dumm_staat[m].first <= mitschuler[i][0]){
                    l = m;
                } else {
                    r = m;
                }
            }
            if (l == -1) {
                ans = INF;
            } else {
                ans = mn2[l];
            }
        }

        if (mitschuler[i][2] != 0 && a[mitschuler[i][2] - 1] == 1){
            ans = min(ans, mitschuler[i][2] - 1);
        }

        if (ans == INF) {
            cout << "0 ";
        } else {
            cout << ans + 1 << " ";
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
    while(t--){
        solve();
    }
    return 0;
}
