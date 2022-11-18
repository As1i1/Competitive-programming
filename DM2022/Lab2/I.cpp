#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        string n_s;
        int step2 = 1;
        for (int i = 1; i < s.size() + 1;) {
            if (step2 == n_s.size() + 1) {
                n_s += "0";
                step2 *= 2;
            } else {
                n_s += s[i - 1];
                i++;
            }
        }
        step2 = 1;
        int k = 0;
        while (step2 < n_s.size()) {
            int res = 0;
            for (int j = 0; j < n_s.size(); j++) {
                int tmp = n_s[j] - '0';
                if (((j + 1) & (1 << k)) && j + 1 != step2) {
                    res = res ^ tmp;
                }
            }
            n_s[step2 - 1] = '0' + res;
            k++;
            step2 *= 2;

        }
        cout << n_s << endl;
    } else {
        set<int> s_e;
        int step2 = 1, k = 0, cnt = 0, ttt = 0;
        while (step2 < s.size()) {
            set<int> tmp;
            int res = 0;
            for (int j = 0; j < s.size(); j++) {
                int tp = s[j] - '0';
                if (((j + 1) & (1 << k)) && j + 1 != step2) {
                    res = res ^ tp;
                    tmp.insert(j);
                }
            }
            if (res != s[step2 - 1] - '0') {
                cnt++;
                ttt = step2 - 1;
                if (s_e.empty()) {
                    s_e = tmp;
                } else {
                    set<int> r;
                    for (auto c: s_e) {
                        if (tmp.find(c) != tmp.end()) r.insert(c);
                    }
                    s_e = r;
                }
            } else if (!s_e.empty()) {
                set<int> r;
                for (auto c: s_e) {
                    if (tmp.find(c) == tmp.end()) r.insert(c);
                }
                s_e = r;
            }
            step2 *= 2;
            k++;
        }
        if (cnt == 1){
            char t = s[ttt] - '0';
            s[ttt] = 1 - t + '0';
        } else if (cnt > 1) {
            int kk = *(s_e.begin());
            s[kk] = 1 - (s[kk] - '0') + '0';
        }
        string ns;
        step2 = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 == step2) {
                step2 *= 2;
            } else {
                ns += s[i];
            }
        }
        cout << ns << endl;
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
