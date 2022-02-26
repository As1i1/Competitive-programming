//
// Created by AMD on 06.02.2022.
//

//
// Created by AMD on 06.02.2022.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <ctime>
#include <bitset>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 gen;


void solve(){
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i){
        int cur_ans = -1, ind = -1;
        for (int j = 0; j < n; ++j){
            if (i == j) continue;
            int tmp_ans = 0;
            for (int k = 0; k < n; ++k){
                if (a[i][k] != a[j][k]){
                    tmp_ans = k;
                    break;
                }
            }
            for (int k1 = a[i].size() - 1, k2 = a[j].size() - 1; min(k1, k2) >= tmp_ans; k1--, k2--){
                if (a[i][k1] != a[j][k2]){
                    tmp_ans += a[i].size() - k1 + 1;
                    break;
                }
            }
            if (tmp_ans > cur_ans){
                tmp_ans = cur_ans;
                ind = j;
            }
        }
        ans[i] = ind + 1;
    }
    for (int i = 0; i < n; ++i){
        cout << ans[i] << " ";
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    //gen.seed(time(0));
    //cout << fixed;
    //cout.precision(15);
    int t = 1;
    //   cin >> t;
    while(t--){
        solve();
    }
    return 0;
}