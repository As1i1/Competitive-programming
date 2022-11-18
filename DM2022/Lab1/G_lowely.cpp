#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void print(vector<vector<int>> vector1) {
    for (int i = 0; i < vector1.size(); i++) {
        if (i != 0) {
            cout << "|";
        }
        for (int j = 0; j < vector1[0].size(); j++) {
            if (j != 0) {
                cout << "&";
            }
            if (vector1[i][j] == 0) {
                cout << "~";
            }
            cout << j + 1;
        }
    }
}

bool check(vector<bitset<33>> a, vector<vector<int>> sdnf, bitset<33> s) {
    bitset<33> res(0);
    for (int i = 0; i < sdnf.size(); i++) {
        bitset<33> tmp(0);
        tmp.flip();
        for (int j = 0; j < sdnf[i].size(); j++) {
            if (sdnf[i][j] == 0) {
                bitset<33> tmp2(a[j]);
                tmp &= tmp2.flip();
            } else {
                tmp &= a[j];
            }
        }
        res |= tmp;
    }
    return res == s;
}


void solve(){
    int n;
    cin >> n;
    vector<bitset<33>> a(n);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[i] = bitset<33>(x);
    }
    ll stmp;
    cin >> stmp;
    if (stmp == 0) {
        cout << "~1&1";
        return;
    }
    bitset<33> s(stmp);
    vector<vector<int>> sdnf;
    for (int i = 0; i < 33; i++) {
        if (s[i] == 1){
            vector<int> tmp(n);
            for (int j = 0; j < n; ++j) {
                tmp[j] = a[j][i];
            }
            sdnf.push_back(tmp);
        }
    }
    if (check(a, sdnf, s)) {
        print(sdnf);
    } else {
        cout << "Impossible";
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
