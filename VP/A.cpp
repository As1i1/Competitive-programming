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
    ll n, ans = 0;
    cin >> n;
    for (int i = 0; i * 50 <= n; i++){
        for (int j = 0; j * 100 <= (n - i * 50); j++){
            if ((n - i * 50 - j * 100) % 200 == 0){
                ans++;
            }
        }
    }
    cout << ans;
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