//
// Created by AMD on 25.12.2021.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;
vector<string> shablon = {"....G.R.G.R.G.B.R.R.G.B.G.B...",
                          "....B.G.R.G.B.R.G.R.B.B.B.G...",
                          "....R.B.G.G.B.B.B.G.R.B.G.R...",
                          "....G.R.B.R.G.B.R.R.G.R.B.R...",
                          "....B.G.R.G.B.G.B.R.B.R.R.G..."}, a;



bool check(int s_j, int e_j, int w_b, int w_e, int d){
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < 5; ++i){
        for (int j = s_j; j < e_j; ++j){
            if (j >= w_b && j <= w_e){
                if (a[i][j] != 'W') return false;
            }
            else if (shablon[i][j + d] == 'R' || shablon[i][j + d] == 'G' || shablon[i][j + d] == 'B'){
                if (a[i][j] != 'R' && a[i][j] != 'G' && a[i][j] != 'B') return false;
                if (a[i][j] != shablon[i][j + d]){
                    if (a[i][j] == 'R') cnt1++;
                    if (a[i][j] == 'G') cnt2++;
                    if (a[i][j] == 'B') cnt3++;
                }

            }
        }
    }
    if (s_j >= 5 || e_j <= 26) return cnt1 <= 7 && cnt2 <= 7 && cnt3 <= 7;
    return cnt1 <= 10 && cnt2 <= 10 && cnt3 <= 10;
}



void solve(){
    int n = 5, m = 30, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; ++i){
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    bool ans = false;
    ans |= check(0, 30, -1, -1, 0);
    for (int i = 0; i <= 10; ++i){
        ans |= check(0, 30 - i, -1, -1, i);
        ans |= check(i, 30, -1, -1, -i);
    }
    for (int k = -10; k < 30; ++k){
        ans |= check(0, 30, k, k + 9, 0);
        for (int i = 0; i <= 10; ++i){
            ans |= check(0, 30 - i, k, k + 9, i);
            ans |= check(i, 30, k, k + 9, -i);
        }
    }
    if (ans) cout << "YES";
    else{
        cout << "NO\n";
        for (int i = 0; i < n; ++i){
            cout << shablon[i] << "\n";
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
