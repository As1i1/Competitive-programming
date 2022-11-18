#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


int aloneP(vector<vector<pair<int, int>>> clos) {
    for (int i = 0; i < clos.size(); i++){
        int k = -1;
        int cnt = 0;
        for (int j = 0; j < clos[i].size(); j++) {
            if (clos[i][j].second == -1) {
                k = clos[i][j].first;
                cnt++;
            } else if (clos[i][j].second == 1) {
                cnt = 2;
            }
        }
        if (cnt == 1) {
            return k;
        }
    }
    return -1;
}

bool isZero(vector<vector<pair<int, int>>> clos) {
    for (int i = 0; i < clos.size(); i++){
        bool isZero = true;
        for (int j = 0; j < clos[i].size(); j++) {
            if (clos[i][j].second == 1 || clos[i][j].second == -1) {
                isZero = false;
                break;
            }
        }
        if (isZero) {
            return true;
        }
    }
    return false;
}


void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> clos(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 0) {
                clos[i].push_back({j + n, -1});
            } else if (x == 1) {
                clos[i].push_back({j, -1});
            }
        }
    }

    while (true) {
        if (isZero(clos)) {
            cout << "YES";
            return;
        }
        int x = aloneP(clos);
        int x_n;
        if (x == -1) {
            cout << "NO";
            return;
        }
        if (x < n) {
            x_n = x + n;
        } else {
            x_n = x - n;
        }
        for (int i = 0; i < clos.size(); ++i) {
            for (int j = 0; j < clos[i].size(); j++){
                if (clos[i][j].first == x) {
                    clos[i][j].second = 1;
                } else if (clos[i][j].first == x_n) {
                    clos[i][j].second = 0;
                }
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
    while(t--){
        solve();
    }
    return 0;
}
