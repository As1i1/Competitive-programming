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
const int MAXN = 1e6 + 20;


map<int, int> dels(int n){
    int i = 2;
    map<int, int> ans;
    while(i * i <= n){
        while(n % i == 0){
            ans[i]++;
            n /= i;
        }
        i++;
    }
    if (n != 1){
        ans[n]++;
    }
    return ans;
}



void solve(){
    int n, k;
    cin >> n >> k;
    vector<map<int, int>> a(MAXN);
    multiset<int> s;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        a[x] = dels(x);
        s.insert(x);
    }
    bool flag = true;
    while(flag){
        int x = *s.rbegin();
        if (x == 1) break;
        s.erase(s.find(x));
        for (auto p: a[x]){
            if (p.second != 0){
                if (p.first > k){
                    flag = false;
                    break;
                }
                else{
                    a[x / p.first] = a[x];
                    x /= p.first;
                    k -= p.first;
                    a[x][p.first]--;
                    break;
                }
            }
        }
        s.insert(x);
    }
    cout << *s.rbegin();
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