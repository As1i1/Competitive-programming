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



string solve1(int n, int k, vector<vector<int>> ttt) {
    vector<vector<int>> f;
    f.resize(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            f[i].push_back(ttt[i][j]);
        }
    }
    for (int i = 0; i < k; ++i) {
        int cnt = 0;
        int ii = -1;
        for (int j = 0; j < n; ++j) {
            if (f[i][j] != -1) {
                cnt++;
                ii = j;
            }
        }
        if (cnt == 1) {
            int x = f[i][ii];
            f[i][ii] = -1;
            for (int j = 0; j < k; ++j) {
                int cnt2 = 0;
                for (int t = 0; t < n; ++t) {
                    if (f[j][t] != -1) {
                        cnt2++;
                    }
                }
                if (cnt2 == 1 && f[j][ii] != -1) {
                    if (x != f[j][ii]) {
                        return "YES";
                    }
                }
                if (x == f[j][ii]) {
                    for (int t = 0; t < n; ++t) {
                        f[j][t] = -1;
                    }
                }
                f[j][ii] = -1;
            }
            i = -1;
        }
    }
    return "NO";
}


string solve2(int n, int k, vector<vector<int>> ttt){
//    int n, k;
//    cin >> n >> k;
    vector<vector<pair<int, int>>> clos(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; j++) {
//            int x;
//            cin >> x;
            if (ttt[i][j] == 0) {
                clos[i].push_back({j + n, -1});
            } else if (ttt[i][j] == 1) {
                clos[i].push_back({j, -1});
            }
        }
    }

    while (true) {
        if (isZero(clos)) {
            return "YES";
        }
        int x = aloneP(clos);
        int x_n;
        if (x == -1) {
            return "NO";
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
    cin >> t;
    while(t--){
        int n = gen() % 3 + 3, k = gen() % 3 + 3;
        vector<vector<int>> f(k, vector<int> (n, -1));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; j++){
                if (gen() % 2) {
                    f[i][j] = 0;
                }
            }
            int y = gen() % n;
            f[i][y] = 1;
        }
        string s1 = solve1(n, k, f), s2 = solve2(n, k, f);
        if (s1 != s2) {
            cout << s1 << "\n" << s2 << "\n";
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << f[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
