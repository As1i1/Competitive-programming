//
// Created by AMD on 13.02.2022.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9, MOD = 1e9 + 7, Q = 38;
const ld eps = 1e-9;
const ll ll_INF = 1e18;
mt19937 gen;


void push(map<int, int> &sm, int start){
    while(sm[start] >= 10){
        sm[start + 1] += sm[start] / 10;
        sm[start] %= 10;
        start++;
    }
}


int pow(int a, int n){
    int p = 1;
    for (int i = 0; i < n; ++i){
        p *= a;
    }
    return p;
}



void solve(){
    int n;
    cin >> n;
    map<int, int> sm;
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
       while (a % 10 == 0){
            a /= 10;
            b++;
        }
        string s_a = to_string(a);
        reverse(s_a.begin(), s_a.end());
        for (int j = 0; j < s_a.size(); ++j){
            sm[b + j] += (s_a[j] - '0');
            push(sm, b + j);
        }
    }
    int ans = INT32_MAX;
    for (auto elem: sm){
        if (elem.second == 0) continue;
        ans = min(ans, elem.first);
    }
    cout << ans;
}


signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t = 1;
	gen.seed(time(0));
//	cout << fixed;
//	cout.precision(15);
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
